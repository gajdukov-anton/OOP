#include "stdafx.h"
#include "CommandForParsing.h"

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
	if (domain.find("www.") != 0)
		return false;
	if (domain.find(".", 4) == std::string::npos)
		return false;
	return true;
}

std::string GetDomainFromUrl(std::string const& url, size_t& endOfDomain)
{
	std::string domain = "//";
	if (url.size() < 8)
		return "";
	if (CheckDomain(url.substr(2, url.size() - 2)))
	{
		size_t i = 2;
		while (url[i] != '/')
		{
			domain += url[i];
			i++;
			if (i == url.size())
				return "";
		}
		endOfDomain = i;
	}
	else
		return "";
	return domain;
}

std::string GetDocumentFromUrl(std::string const& url, size_t startOfDocument)
{
	std::string document;
	if (url.size() == startOfDocument + 1)
		return "";
	for (size_t i = startOfDocument; i < url.size(); i++)
		document += url[i];
	return document;
}