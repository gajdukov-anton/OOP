#include "stdafx.h"
#include "CUrlParsingError.h"


CUrlParsingError::CUrlParsingError(std::string const& message)
	:invalid_argument(message)
{
	m_message = message;
}

std::string CUrlParsingError::GetMessage() const
{
	return m_message;
}

CUrlParsingError::~CUrlParsingError()
{
}
