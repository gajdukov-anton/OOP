set PROGRAM="%~1"

REM запуск программы без параметров
%PROGRAM% 
IF ERRORLEVEL 1 GOTO err

REM запуск программы с несуществующим файлом
%PROGRAM% notANumber.txt
IF NOT ERRORLEVEL 1 GOTO err

REM запууск программы со стандартной матрицей №1 (и проверяет результат)
%PROGRAM% matrix.txt > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result1.txt
IF ERRORLEVEL 1 GOTO err

REM запууск программы со стандартной матрицей №2 (и проверяет результат)
%PROGRAM% matrix2.txt > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result2.txt
IF ERRORLEVEL 1 GOTO err

REM запууск программы с матрицей, имеющий нулевой определитель (и проверяет результат)
%PROGRAM% matrix3.txt > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result3.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT