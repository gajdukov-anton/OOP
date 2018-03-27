#pragma once
#include <string>
#include <fstream>
#include <iostream>

class CTVSet;

class CRemoteControl
{
public:
	CRemoteControl(CTVSet& tv);
	bool HandleCommand(const std::string& command);
	~CRemoteControl();

private:
	bool TurnOn();
	bool TurnOff();
	bool Info();
	bool SelectChannel(int channel);
	bool SelectLastChannel();
	int GetNumberOfChannel(const std::string& strWithCommand, size_t positionOfNumber);
	bool CheckCommand(const std::string& command);

private:
	CTVSet& m_tv;
};

