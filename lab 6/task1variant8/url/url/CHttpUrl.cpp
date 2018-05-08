#include "stdafx.h"
#include "CHttpUrl.h"


CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol)
	:m_domain(domain), m_document(document), m_protocol(protocol)
{
	if (m_document[0] != '/')
	{
		m_document = "/" + m_document;
	}

}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port)
	:m_domain(domain), m_document(document), m_protocol(protocol), m_port(port)
{
	if (m_document[0] != '/')
	{
		m_document = "/" + m_document;
	}
}



bool CHttpUrl::ParseUrl(std::string const& url)
{
	std::string str = url.substr(0, 4);
	//ToLowerCase(str);
	if (str != "http" || str != "https")
		return false;
	else if(str == "http")
	{
		m_protocol = HTTP;
		m_url += str;
	}
	else
	{
		m_protocol = HTTPS;
		m_url += str;
	}
	


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
