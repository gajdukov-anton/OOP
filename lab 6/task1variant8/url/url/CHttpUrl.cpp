#include "stdafx.h"
#include "CHttpUrl.h"
#include "CommandForParsing.h"
#include "CUrlParsingError.h"


CHttpUrl::CHttpUrl(std::string const& url)
	:m_url(url)
{
	ParseUrl(url);
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol)
	:m_domain(domain), m_document(document), m_protocol(protocol)
{
	if (m_document[0] != '/')
		m_document = "/" + m_document;

	if (!CheckDomain(m_domain))
		throw CUrlParsingError("Invalid type of Domain.");
	if (!CheckDocument(m_document))
		throw CUrlParsingError("Invalid type of Document.");

	if (m_protocol == HTTP)
		m_port = 80;
	else
		m_port = 443;
}


CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port)
	:m_domain(domain), m_document(document), m_protocol(protocol), m_port(port)
{
	if (m_document[0] != '/')
		m_document = "/" + m_document;

	if (!CheckDomain(m_domain))
		throw CUrlParsingError("Invalid type of Domain.");
	if (!CheckDocument(m_document))
		throw CUrlParsingError("Invalid type of Document.");

	if (m_protocol == HTTP && m_port != 80)
		throw CUrlParsingError("Invalid value of port.");
	if (m_protocol == HTTPS && m_port != 443)
		throw CUrlParsingError("Invalid value of port.");
}

void CHttpUrl::ParseUrl(std::string const& url)
{
	size_t pos;
	std::string str = GetProtocolFromUrl(url, pos);

	if (str == "")
		throw CUrlParsingError("Invalid type of Protocol.");
	if (str == "http")
	{
		m_protocol = HTTP;
		m_port = 80;
	}
	if (str == "https")
	{
		m_protocol = HTTPS;
		m_port = 443;
	}

	str = GetDomainFromUrl(url, pos + 1, pos);
	if (str != "")
		m_domain = str;
	else
		throw CUrlParsingError("Invalid type of Domain.");

	str = GetDocumentFromUrl(url, pos);
	if (str != "")
		m_document = str;
	else
		throw CUrlParsingError("Invalid type of Document.");
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
