// miniDictonary.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <map>

using namespace std;

const string endOfWork = "...";

void FillTheDictonary(map <string, string>& dictonaryForFill, ifstream& fileWithDictonary);
string FindValueInDictonary(map <string, string>& dictonaryForFind, map <string, string>& newDictonaryForFind, string key);
void WriteToDictonary(map <string, string>& dictonaryForWrite, pair <string, string>& newWord);
void SaveNewDictonary(map <string, string>& dictonaryForSave, ofstream& fileWithDictonary);

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "rus");

	if (argc <= 1)
	{
		cout << "Please, enter name of program and name of dictonary as an example: miniDictonary.exe fileOfDictonary.txt. \n";
		return 1;
	}
		
	ifstream inputFile(argv[1]);
	map <string, string> dictonary;
	map <string, string> newDictonary;

	if (inputFile.is_open())
		FillTheDictonary(dictonary, inputFile);

	inputFile.close();
	ofstream outputFile(argv[1], ios_base::app);
	string str;
	string value;
	getline(cin, str);

	while (str != endOfWork)
	{
		value = FindValueInDictonary(dictonary, newDictonary, str);
		if (value == "")
		{
			cout << "Неизвестное слово \"" << str << "\". Введите перевод или пустую строку для отказа." << endl;
			getline(cin, value);
			if (value != "")
			{
				pair <string, string> newWord(str, value);
				WriteToDictonary(newDictonary, newWord);
				cout << "Слово \"" << str << "\" сохранено в словаре как \"" << value << "\". " << endl;
			}
			else
				cout << "Слово " << str << " проигнорировано." << endl;
		}
		else
			cout << value << endl;
		getline(cin, str);
	}

	cout << "В словарь быои внесены изменения нажмите \"Y\" для сохранения." << endl;
	getline(cin, str);
	if (str == "Y")
	{
		SaveNewDictonary(newDictonary, outputFile);
		cout << "Изменения сохранены. До свидания. " << endl;
	}
	else
		cout << "Изменения отклонены. До свидания. " << endl;

    return 0;
}

void FillTheDictonary(map <string, string>& dictonaryForFill, ifstream& fileWithDictonary)
{
	string key = "";
	string value = "";

	while (getline(fileWithDictonary, key))
	{
		getline(fileWithDictonary, value);
		dictonaryForFill.insert(pair<string, string>(key, value));
	}
}

string FindValueInDictonary(map <string, string>& dictonaryForFind, map <string, string>& newDictonaryForFind, string key)
{
	auto posOfValueInOldDictonary = dictonaryForFind.find(key);
	auto posOfValueInNewDictonary = newDictonaryForFind.find(key);
	if (posOfValueInOldDictonary != dictonaryForFind.end())
		return dictonaryForFind[key];  
	if (posOfValueInNewDictonary != newDictonaryForFind.end())
		return newDictonaryForFind[key];
	return "";
}

void WriteToDictonary(map <string, string>& dictonaryForWrite, pair <string, string>& newWord)
{
	dictonaryForWrite.insert(newWord);
}

void SaveNewDictonary(map <string, string>& dictonaryForSave, ofstream& fileWithDictonary)
{
	for (auto it = dictonaryForSave.begin(); it != dictonaryForSave.end(); ++it)
		fileWithDictonary << (*it).first << endl << (*it).second << endl;
}
