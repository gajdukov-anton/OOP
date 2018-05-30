#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <cassert>
#include <sstream>
#include <algorithm>
#include "CStackError.h"

class CStringStack
{
public:
	CStringStack();
	CStringStack(const CStringStack& stack);
	CStringStack(CStringStack&& stack);
	CStringStack& operator=(const CStringStack& other);
	CStringStack& operator=(CStringStack && other);
	void Clear();
	size_t GetSize() const;
	size_t GetCapacity()const;
	std::string GetTop() const;
	void ChangeTop(const std::string& str);
	void Push(const std::string& str);
	void Pop();
	~CStringStack();
private:
	std::string * m_begin = nullptr;
	std::string *m_end = nullptr;
	std::string *m_endOfCapacity = nullptr;
	size_t m_length = 0;

	void DeleteItems(std::string * begin, std::string * end);
	void CopyItems(const std::string *srcBegin, std::string *srcEnd, std::string * const dstBegin, std::string * & dstEnd);
	void DestroyItems(std::string * from, std::string *to);
	std::string * RawAlloc(size_t n);
	void RawDealloc(std::string *p);
	
};

