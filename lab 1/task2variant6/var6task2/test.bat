set PROGRAM="%~1"

REM running the program without parameters
%PROGRAM%
IF ERRORLEVEL 1 GOTO err

REM running the program with non-numeric parameter
%PROGRAM% notANumber
IF NOT ERRORLEVEL 1 GOTO err

REM running the program with empty string
%PROGRAM% ""
IF NOT ERRORLEVEL 1 GOTO err

REM running the program with minus parameter
%PROGRAM% -10
IF NOT ERRORLEVEL 1 GOTO err

REM running the program with number exceeding a value of 255
%PROGRAM% 500
IF NOT ERRORLEVEL 1 GOTO err

REM running the program with number exceeding a value
%PROGRAM% 999999999999
IF NOT ERRORLEVEL 1 GOTO err

REM running the program with number (and checking the result)
%PROGRAM% 6 > tests\output.txt
IF ERRORLEVEL 1 GOTO err
FC /B tests\output.txt tests\6-96.txt
IF ERRORLEVEL 1 GOTO err

REM running the program with number (and checking the result)
%PROGRAM% 140 > tests\output.txt
IF ERRORLEVEL 1 GOTO err
FC /B tests\output.txt tests\140-49.txt
IF ERRORLEVEL 1 GOTO err

REM running the program with number (and checking the result)
%PROGRAM% 16 > tests\output.txt
IF ERRORLEVEL 1 GOTO err
FC /B tests\output.txt tests\16-8.txt
IF ERRORLEVEL 1 GOTO err

REM running the program with number (and checking the result)
%PROGRAM% 255 > tests\output.txt
IF ERRORLEVEL 1 GOTO err
FC /B tests\output.txt tests\255-255.txt
IF ERRORLEVEL 1 GOTO err

REM running the program with number (and checking the result)
%PROGRAM% 0 > tests\output.txt
IF ERRORLEVEL 1 GOTO err
FC /B tests\output.txt tests\0-0.txt
IF ERRORLEVEL 1 GOTO err

REM running the program with number (and checking the result)
%PROGRAM% 254 > tests\output.txt
IF ERRORLEVEL 1 GOTO err
FC /B tests\output.txt tests\254-127.txt
IF ERRORLEVEL 1 GOTO err

REM running the program with number (and checking the result)
%PROGRAM% 128 > tests\output.txt
IF ERRORLEVEL 1 GOTO err
FC /B tests\output.txt tests\128-1.txt
IF ERRORLEVEL 1 GOTO err


ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT