#include "stdafx.h"
#include "CHttpUrl.h"
#include "CUrlParsingError.h"



CHttpUrl::CHttpUrl()
{
}


CHttpUrl::CHttpUrl(std::string const& url)
	:m_url(url)
{
	ParseUrl(url);
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol)
try
	:m_protocol(protocol)
{
	CreateDomain(domain);
	CreateDocument(document);
	if (m_protocol == HTTP)
		m_port = 80;
	else
		m_port = 443;
	CreateUrl();
}
catch (std::invalid_argument error)
{
	throw std::invalid_argument(error.what());
}


CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port)
try
	:m_protocol(protocol)
{
	CreateDomain(domain);
	CreateDocument(document);
	CreatePort(std::to_string(port));
	CreateUrl();
}
catch (std::invalid_argument error)
{
	throw std::invalid_argument(error.what());
}

void CHttpUrl::ParseUrl(std::string const& url)
{
	if (url.empty())
	{
		throw CUrlParsingError("Url is empty");
	}

	std::regex regex(R"(^([A-Za-z0-9-.]+)://([A-Za-z0-9-.]+)(?::([0-9]+))?(?:\/(.*))?$)", std::regex_constants::icase);
	std::smatch result;
	if (!std::regex_match(url, result, regex))
	{
		throw CUrlParsingError("Invalid url");
	}

	CreateProtocol(result[1]);
	CreateDomain(result[2]);
	CreatePort(result[3]);
	CreateDocument(result[4]);
}

void ToLowerCase(std::string& str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (isupper(str[i]))
			str[i] = tolower(str[i]);
	}
}

void CHttpUrl::CreateDocument(std::string const& documentStr)
{
	if (documentStr.size() == 0 || documentStr[0] != '/')
	{
		m_document = '/' + documentStr;
	}
	else
	{
		m_document = documentStr;
	}
}

void CHttpUrl::CreateDomain(std::string const& domainStr)
{
	std::regex regex(R"(^([a-zA-Z0-9]([a-zA-Z0-9\-]{0,31}[a-zA-Z0-9])?\.)+[a-zA-Z]{2,6}$)", std::regex_constants::icase);
	std::smatch result;
	if (!std::regex_match(domainStr, result, regex))
	{
		throw CUrlParsingError("Invalid type of Domain.");
	}
	m_domain = domainStr;
}


void CHttpUrl::CreateProtocol(std::string const& protocolStr)
{
	//ToLowerCase(protocolStr);
	
	if (protocolStr == "http")
	{
		m_protocol = HTTP;
	}
	else if (protocolStr == "https")
	{
		m_protocol = HTTPS;
	}
	else 
	{
		throw CUrlParsingError("Invalid type of Protocol.");
	}
}

void CHttpUrl::CreatePort(std::string const& portStr)
{
	if (m_protocol == HTTP && portStr == "")
	{
		m_port = 80;
	}
	else if (m_protocol == HTTPS && portStr == "")
	{
		m_port = 443;
	}
	else
	{
		try
		{
			int port = std::stoi(portStr);
			if (port >= 1 && port <= 1000)
			{
				m_port = static_cast<unsigned short>(port);
			}
			else
			{
				throw CUrlParsingError("Invalid value of port.");
			}
		}
		catch (...)
		{
			throw CUrlParsingError("Invalid value of port.");
		}
	}
}

void CHttpUrl::CreateUrl()
{
	if (m_protocol == HTTP)
		m_url = "http://" + m_domain + ':' + std::to_string(m_port) + m_document;
	else
		m_url = "https://" + m_domain + ':' + std::to_string(m_port) + m_document;
}

std::string CHttpUrl::GetStrProtocol() const
{
	if (m_protocol == HTTP)
		return "http";
	else
		return "https";
}

std::string CHttpUrl::GetUrl() const
{
	return m_url;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

CHttpUrl::~CHttpUrl()
{
}
