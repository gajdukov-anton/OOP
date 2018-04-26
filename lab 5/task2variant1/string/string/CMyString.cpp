#include "stdafx.h"
#include "CMyString.h"


CMyString::CMyString()
{
	m_length = 0;
	m_ptrChar = NULL;
}

CMyString::CMyString(const char * pString, size_t length)
{
	m_length = length;
	m_ptrChar = std::make_unique<char[]>(m_length + 1);
	memcpy(m_ptrChar.get(), pString, m_length);
	m_ptrChar[m_length] = (char)(0);
}

CMyString::CMyString(const char * pString)
	:CMyString(pString, strlen(pString))
{
}

CMyString::CMyString(CMyString const& other)
	:CMyString(other.GetStringData(), other.GetLength())
{
}

CMyString::CMyString(std::string const& stlString)
{
	m_length = stlString.length();
	m_ptrChar = std::make_unique<char[]>(m_length + 1);
	memcpy(m_ptrChar.get(), stlString.c_str(), m_length);
	m_ptrChar[m_length] = (char)(0);
}

char* CMyString::GetStringData() const
{
	if (m_ptrChar != 0)
		return m_ptrChar.get();
	else
		return '\0';
}

int CMyString::GetLength() const
{
	return m_length;
}

CMyString::~CMyString()
{
}
