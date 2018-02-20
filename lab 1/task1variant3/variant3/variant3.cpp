// task1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc <= 2)
	{
		cout << "You need enter 2 arguments for correct work. \n";
		return 0;
	}

	ifstream input_file(argv[1]);

	if (!input_file.is_open())
	{
		cout << "File is not find, please check your data and repeat again.\n";
		return 1;
	}

	string strForSearch;
	int substrPositionWithinTheStr;
	int numberOfTheCurrentStr = 0;
	int numberOfTheSoughtStr = 0;

	while (!input_file.eof())
	{
		getline(input_file, strForSearch);
		++numberOfTheCurrentStr;
		substrPositionWithinTheStr = strForSearch.find(argv[2]);
		
		if (substrPositionWithinTheStr != -1)
		{
			numberOfTheSoughtStr = numberOfTheCurrentStr;
			cout << numberOfTheSoughtStr << " ";
		}
	}

	input_file.close();

	if (numberOfTheSoughtStr == 0)
	{
		cout << "Text not found.\n";
		return 1;
	}
	return 0;
}
