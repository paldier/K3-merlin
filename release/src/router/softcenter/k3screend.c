/*
* 作者：杨志永
* 日期：2012-04-17 10:10 
* Email:ljy520zhiyong@163.com
* 修改：paldier
*/
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
 
#define BUFFER 1024
#define SECOND 1
int get_net_work_download_speed(int * download_speed, int * upload_speed, char * download_type, char * upload_type);

void get_time()
{
	time_t tmpcal_ptr;
	FILE *fptime, *fpdate;
	struct tm *tmp_ptr = NULL;
	time(&tmpcal_ptr);
	tmp_ptr = localtime(&tmpcal_ptr);
	if (fptime = fopen("/tmp/k3screenctrl/time", "w")){
		fprintf(fptime, "%02d:%02d\n", tmp_ptr->tm_hour, tmp_ptr->tm_min);
		fclose(fptime);
	}
	if (fpdate = fopen("/tmp/k3screenctrl/date", "w")){
		fprintf(fpdate, "%d-%d-%d\n", (1900+tmp_ptr->tm_year), (1+tmp_ptr->tm_mon), tmp_ptr->tm_mday);
		fclose(fpdate);
	}
}

int main(int argc, char * argv[])
{
	int start_download_speed;
	int end_download_speed;
	int start_upload_speed;
	int end_upload_speed;
	int result_of_download;
	int result_of_upload;
	FILE *fpup, *fpdo;

	while (1)
	{
		get_net_work_download_speed(&start_download_speed, &start_upload_speed, "RX bytes:", "TX bytes:");
		sleep(SECOND);
		get_net_work_download_speed(&end_download_speed, &end_upload_speed, "RX bytes:", "TX bytes:");
		result_of_download = (end_download_speed-start_download_speed);
		result_of_upload = (end_upload_speed-start_upload_speed);
		if (fpup = fopen("/tmp/k3screenctrl/upspeed", "w")){
			fprintf(fpup, "%d\n", result_of_upload);
			fclose(fpup);
		}
		if (fpdo = fopen("/tmp/k3screenctrl/downspeed", "w")){
			fprintf(fpdo, "%d\n", result_of_download);
			fclose(fpdo);
		}
		get_time();
		sleep(SECOND*5);
	}
}
 
int get_net_work_download_speed(int * download_speed, int * upload_speed, char * download_type, char * upload_type)
{
	FILE * pipo_stream;
	size_t bytes_read;
	char buffer[BUFFER];
	char * match;
	int wan;

	if ((pipo_stream=popen("ifconfig", "r")) == NULL )
	{
		printf("K3SCREEND:not found any wan!\n");//reboot/upgrade? exit
		exit(1);
	}
	fread(buffer, 1, sizeof(buffer), pipo_stream);
	fclose(pipo_stream);

	if (strstr(buffer, "ppp0"))
		wan=1;
	else if (strstr(buffer, "vlan2"))
		wan=2;
	else if (strstr(buffer, "eth0"))
		wan=3;
	else
		wan=0;
	if (wan==1)
		pipo_stream=popen("ifconfig ppp0", "r");
	else if (wan==2)
		pipo_stream=popen("ifconfig vlan2", "r");
	else if (wan==3)
		pipo_stream=popen("ifconfig eth0", "r");
	else {
GETERR:
		upload_speed=0;
		download_speed=0;
		return 0;
	}
	bytes_read = fread(buffer, 1, sizeof(buffer), pipo_stream);
 
	if ( (fclose(pipo_stream)) != 0 )
	{
		printf("fclose error!\n");
goto GETERR;
	}
 
	if ( bytes_read == 0 )
	{
		printf("bytes_read == 0\n");
goto GETERR;
	}	
 
	match = strstr(buffer, download_type);
 
	if (match == NULL)
	{
		printf("NO Keyword %s To Find!\n", download_type);
goto GETERR;
	}
 
	sscanf(match, "RX bytes:%ld", download_speed);
 
	match = strstr(buffer, upload_type);
	if (match == NULL)
	{
		printf("No Keyword %s To Find!\n", upload_type);
goto GETERR;
	}
	sscanf(match, "TX bytes:%ld", upload_speed);
	return 0;	
 
}
