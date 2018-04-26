#pragma once
#include <string>
#include <iostream>
#include <memory>

class CMyString
{
public:
	CMyString();
	CMyString(const char * pString);
	CMyString(const char * pString, size_t length);
	CMyString(CMyString const& other);
	CMyString(std::string const& stlString);
	char * GetStringData() const;
	int GetLength() const;

	~CMyString();

private:
	std::unique_ptr<char[] > m_ptrChar;
	int m_length = 0;
};

