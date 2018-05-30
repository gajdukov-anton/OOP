#include "stdafx.h"
#include "CStackError.h"


CStackError::CStackError(std::string const& message)
	:out_of_range(message)
{
	m_message = message;
}

std::string CStackError::GetMessage() const
{
	return m_message;
}

CStackError::~CStackError()
{
}
