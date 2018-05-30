#include "stdafx.h"
#include "CStringStack.h"


CStringStack::CStringStack()
{
}

CStringStack::CStringStack(const CStringStack& stack)
{
	const auto size = stack.GetSize();
	if (size != 0)
	{
		m_begin = RawAlloc(size);
		try
		{
			CopyItems(stack.m_begin, stack.m_end, m_begin, m_end);
			m_endOfCapacity = m_end;
		}
		catch (...)
		{
			DeleteItems(m_begin, m_end);
			throw;
		}
	}
	m_length = static_cast<size_t>(m_end - m_begin);
}

CStringStack::CStringStack(CStringStack&& stack)
	:CStringStack(stack)
{
	stack.Clear();
}

void CStringStack::DeleteItems(std::string * begin, std::string * end)
{
	DestroyItems(begin, end);
	RawDealloc(begin);
}

void CStringStack::CopyItems(const std::string *srcBegin, std::string *srcEnd, std::string * const dstBegin, std::string * & dstEnd)
{
	for (dstEnd = dstBegin; srcBegin != srcEnd; ++srcBegin, ++dstEnd)
	{
		new (dstEnd)std::string(*srcBegin);
	}
}

void CStringStack::DestroyItems(std::string * from, std::string *to)
{
	while (to != from)
	{
		--to;
		to->~basic_string();
	}
}

std::string * CStringStack::RawAlloc(size_t n)
{
	size_t memSize = n * sizeof(std::string);
	std::string * p = static_cast<std::string *>(malloc(memSize));
	if (!p)
	{
		throw std::bad_alloc();
	}
	return p;
}

void CStringStack::RawDealloc(std::string *p)
{
	free(p);
}

size_t CStringStack::GetSize() const
{
	return m_length;
}

size_t CStringStack::GetCapacity() const
{
	return m_endOfCapacity - m_begin;
}

void CStringStack::Clear()
{
	if (GetSize() != 0)
	{
		DeleteItems(m_begin, m_end);
		m_begin = nullptr;
		m_end = nullptr;
		m_endOfCapacity = nullptr;
		m_length = static_cast<size_t>(m_end - m_begin);
	}
}

std::string CStringStack::GetTop() const
{
	return m_length > 0 ? *(m_end - 1) : throw CStackError("it is impossible to get top of empty stack");
}

void CStringStack::ChangeTop(const std::string& str)
{
	/*if (m_length > 0)
	{
		*(m_end - 1) = str;
	}
	else
	{
		throw CStackError("it is impossible to change top of empty stack");
	}*/
	m_length > 0 ? *(m_end - 1) = str : throw CStackError("it is impossible to change top of empty stack");
}

void CStringStack::Push(const std::string& str)
{
	if (m_end == m_endOfCapacity)
	{
		size_t newCapacity = std::max(size_t(1), GetCapacity() * 2);

		auto newBegin = RawAlloc(newCapacity);
		std::string * newEnd = newBegin;
		try
		{
			CopyItems(m_begin, m_end, newBegin, newEnd);
			new (newEnd)std::string(str);
			++newEnd;
		}
		catch (...)
		{
			DeleteItems(newBegin, newEnd);
			throw;
		}
		DeleteItems(m_begin, m_end);

		m_begin = newBegin;
		m_end = newEnd;
		m_endOfCapacity = m_begin + newCapacity;
	}
	else
	{
		new (m_end)std::string(str);
		++m_end;
	}
	m_length = static_cast<size_t>(m_end - m_begin);
}

void CStringStack::Pop()
{
	if (m_length > 0)
	{
		DestroyItems(m_begin + m_length - 1, m_end);
		m_end = m_begin + m_length - 1;
		m_length = static_cast<size_t>(m_end - m_begin);
	}
	else
	{
		throw CStackError("it is impossible to remove from empty stack");
	}
}

CStringStack::~CStringStack()
{
	DeleteItems(m_begin, m_end);
}
