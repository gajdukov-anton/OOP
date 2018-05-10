#pragma once

enum Protocol
{
	HTTP,
	HTTPS
};


class CHttpUrl
{
public:
    CHttpUrl(std::string const& url);
	CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol = HTTP);
	CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port);
	std::string GetUrl() const;
	std::string GetDomain() const;
	std::string GetDocument() const;
	Protocol GetProtocol() const;
	unsigned short GetPort() const;
		~CHttpUrl();
private:
	std::string m_url;
	std::string m_domain;
	std::string m_document;
	Protocol m_protocol;
	unsigned short m_port;
	//bool CheckDomain(std::string const& domain) const;
	void ParseUrl(std::string const& url);
};

