set PROGRAM="%~1"

REM running program without parametrs
ECHO Running program without parametrs
%PROGRAM% 
IF NOT ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)
EXIT

:err
ECHO Program testing failed :-(
EXIT