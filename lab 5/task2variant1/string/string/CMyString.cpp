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
	memcpy(m_ptrChar.get(), (pString + '\0'), m_length + 1);
	m_ptrChar[m_length] = '\0';
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
	:CMyString(stlString.c_str(), stlString.length())
{
}

const char* CMyString::GetStringData() const
{
	return m_ptrChar ? m_ptrChar.get() + '\0' : "";
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

bool CMyString::operator !=(CMyString const& other) const
{
	if (other.m_length != m_length)
	{
		return true;
	}
	for (size_t i = 0; i < m_length; i++)
	{
		if (other.m_ptrChar[i] != m_ptrChar[i])
		{
			return true;
		}
	}
	return false;
}

CMyString const CMyString::operator +(CMyString const& other) const
{
	std::unique_ptr<char[] > newPtrChar = std::make_unique<char[]>(m_length + other.m_length + 1);
	memcpy(newPtrChar.get(), m_ptrChar.get(), m_length);
	memcpy(newPtrChar.get() + m_length, other.GetStringData(), other.m_length + 1);
	return CMyString(newPtrChar.get());
}

CMyString const operator +(std::string& str, CMyString const& myStr)
{
	std::unique_ptr<char[] > newPtrChar = std::make_unique<char[]>(myStr.GetLength() + str.length() + 1);
	memcpy(newPtrChar.get(), myStr.GetStringData(), myStr.GetLength());
	memcpy(newPtrChar.get() + myStr.GetLength(), str.c_str(), str.length() + 1);
	return CMyString(newPtrChar.get());
}

CMyString const operator +(const char * pString, CMyString const& myStr)
{
	std::unique_ptr<char[] > newPtrChar = std::make_unique<char[]>(myStr.GetLength() + strlen(pString) + 1);
	memcpy(newPtrChar.get(), myStr.GetStringData(), myStr.GetLength());
	memcpy(newPtrChar.get() + myStr.GetLength(), pString, strlen(pString) + 1);
	return CMyString(newPtrChar.get());
}

const char& CMyString::operator[](size_t index) const
{
	if (index < m_length && m_length > 0)
		return m_ptrChar[index];
	else
		throw std::out_of_range("the index should be in the range from 0 to the length of the string");
}


char& CMyString::operator[](size_t index)
{
	char pr = ' ';
	if (index < m_length && m_length > 0)
		return m_ptrChar[index];
	else
		throw std::out_of_range("the index should be in the range from 0 to the length of the string");
}

bool CMyString::operator <(CMyString const& other) const
{
	size_t i = 0;
	while (i < m_length && i < other.m_length)
	{
		if (m_ptrChar[i] > other.m_ptrChar[i])
		{
			return false;
		}
		i++;
	}
	if (i < m_length)
	{
		return false;
	}
	return true;
}

bool CMyString::operator >(CMyString const& other) const
{
	size_t i = 0;
	while (i < m_length && i < other.m_length)
	{
		if (m_ptrChar[i] < other.m_ptrChar[i])
		{
			return false;
		}
		i++;
	}
	if (i < other.m_length)
	{
		return false;
	}
	return true;
}

CMyString::~CMyString()
{
}
