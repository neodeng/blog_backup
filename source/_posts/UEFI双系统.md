title: UEFI双系统
date: 2014-11-04 01:23:12
comments: True
tags:
	system
---
传统的BIOS担任着操作系统控制硬件的中介，目前，已经发展出最新的UEFI(Unified Extensible Firmware Interface)固件接口，这种接口大部分是C语言编写的；运行于64位模式，突破了传统16位代码的寻址能力，从而运行速度快；向下兼容性好，是由EFI字节代码编写而成；内置图形界面，且扩展性很强大。UEFI在引导时提供了SecureBoot,虽然大大加快了开机速度，但是也禁止了加载未知的系统，从而不能在SecureBoot开启的情况下安装双系统。
<!--more-->
###访问UEFI设置
在WIN8中，windows+i进入windows设置->更改电脑设置->通用设置/更新与恢复->高级启动->立即重新启动->疑难解答->高级选项->UEFI设置->重启电脑，即以UEFI启动系统
###禁用安全启动
移动选项卡到Secure/Boot下，在Secure Boot选Disabled,退出并保存设置。
选择启动顺序  U盘HDD优先
###重启，安装ubuntu
做好U盘启动盘，接入重启，安装ubuntu。

