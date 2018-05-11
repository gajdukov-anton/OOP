#include "stdafx.h"
#include "CommandForParsing.h"
#include "CUrlParsingError.h"

void FillInvalidElements(std::set<char>& setForFill)
{
	setForFill.insert('\'');
	setForFill.insert(':');
	setForFill.insert('*');
	setForFill.insert('?');
	setForFill.insert('"');
	setForFill.insert('<');
	setForFill.insert('>');
	setForFill.insert('|');
}

void ToLowerCase(std::string& str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (isupper(str[i]))
			str[i] = tolower(str[i]);
	}
}

bool CheckDomain(std::string const& domain)
{
	if (domain.size() < 7)
		return false;
	if (domain.find("www.") != 0 || domain[4] == '.')
		return false;
	if (domain.find(".", 5) == std::string::npos)
		return false;
	return true;
}

bool CheckDocument(std::string const& document)
{
	std::set<char> invalidElements;
	FillInvalidElements(invalidElements);

	if (document.size() == 0)
		return false;
	if (document[0] == '/' && document.size() == 1)
		return false;
	if (document[0] != '/')
		return false;

	for (size_t i = 1; i < document.size(); i++)
	{
		if (document[i - 1] == '/' && document[i] == '/')
			return false;
		if (invalidElements.find(document[i]) != invalidElements.end())
			return false;
	}
	return true;
}

std::string GetDomainFromUrl(std::string const& url, size_t startDomain, size_t& endOfDomain)
{
	std::string domain = "";
	size_t i = startDomain;
	while (url[i] != '/' && i != url.size())
	{
		domain += url[i];
		i++;
	}
	endOfDomain = i;
	if (!CheckDomain(domain))
		return "";
	return domain;
}

std::string GetDocumentFromUrl(std::string const& url, size_t startOfDocument)
{
	std::string document = "";
	for (size_t i = startOfDocument; i < url.size(); i++)
		document += url[i];
	if (!CheckDocument(document))
		return "";
	return document;
}

std::string GetProtocolFromUrl(std::string const& url, size_t& EndProtocol)
{
	std::string protocol = url.substr(0, 4);
	ToLowerCase(protocol);

	if (protocol != "http")
		return "";
	if (url[4] == ':' && url[5] == '/'  && url[6] == '/')
	{
		EndProtocol = 6;
		return protocol;
	}
	if (url[4] == 's' && url[5] == ':' && url[6] == '/'  && url[7] == '/')
	{
		EndProtocol = 7;
		return protocol + "s";
	}
	return "";
}