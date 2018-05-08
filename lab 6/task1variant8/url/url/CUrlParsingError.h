#pragma once
class CUrlParsingError : public std::invalid_argument
{
public:
	CUrlParsingError(std::string const& message);
	std::string GetMessage() const;
	~CUrlParsingError();
private:
	std::string m_message;
};

