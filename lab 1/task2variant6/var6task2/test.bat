set PROGRAM="%~1"

REM запуск программы без параметров
%PROGRAM%
IF ERRORLEVEL 1 GOTO err

REM запуск программы с одним нечисловым параметром
%PROGRAM% notANumber
IF NOT ERRORLEVEL 1 GOTO err

REM запуск прогрраммы с пустой строкой в качестве одного из параметров
%PROGRAM% ""
IF NOT ERRORLEVEL 1 GOTO err

REM запуск прогрраммы с отрицательным числом в качестве одного из параметров
%PROGRAM% -10
IF NOT ERRORLEVEL 1 GOTO err

REM запуск прогрраммы с числом превышающим значение 255 в качестве одного из параметров
%PROGRAM% 500
IF NOT ERRORLEVEL 1 GOTO err

REM запуск прогрраммы с числом превышающим значение int в качестве одного из параметров
%PROGRAM% 999999999999
IF NOT ERRORLEVEL 1 GOTO err

REM запуск программы с одним числовым параметром (и проверяет результат)
%PROGRAM% 6 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 6-96.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с одним числовым параметром (и проверяет результат)
%PROGRAM% 140 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 140-49.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с одним числовым параметром (и проверяет результат)
%PROGRAM% 16 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 16-8.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с одним числовым параметром (и проверяет результат)
%PROGRAM% 255 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 255-255.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с одним числовым параметром (и проверяет результат)
%PROGRAM% 0 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 0-0.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с одним числовым параметром (и проверяет результат)
%PROGRAM% 254 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 254-127.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с одним числовым параметром (и проверяет результат)
%PROGRAM% 128 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 128-1.txt
IF ERRORLEVEL 1 GOTO err


ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT