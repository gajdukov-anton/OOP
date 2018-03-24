#include "stdafx.h"
#include "CTVSet.h"
#include <vector>
#include <iostream>
#include <string>


CTVSet::CTVSet()
{
	m_isActivated = false;
	m_currentChannel = 1;
	m_lastChannel = 1;
	m_channels.reserve(99);
}


CTVSet::~CTVSet()
{
}

bool CTVSet::TurnOn() 
{
	if (!m_isActivated)
	{
		m_isActivated = true;
		return true;
	}
	else
		return false;
}

bool CTVSet::TurnOff()
{
	if (m_isActivated)
	{
		m_isActivated = false;
		return true;
	}
	else
		return false;
}

int CTVSet::SelectChannel(int channelNumber)
{
	if (!m_isActivated)
		return 0;
	if (!(channelNumber >= 1 && channelNumber <= 99))
		return 0;
	m_lastChannel = m_currentChannel;
	m_currentChannel = channelNumber;
	return m_currentChannel;
}

int CTVSet::SelectLastChannel()
{
	if (!m_isActivated)
		return 0;
	m_currentChannel = m_lastChannel;
	return m_currentChannel;
}

std::string CTVSet::info() const 
{
	std::string tvStatus = "";
	if (m_isActivated)
		tvStatus = "The TV is on, current chanel: " + std::to_string(m_currentChannel);
	else
		tvStatus = "The TV is off, current chanel: 0";
	return tvStatus;
}

