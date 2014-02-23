无线网卡驱动B43安装指南
=======================
### 网卡型号
```console
junze@Junze-PC ~ $ lspci -vnn | grep 14e4:
04:00.0 Network controller [0280]: Broadcom Corporation BCM4312 802.11b/g LP-PHY [14e4:4315] (rev 01)
	Subsystem: Broadcom Corporation Device [14e4:04b5]
07:00.0 Ethernet controller [0200]: Broadcom Corporation NetLink BCM5906M Fast Ethernet PCI Express [14e4:1713] (rev 02)
```

### Download source files from [AUR](https://aur.archlinux.org/packages/b43-firmware/)
The most important file is PKGBUILD. you may just download a [tarball](https://aur.archlinux.org/packages/b4/b43-firmware/b43-firmware.tar.gz) for all required.

### Build the package
#### Uncompress the tarball
```shell
tar -zxvf tarball-name.tar.gz
```
#### Build
Run the following command at where you find file PKGBUILD
```shell
makepkg
```

### Install the package
```shell
pacman -U b43-package-file.tar.gz.xz
```

### More detail
[How to choose driver for Broadcom Wireless](https://wiki.archlinux.org/index.php/B43)
[Arch User Reposition (ARU) GUIDE](https://wiki.archlinux.org/index.php/Arch_User_Repository)
[Where you can download B43 tarball](https://aur.archlinux.org/packages/b43-firmware/)

