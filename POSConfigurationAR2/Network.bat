regedit /s aloha.reg
set LOCALDIR=C:\BOOTDRV\Aloha
ECHO Y | copy IBERCFG.bat C:\BOOTDRV\Aloha\
netsh interface ip set address name="local area connection"  static 10.253.1.101 255.255.255.0 10.253.1.100 
netsh interface ip set address name="local area connection 2" static 10.253.1.101 255.255.255.0 10.253.1.100 
netsh interface ip set address name="local area connection 3" static 10.253.1.101 255.255.255.0 10.253.1.100 
netsh interface ip set address name="local area connection 4" static 10.253.1.101 255.255.255.0 10.253.1.100 
wmic path win32_computersystem where "Name='%computername%'" CALL rename name='TERM1'
wmic path win32_computersystem where "Name='%computername%'" CALL joindomainorworkgroup name='ALOHA'
xcopy \\10.253.1.100\BOOTDRV\Aloha\bin\*.* /y/c %LOCALDIR%\bin\*.*
xcopy \\10.253.1.100\BOOTDRV\Aloha\data\*.* /y/c %LOCALDIR%\data\*.*
xcopy \\10.253.1.100\BOOTDRV\Aloha\bmp\*.* /y/c %LOCALDIR%\bmp\*.*
shutdown /r -f -t 5
