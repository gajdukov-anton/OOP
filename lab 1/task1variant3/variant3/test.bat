set PROGRAM="%~1"

REM ������ ��������� ��� ����������
%PROGRAM%
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ����� ������ � �������� ��������� (� ��������� ���������)
%PROGRAM% input1.txt Moscow > tests\output.txt
IF NOT ERRORLEVEL 1 GOTO err
FC /B tests\output.txt tests\0.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ����� ������ � �������� ��������� (� ��������� ���������)
%PROGRAM% input1.txt "Who doesn't love music?"  > tests\output.txt
IF ERRORLEVEL 1 GOTO err
FC /B tests\output.txt tests\1.txt
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ����� ������������� ������ � �������� ��������� (� ��������� ���������)
%PROGRAM% input1.txt are > tests\output.txt
IF ERRORLEVEL 1 GOTO err
FC /B tests\output.txt "tests\7 9 11 15 17.txt"
IF ERRORLEVEL 1 GOTO err

REM ������ ��������� � ����� ������ � �������� ��������� (� ��������� ���������)
%PROGRAM% input1.txt "silence or holidays" > tests\output.txt
IF ERRORLEVEL 1 GOTO err
FC /B tests\output.txt 5.txt
IF ERRORLEVEL 1 GOTO err

REM ������� ��������� � ����� ������ � �������� ��������� (� ��������� ���������)
%PROGRAM% input1.txt "Probably it is so" > tests\output.txt
IF ERRORLEVEL 1 GOTO err
FC /B tests\output.txt tests\19.txt
IF ERRORLEVEL 1 GOTO err

REM ������� ��������� � ����� �������� ������ � �������� ��������� (� ��������� ���������)
%PROGRAM% input1.txt "This is a great way to mix business with pleasure." > tests\output.txt
IF ERRORLEVEL 1 GOTO err
FC /B tests\output.txt tests\21.txt
IF ERRORLEVEL 1 GOTO err

REM ������� ��������� � ����� �������� ������ � �������� ��������� (� ��������� ���������)
%PROGRAM% input2.txt "chanson, hip-hop and others. " > tests\output.txt
IF ERRORLEVEL 1 GOTO err
FC /B tests\output.txt tests\5v2.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT