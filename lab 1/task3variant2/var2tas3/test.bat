set PROGRAM="%~1"

REM runnig program without parametrs
%PROGRAM% 
IF NOT ERRORLEVEL 1 GOTO err

REM running program with nonexistent file
%PROGRAM% tests\notANumber.txt
IF NOT ERRORLEVEL 1 GOTO err

REM running program with standart matrix #1
ECHO Running program with standart matrix #1
%PROGRAM% tests\matrix.txt > tests\output.txt
IF ERRORLEVEL 1 GOTO err
FC /B tests\output.txt tests\result1.txt
IF ERRORLEVEL 1 GOTO err

REM running program with standart matrix #2
ECHO Running program with standart matrix #2
%PROGRAM% tests\matrix2.txt > tests\output.txt
IF ERRORLEVEL 1 GOTO err
FC /B tests\output.txt tests\result2.txt
IF ERRORLEVEL 1 GOTO err

REM running program with matrix with a null determinant
ECHO Running program with matrix with a null determinant
%PROGRAM% tests\matrix3.txt > tests\output.txt
IF ERRORLEVEL 1 GOTO err
FC /B tests\output.txt tests\result3.txt
IF ERRORLEVEL 1 GOTO err

REM running program with matrix with a matrix4
ECHO Running program with matrix with a matrix4
%PROGRAM% tests\matrix4.txt > tests\output.txt
IF ERRORLEVEL 1 GOTO err
FC /B tests\output.txt tests\result4.txt
IF ERRORLEVEL 1 GOTO err

REM running program with Unit matrix 
ECHO Running program with Unit matrix 
%PROGRAM% tests\unitMatrix.txt > tests\output.txt
IF ERRORLEVEL 1 GOTO err
FC /B tests\output.txt tests\result5.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT