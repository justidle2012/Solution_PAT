@echo off
:loop
	gen.exe %random% > data.in
	std.exe < data.in >std.out
	pta1021.exe < data.in > my.out
	fc my.out std.out
if not errorlevel 1 goto loop
pause
goto loop


