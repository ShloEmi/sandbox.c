@echo OFF
cl hello.c /nologo /W4

IF %ERRORLEVEL% NEQ 0 GOTO :ERROR_COMPILE

link *.obj
GOTO :DONE

:ERROR_COMPILE
Echo Error compiling!

:DONE
Echo Exiting..
pause
