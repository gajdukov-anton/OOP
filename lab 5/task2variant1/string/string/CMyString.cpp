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

const char* CMyString::GetStringData() const
{
	return m_ptrChar ? m_ptrChar.get() : "";
}

int CMyString::GetLength() const
{
	return m_length;
}

void CMyString::Clear()
{
	m_ptrChar = NULL;
	m_length = 0;
}

CMyString& CMyString::operator =(CMyString const& other)
{
	if (std::addressof(other) != this)
	{
		CMyString tmpCopy(other);
		std::swap(m_ptrChar, tmpCopy.m_ptrChar);
		std::swap(m_length, tmpCopy.m_length);
	}
	return *this;
}

CMyString& CMyString::operator +=(CMyString const& other)
{
	CMyString tmpCopy(other);
	std::unique_ptr<char[] > newPtrChar = std::make_unique<char[]>(m_length + tmpCopy.m_length + 1);
	memcpy(newPtrChar.get(), m_ptrChar.get(), m_length);
	memcpy(newPtrChar.get() + m_length, tmpCopy.GetStringData(), tmpCopy.m_length + 1);
	std::swap(m_ptrChar, newPtrChar);
	m_length = strlen(m_ptrChar.get());
	return *this;
}

bool CMyString::operator ==(CMyString const& other) const
{
	if (other.m_length != m_length)
	{
		return false;
	}
	for (size_t i = 0; i < m_length; i++)
	{
		if (other.m_ptrChar[i] != m_ptrChar[i])
		{
			return false;
		}
	}
	return true;
}


CMyString::~CMyString()
{
}
