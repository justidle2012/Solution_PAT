@echo off
:loop
	gen.exe %random% > data.in
	std.exe < data.in >std.out
	pat1064.exe < data.in > my.out
	fc my.out std.out
if not errorlevel 1 goto loop
pause
goto loop


