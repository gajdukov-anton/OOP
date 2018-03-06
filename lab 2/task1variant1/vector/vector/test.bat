set PROGRAM="%~1"

REM running the program without parameters
%PROGRAM%
IF NOT ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT