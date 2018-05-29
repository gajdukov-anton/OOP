#pragma once
template <typename Type>
class CMyRevIterator
{
public:

	CMyRevIterator();
	CMyRevIterator(Type* iterator);
	CMyRevIterator<Type>& operator=(const CMyRevIterator& other);
	CMyRevIterator<Type>& operator++();
	const CMyRevIterator<Type> operator++(int);
	const CMyRevIterator<Type> operator--(int);
	CMyRevIterator<Type>& operator--();
	bool operator==(const CMyRevIterator& other) const;
	bool operator!=(const CMyRevIterator& other) const;
	Type GetValue() const;
	~CMyRevIterator();

private:
	Type * m_iterator = nullptr;
};

template <typename Type>
CMyRevIterator<Type>::CMyRevIterator()
{
}

template <typename Type>
CMyRevIterator<Type>::CMyRevIterator(Type* iterator)
	:m_iterator(iterator)
{
}

template<typename Type>
CMyRevIterator<Type>& CMyRevIterator<Type>::operator=(const CMyRevIterator& other)
{
	if (std::addressof(other) != this)
	{
		m_iterator = other.m_iterator;
	}
	return *this;
}

template<typename Type>
CMyRevIterator<Type>& CMyRevIterator<Type>::operator++()
{
	--m_iterator;
	return *this;
}

template<typename Type>
const CMyRevIterator<Type> CMyRevIterator<Type>::operator++(int)
{
	auto tempIterator(*this);
	++*this;
	return tempIterator;
}

template<typename Type>
const CMyRevIterator<Type> CMyRevIterator<Type>::operator--(int)
{
	auto tempIterator(*this);
	--*this;
	return tempIterator;
}


template<typename Type>
CMyRevIterator<Type>& CMyRevIterator<Type>::operator--()
{
	++m_iterator;
	return *this;
}

template<typename Type>
bool CMyRevIterator<Type>::operator==(const CMyRevIterator& other) const
{
	return (m_iterator == other.m_iterator);
}

template<typename Type>
bool CMyRevIterator<Type>::operator!=(const CMyRevIterator& other) const
{
	return (m_iterator != other.m_iterator);
}

template <typename Type>
Type  CMyRevIterator<Type>::GetValue() const
{
	return *m_iterator;
}

template <typename Type>
CMyRevIterator<Type>::~CMyRevIterator()
{
}