#pragma once

enum Protocol
{
	HTTP,
	HTTPS
};


class CHttpUrl
{
public:
	CHttpUrl();
    CHttpUrl(std::string const& url);
	CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol = HTTP);
	CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port);
	std::string GetUrl() const;
	std::string GetDomain() const;
	std::string GetDocument() const;
	Protocol GetProtocol() const;
	std::string GetStrProtocol() const;
	unsigned short GetPort() const;
	void CreateProtocol(std::string const& protocloStr);
	void CreatePort(std::string const& portStr);
	void CreateDomain(std::string const& domainStr);
	void CreateDocument(std::string const& documentStr);
	void ParseUrl(std::string const& url);
		~CHttpUrl();
private:
	std::string m_url = "";
	std::string m_domain = "";
	std::string m_document = "";
	Protocol m_protocol = HTTP;
	unsigned short m_port = 80;
	void CreateUrl();
	//bool CheckDomain(std::string const& domain) const;
};

