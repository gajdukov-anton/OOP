// task1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

using namespace std;

bool FindText(ifstream& inFile, string str);

int main(int argc, char* argv[])
{
	if (argc <= 2)
	{
		cout << "You need enter 2 arguments for correct work. \n";
		return 0;
	}

	ifstream inputFile(argv[1]);

	if (!inputFile.is_open())
	{
		cout << "File is not find, please check your data and repeat again.\n";
		return 1;
	}

	/*string strForSearch;
	size_t substrPositionWithinTheStr;
	int numberOfTheCurrentStr = 0;
	int numberOfTheSoughtStr = 0;

	while (!inputFile.eof())
	{
		getline(inputFile, strForSearch);
		++numberOfTheCurrentStr;
		
		if (strForSearch.find(argv[2]) != string::npos)
		{
			numberOfTheSoughtStr = numberOfTheCurrentStr;
			cout << numberOfTheSoughtStr << " ";
		}
	}*/
	bool isFindStr = FindText(inputFile, argv[2]);

	if (!isFindStr)
	{
		cout << "Text not found.\n";
		return 1;
	}

	cout.flush();
	return 0;
}

bool FindText(ifstream& inFile, string str)
{
	string strForSearch;
	size_t substrPositionWithinTheStr;
	int numberOfTheCurrentStr = 0;
	int numberOfTheSoughtStr = 0;
	//bool isFindStr = false;

	while (!inFile.eof())
	{
		getline(inFile, strForSearch);
		++numberOfTheCurrentStr;

		if (strForSearch.find(str) != string::npos)
		{
			numberOfTheSoughtStr = numberOfTheCurrentStr;
			cout << numberOfTheSoughtStr << " ";
		}
	}

	if (numberOfTheSoughtStr != 0)
		return true;
	else
		return false;
}
