#pragma once
#include <vector>
#include <string>

class CTVSet
{
public:
	CTVSet();

	~CTVSet();

	bool TurnOn();

	bool TurnOff();

	int SelectChannel(int channelNumber);

	int SelectPreviousChannel();

	std::string info() const;

private:
	bool m_isActivated;
	int m_currentChannel;
	int m_lastChannel;
	std::vector<std::string> m_channels;
};

