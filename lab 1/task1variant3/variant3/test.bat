set PROGRAM="%~1"

REM запуск программы без параметров
%PROGRAM%
IF ERRORLEVEL 1 GOTO err

REM запуск программы с одним словом в качестве параметра (и проверяет результат)
%PROGRAM% input1.txt Moscow > output.txt
IF NOT ERRORLEVEL 1 GOTO err
FC /B output.txt 0.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с одной фразой в качестве параметра (и проверяет результат)
%PROGRAM% input1.txt "Who doesn't love music?"  > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 1.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с одним повторяющимся словом в качестве параметра (и проверяет результат)
%PROGRAM% input1.txt are > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt "7 9 11 15 17.txt"
IF ERRORLEVEL 1 GOTO err

REM заууск программы с одной фразой в качестве параметра (и проверяет результат)
%PROGRAM% input1.txt "silence or holidays" > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 5.txt
IF ERRORLEVEL 1 GOTO err

REM запууск программы с одной фразой в качестве параметра (и проверяет результат)
%PROGRAM% input1.txt "Probably it is so" > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 19.txt
IF ERRORLEVEL 1 GOTO err

REM запууск программы с одной конечной фразой в качестве параметра (и проверяет результат)
%PROGRAM% input1.txt "This is a great way to mix business with pleasure." > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 21.txt
IF ERRORLEVEL 1 GOTO err

REM запууск программы с одной конечной фразой в качестве параметра (и проверяет результат)
%PROGRAM% input2.txt "chanson, hip-hop and others. " > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt 5v2.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT