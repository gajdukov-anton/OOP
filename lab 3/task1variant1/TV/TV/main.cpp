// TV.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CTVSet.h"
#include "string"
#include <iostream>
#include "WorkWithCommandr.h"

using namespace std;

const string COMMAND_TURN_ON = "TurnOn";
const string COMMAND_TURN_OFF = "TurnOff";
const string COMMAND_SELECT_CHANNEL = "SelectChannel";
const string COMMAND_INFO = "info";
const string COMMAND_SELECT_LAST_CHANNEL = "SelectLastChannel";

void RunInfoCommand(const string& commandForRun, CTVSet& TV);
void RunTurnOnCommand(const string& commandForRun, CTVSet& TV);
void RunTurnOffCommand(const string& commandForRun, CTVSet& TV);
void RunSelectChannelCommand(const string& commandForRun, CTVSet& TV);
void RunSelectLastChannel(const string& commandForRun, CTVSet& TV);

int main()
{
	string command;
	CTVSet smartTV;

	while (getline(cin, command))
	{
		RunInfoCommand(command, smartTV);
		RunTurnOnCommand(command, smartTV);
		RunTurnOffCommand(command, smartTV);
		RunSelectChannelCommand(command, smartTV);
		RunSelectLastChannel(command, smartTV);
	}
    return 0;
}

void RunInfoCommand(const string& commandForRun, CTVSet& TV)
{
	if (commandForRun == COMMAND_INFO)
		cout << TV.info() << endl;
}

void RunTurnOnCommand(const string& commandForRun, CTVSet& TV)
{
	if (commandForRun == COMMAND_TURN_ON)
		cout << TV.TurnOn() << endl;
}

void RunTurnOffCommand(const string& commandForRun, CTVSet& TV)
{
	if (commandForRun == COMMAND_TURN_OFF)
		cout << TV.TurnOff() << endl;
}

void RunSelectChannelCommand(const string& commandForRun, CTVSet& TV)
{
	int number;
	if (commandForRun != COMMAND_INFO && commandForRun != COMMAND_TURN_ON && commandForRun != COMMAND_TURN_OFF && commandForRun != COMMAND_SELECT_LAST_CHANNEL)
	{
		if (CheckCommand(commandForRun))
		{
			number = GetNumberOfChannel(commandForRun, 13);
			if (number == 0)
				cout << "Invalid number of channel" << endl;
			else
				cout << TV.SelectChannel(number) << endl;
		}
		else
			cout << "Invalid command." << endl;
	}
}

void RunSelectLastChannel(const string& commandForRun, CTVSet& TV)
{
	if (commandForRun == COMMAND_SELECT_LAST_CHANNEL)
		cout << TV.SelectLastChannel() << endl;
}