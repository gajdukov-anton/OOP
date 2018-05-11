#pragma once


std::string GetDocumentFromUrl(std::string const& url, size_t startOfDocument);
std::string GetDomainFromUrl(std::string const& url, size_t startDomain, size_t& endOfDomain);
bool CheckDomain(std::string const& domain);
bool CheckDocument(std::string const& document);
void ToLowerCase(std::string& str);
std::string GetProtocolFromUrl(std::string const& url, size_t& EndProtocol);
