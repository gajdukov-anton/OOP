#include "stdafx.h"
#include "WorkWithCommandr.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

string RemoveBlanks(const string& strWithCommand)
{
	string command = "";
	size_t amountLetters = strWithCommand.size();

	for (size_t i = 0; i < amountLetters; i++)
	{
		if (strWithCommand[i] != ' ')
			command += strWithCommand[i];
	}
	return command;
}

int GetNumberOfChannel(const std::string& strWithCommand, size_t positionOfNumber)
{
	size_t amountOfElement = strWithCommand.size();
	string strWithNumber = "";
	int numberOfChannel;
	for (size_t i = positionOfNumber + 1; i < amountOfElement - 1; i++)
	{
		if (strWithCommand[i] != '>')
			strWithNumber += strWithCommand[i];
		else
			break;
	}
	try
	{
		numberOfChannel = stoi(strWithNumber);
	}
	catch (const std::invalid_argument)
	{
		return 0;
	}
	return numberOfChannel;
}

bool CheckCommand(const std::string& command)
{
	const string COMMAND_SELECT_CHANNEL = "SelectChannel";
	bool isCommand = true;
	bool isEndCommand = false;
	size_t i = 0;
	while (isCommand && !isEndCommand)
	{
		if (command[i] != COMMAND_SELECT_CHANNEL[i] || i == command.size() - 2)
			isCommand = false;
		i++;
		if (command[i] == '<')
			isEndCommand = true;
	}
	return isCommand;
}