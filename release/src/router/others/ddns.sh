#!/bin/sh

server=`nvram get ddns_server_x`
username=`nvram get ddns_username_x`
pass=`nvram get ddns_passwd_x`
hostname=`nvram get ddns_hostname_x`
wanip=`nvram get wan0_ipaddr`
dualwan=`nvram get wans_dualwan`

if [ "$server" == "3322" ]
then
   if [ "$dualwan" != "wan none" ]; then
      wget -q -O - "http://$username:$pass@members.3322.net/dyndns/update?hostname=$hostname&myip=$wanip"   
   else
      wget -q -O - "http://$username:$pass@members.3322.net/dyndns/update?hostname=$hostname"
   fi
if [ $? -eq 0 ]; then
    /sbin/ddns_custom_updated 1
else                           
    /sbin/ddns_custom_updated 0
fi 
fi

if [ "$server" == "oray" ]
then
   if [ "$dualwan" != "wan none" ]; then
      result=`curl -s "http://$username:$pass@ddns.oray.com/ph/update?hostname=$hostname&myip=$wanip"|tr " " "\n"|sed -n 1p`
      case $result in
      good|nochg)
      /sbin/ddns_custom_updated 1 
      ;;
      *)
      /sbin/ddns_custom_updated 0
      ;;
      esac
   else
      result=`curl -s "http://$username:$pass@ddns.oray.com/ph/update?hostname=$hostname"|tr " " "\n"|sed -n 1p`
      case $result in
      good|nochg)
      /sbin/ddns_custom_updated 1
      ;;
      *)
      /sbin/ddns_custom_updated 0
      ;;
      esac
   fi
fi

if [ "$server" == "changeip" ]
then
   if [ "$dualwan" != "wan none" ]; then
      wget -q -O - "http://nic.ChangeIP.com/nic/update?u=$username&p=$pass&hostname=$hostname&cmd=update&offline=0&myip=$wanip"   
   else
      wget -q -O - "http://nic.ChangeIP.com/nic/update?u=$username&p=$pass&hostname=$hostname&cmd=update&offline=0"
   fi
if [ $? -eq 0 ]; then
    /sbin/ddns_custom_updated 1
else                           
    /sbin/ddns_custom_updated 0
fi 
fi
