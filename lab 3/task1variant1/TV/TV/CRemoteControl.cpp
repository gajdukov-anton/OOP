#include "stdafx.h"
#include "CRemoteControl.h"
#include "CTVSet.h"
#include <string>
#include <iostream>

using namespace std;

const string COMMAND_TURN_ON = "TurnOn";
const string COMMAND_TURN_OFF = "TurnOff";
const string COMMAND_SELECT_CHANNEL = "SelectChannel";
const string COMMAND_INFO = "info";
const string COMMAND_SELECT_LAST_CHANNEL = "SelectLastChannel";

CRemoteControl::CRemoteControl(CTVSet& tv)
	:m_tv(tv)
{
}


CRemoteControl::~CRemoteControl()
{
}

bool CRemoteControl::HandleCommand(const std::string& command)
{
	bool commandDone = false;
	if (command == COMMAND_TURN_ON)
	{
		TurnOn();
		commandDone = true;
	}
	if (command == COMMAND_TURN_OFF)
	{
		TurnOff();
		commandDone = true;
	}
	if (command == COMMAND_INFO)
	{
		Info();
		commandDone = true;
	}
	if (command == COMMAND_SELECT_LAST_CHANNEL)
	{
		SelectPreviousChannel();
		commandDone = true;
	}
	if (!commandDone)
	{
		if (CheckCommand(command))
		{
			commandDone = true;
			int number;
			number = GetNumberOfChannel(command, 13);
			if (number == 0)
			{
				cout << "Invalid number of channel" << endl;
				return false;
			}
			else
				cout << "Selected channel: " << m_tv.SelectChannel(number) << endl;
		}
	}
	if (!commandDone)
	{
		cout << "Invalid command" << endl;
		return false;
	}
	return true;
}

bool CRemoteControl::TurnOn()
{
	
	if (m_tv.TurnOn())
	{
		cout << "TV is turned on" << endl;
	}
	else
	{
		cout << "TV has already turned on" << endl;
	}
	return true;
}

bool CRemoteControl::TurnOff()
{
	if (m_tv.TurnOff())
	{
		cout << "TV is turned off" << endl;
	}
	else
	{
		cout << "TV has already turned off" << endl;
	}
	return true;
}

bool CRemoteControl::Info()
{
	cout << m_tv.info() << endl;
	return true;
}

bool CRemoteControl::SelectChannel(int channel)
{
	cout << "Selected channel: " << m_tv.SelectChannel(channel) << endl;
	return true;
}

bool CRemoteControl::SelectPreviousChannel()
{
	cout << "Selected last channel: " << m_tv.SelectPreviousChannel() << endl;
	return true;
}

int CRemoteControl::GetNumberOfChannel(const std::string& strWithCommand, size_t positionOfNumber)
{
	size_t amountOfElement = strWithCommand.size();
	string strWithNumber = "";
	int numberOfChannel;
	for (size_t i = positionOfNumber + 1; i < amountOfElement; i++)
	{
		if (i == amountOfElement - 1 && strWithCommand[i] != '>')
			return 0;
		if (strWithCommand[i] != '>')
			strWithNumber += strWithCommand[i];
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

bool CRemoteControl::CheckCommand(const std::string& command)
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
