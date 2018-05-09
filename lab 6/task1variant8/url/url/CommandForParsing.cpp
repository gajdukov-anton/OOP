#include "stdafx.h"
#include "CommandForParsing.h"
#include "CUrlParsingError.h"

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

std::string GetDomainFromUrl(std::string const& url, size_t startDomain, size_t& endOfDomain)
{
	std::string domain = "";
	/*size_t pos = url.find("://");
	if (pos == std::string::npos)
		throw CUrlParsingError("Invalid type of url, not enough \"://\" after protocol.");
	pos += 3;*/
	if (CheckDomain(url.substr(startDomain, url.size() - startDomain)))
	{
		size_t i = startDomain;
		while (url[i] != '/')
		{
			domain += url[i];
			i++;
			if (i == url.size())
				//throw CUrlParsingError("Invalid type of url, not enough document after domain.");
				return "";
		}
		endOfDomain = i;
	}
	else
		//throw CUrlParsingError("Invalid type of domain.");
		return "";
	return domain;
}

std::string GetDocumentFromUrl(std::string const& url, size_t startOfDocument)
{
	std::string document;
	if (url.size() == startOfDocument + 1)
		//throw CUrlParsingError("Invalid type of url, not enough document after domain.");
		return "";
	for (size_t i = startOfDocument; i < url.size(); i++)
		document += url[i];
	return document;
}

std::string GetProtocolFromUrl(std::string const& url, size_t& EndProtocol)
{
	std::string protocol = url.substr(0, 4);
	ToLowerCase(protocol);

	if (protocol != "http")
		//throw CUrlParsingError("Invalid type of protocol.");
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
	//throw CUrlParsingError("Invalid type of protocol.");
}