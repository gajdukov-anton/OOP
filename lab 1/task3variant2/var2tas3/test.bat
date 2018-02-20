set PROGRAM="%~1"

REM ������ ��������� ��� ����������
%PROGRAM% 
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � �������������� ������
%PROGRAM% notANumber.txt
IF NOT ERRORLEVEL 1 GOTO err

REM ������� ��������� �� ����������� �������� �1 (� ��������� ���������)
%PROGRAM% matrix.txt > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result1.txt
IF ERRORLEVEL 1 GOTO err

REM ������� ��������� �� ����������� �������� �2 (� ��������� ���������)
%PROGRAM% matrix2.txt > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result2.txt
IF ERRORLEVEL 1 GOTO err

REM ������� ��������� � ��������, ������� ������� ������������ (� ��������� ���������)
%PROGRAM% matrix3.txt > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result3.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT