#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <cassert>


class CMyString
{
public:
	CMyString();
	CMyString(const char * pString);
	CMyString(const char * pString, size_t length);
	CMyString(CMyString const& other);
	CMyString(std::string const& stlString);
	CMyString& operator =(CMyString const& other);
	CMyString& operator +=(CMyString const& other);
	bool operator ==(CMyString const& other) const;
	bool operator !=(CMyString const& other) const;
	bool operator <(CMyString const& other) const;
	bool operator >(CMyString const& other) const;
	CMyString const operator +(CMyString const& other) const;
	const char & operator[](size_t index) const;
	char & operator[](size_t index);
	const char * GetStringData() const;
	int GetLength() const;
	void Clear();
	CMyString SubString(size_t start, size_t length = SIZE_MAX)const;

	~CMyString();
private:
	std::unique_ptr<char[] > m_ptrChar;
	size_t m_length = 0;
};

CMyString const operator +(std::string& str, CMyString const& myStr);
CMyString const operator +(const char * pString, CMyString const& myStr);

