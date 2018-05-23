#pragma once


template <typename Type>
class CMyIterator
{
public:

	CMyIterator();
	CMyIterator(Type* iterator);
	CMyIterator<Type>& operator=(const CMyIterator& other);
	CMyIterator<Type>& operator++();
	CMyIterator<Type>& operator--();
	bool operator==(const CMyIterator& other) const;
	bool operator!=(const CMyIterator& other) const;
	CMyIterator<Type>& operator+=(const int& offset);
	CMyIterator<Type>& operator-=(const int& offset);
	Type GetValue() const;
	~CMyIterator();

private:
	Type * m_iterator = nullptr;
};

template <typename Type>
CMyIterator<Type>::CMyIterator()
{
}

template <typename Type>
CMyIterator<Type>::CMyIterator(Type* iterator)
	:m_iterator(iterator)
{
}

template<typename Type>
CMyIterator<Type>& CMyIterator<Type>::operator=(const CMyIterator& other)
{
	if (std::addressof(other) != this)
	{
		m_iterator = other.m_iterator;
	}
	return *this;
}

template<typename Type>
CMyIterator<Type>& CMyIterator<Type>::operator++()
{
	if (++*m_iterator)
	{
		//++m_iterator;
	}
	return *this;
}

template<typename Type>
CMyIterator<Type>& CMyIterator<Type>::operator--()
{
	if (--*m_iterator)
	{
		//--m_iterator;
	}
	return *this;
}

template<typename Type>
bool CMyIterator<Type>::operator==(const CMyIterator& other) const
{
	return (m_iterator == other.m_iterator);
}

template<typename Type>
bool CMyIterator<Type>::operator!=(const CMyIterator& other) const
{
	return (m_iterator != other.m_iterator);
}

template<typename Type>
CMyIterator<Type>& CMyIterator<Type>::operator+=(const int& offset)
{
	m_iterator += offset;
	return *this;
}

template<typename Type>
CMyIterator<Type>& CMyIterator<Type>::operator-=(const int& offset)
{
	m_iterator -= offset;
	return *this;
}

template <typename Type>
Type  CMyIterator<Type>::GetValue() const
{
	return *m_iterator;
}

template <typename Type>
CMyIterator<Type>::~CMyIterator()
{
}