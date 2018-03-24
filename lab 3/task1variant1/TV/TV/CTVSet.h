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

	std::string info() const;

private:
	bool m_isActivated;
	int m_currentChannel;
	std::vector<std::string> m_channels;
};

