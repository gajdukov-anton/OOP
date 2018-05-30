#pragma once
#include <string>
class CStackError : public std::out_of_range
{
public:
	CStackError(std::string const& message);
	std::string GetMessage() const;
	~CStackError();
private:
	std::string m_message;

};

