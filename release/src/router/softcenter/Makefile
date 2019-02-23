include ../common.mak

install:
	install -d $(INSTALLDIR)/usr/sbin
	install -d $(INSTALLDIR)/usr/bin
	install -d $(INSTALLDIR)/usr/share
	install -d $(INSTALLDIR)/etc/softcenter/bin
	install -d $(INSTALLDIR)/etc/softcenter/res
	install -d $(INSTALLDIR)/etc/softcenter/webs
	install -d $(INSTALLDIR)/etc/softcenter/perp
	install -d $(INSTALLDIR)/etc/softcenter/scripts
	install -d $(INSTALLDIR)/etc/softcenter/perp/.boot
	install -d $(INSTALLDIR)/etc/softcenter/perp/.control

# softcenter
	install -m 0755 softcenter/bin/perpboot $(INSTALLDIR)/etc/softcenter/bin
	install -m 0755 softcenter/bin/perpctl $(INSTALLDIR)/etc/softcenter/bin
	install -m 0755 softcenter/bin/perpd $(INSTALLDIR)/etc/softcenter/bin
	install -m 0755 softcenter/bin/perphup $(INSTALLDIR)/etc/softcenter/bin
	install -m 0755 softcenter/bin/perpls $(INSTALLDIR)/etc/softcenter/bin
	install -m 0755 softcenter/bin/perpok $(INSTALLDIR)/etc/softcenter/bin
	install -m 0755 softcenter/bin/perpstat $(INSTALLDIR)/etc/softcenter/bin
	install -m 0755 softcenter/bin/sissylog $(INSTALLDIR)/etc/softcenter/bin
	install -m 0755 softcenter/bin/tinylog $(INSTALLDIR)/etc/softcenter/bin
	install -m 0755 softcenter/res/icon-default.png $(INSTALLDIR)/etc/softcenter/res
	install -m 0755 softcenter/webs/Main_Soft_center.asp $(INSTALLDIR)/etc/softcenter/webs
	install -m 0755 softcenter/webs/Main_Soft_setting.asp $(INSTALLDIR)/etc/softcenter/webs
	install -m 0755 softcenter/perp/perp.sh $(INSTALLDIR)/etc/softcenter/perp
	install -m 0755 softcenter/perp/.boot/rc.log $(INSTALLDIR)/etc/softcenter/perp/.boot
	install -m 0755 softcenter/perp/.boot/rc.perp $(INSTALLDIR)/etc/softcenter/perp/.boot
	install -m 0755 softcenter/perp/.control/perpd.pid $(INSTALLDIR)/etc/softcenter/perp/.control
	install -m 0755 softcenter/scripts/base.sh $(INSTALLDIR)/etc/softcenter/scripts
	install -m 0755 softcenter/scripts/ks_app_install.sh $(INSTALLDIR)/etc/softcenter/scripts
	install -m 0755 softcenter/scripts/ks_tar_intall.sh $(INSTALLDIR)/etc/softcenter/scripts
	install -m 0755 softcenter/scripts/pluginbase.sh $(INSTALLDIR)/etc/softcenter/scripts
	install -m 0755 jffsinit.sh $(INSTALLDIR)/usr/sbin
	#install -m 0755 k3screen $(INSTALLDIR)/usr/sbin
	#install -m 0755 k3screen.sh $(INSTALLDIR)/usr/sbin
	install -m 0755 phi_speed $(INSTALLDIR)/usr/sbin
	install -m 0755 plugin.sh $(INSTALLDIR)/usr/sbin
	install -m 0755 uqmi $(INSTALLDIR)/usr/sbin
	install -m 0755 weather $(INSTALLDIR)/usr/sbin
	install -m 0755 wl_cr $(INSTALLDIR)/usr/sbin
	install -m 0755 helper.sh $(INSTALLDIR)/usr/sbin
	install -m 0755 libshared.so $(INSTALLDIR)/usr/share

clean:
