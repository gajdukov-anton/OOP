REM запуск программы без параметров
var6task2.exe
IF ERRORLEVEL 1 GOTO err

REM запуск программы с одним нечисловым параметром
var6task2.exe notANumber
IF NOT ERRORLEVEL 1 GOTO err

REM запуск прогрраммы с пустой строкой в качестве одного из параметров
var6task2.exe ""
IF NOT ERRORLEVEL 1 GOTO err

REM запуск прогрраммы с отрицательным числом в качестве одного из параметров
var6task2.exe -10
IF NOT ERRORLEVEL 1 GOTO err

REM запуск прогрраммы с числом превышающим значение 255 в качестве одного из параметров
var6task2.exe 500
IF NOT ERRORLEVEL 1 GOTO err

REM запуск программы с одним числовым параметром (и проверяет результат)
var6task2.exe 6 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 6-96.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с одним числовым параметром (и проверяет результат)
var6task2.exe 140 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 140-49.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с одним числовым параметром (и проверяет результат)
var6task2.exe 16 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 16-8.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с одним числовым параметром (и проверяет результат)
var6task2.exe 255 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 255-255.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с одним числовым параметром (и проверяет результат)
var6task2.exe 0 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 0-0.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с одним числовым параметром (и проверяет результат)
var6task2.exe 254 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 254-127.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с одним числовым параметром (и проверяет результат)
var6task2.exe 128 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 128-1.txt
IF ERRORLEVEL 1 GOTO err


ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT