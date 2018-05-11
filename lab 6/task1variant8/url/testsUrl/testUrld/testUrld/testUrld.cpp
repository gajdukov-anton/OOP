// testUrld.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../../../url/CHttpUrl.h"
#include "../../../url/CommandForParsing.h"
#include "../../../url/CUrlParsingError.h"

using namespace std;

const string INVALID_DOMAIN_EXCEPTION = "Invalid type of Domain.";
const string INVALID_DOCUMENT_EXCEPTION = "Invalid type of Document.";
const string INVALID_PROTOCOL_EXCEPTION = "Invalid type of Protocol.";
const string INVALID_PORT_EXCEPTION = "Invalid value of port.";

TEST_CASE("CheckDomain tests")
{
	cout << "CheckDomain tests started" << endl;
	string testDomain1 = "www.google.com";
	string testDomain2 = "ww.google.com";
	string testDomain3 = "wwwgoogle.com";
	string testDomain4 = "www.googlecom";
	string testDomain5 = "www..com";
	string testDomain6 = "www";
	string testDomain7 = ".com";
	string testDomain8 = "www.";
	CHECK(CheckDomain(testDomain1) == true);
	CHECK(CheckDomain(testDomain2) == false);
	CHECK(CheckDomain(testDomain3) == false);
	CHECK(CheckDomain(testDomain4) == false);
	CHECK(CheckDomain(testDomain5) == false);
	CHECK(CheckDomain(testDomain6) == false);
	CHECK(CheckDomain(testDomain7) == false);
	CHECK(CheckDomain(testDomain8) == false);
}

TEST_CASE("CheckDocument tests")
{
	cout << "CheckDocument tests started" << endl;
	string testDocument1 = "/index.html";
	string testDocument2 = "/";
	string testDocument3 = "";
	string testDocument4 = "//inde.html";
	string testDocument5 = "index.html";
	string testDocument6 = "/ind?ex.html";
	CHECK(CheckDocument(testDocument1) == true);
	CHECK(CheckDocument(testDocument2) == false);
	CHECK(CheckDocument(testDocument3) == false);
	CHECK(CheckDocument(testDocument4) == false);
	CHECK(CheckDocument(testDocument5) == false);
	CHECK(CheckDocument(testDocument6) == false);

}

TEST_CASE("GetDomainFromUrl tests")
{
	cout << "GetDomainFromUrl tests started" << endl;
	string testStr1 = "http://www.google.com/";
	string testStr2 = "https://www.google.com/index.htlm";
	string testStr3 = "http://wwwgoogle.com/index.html";
	string testStr4 = "http://ww.google.com/index.html";
	string testStr5 = "http://wwwgooglecom/index.htm;";
	string testStr6 = "http://wwwcom/index.html";
	string testStr7 = "http://www.google.com/";
	string testStr8 = "http://www..com/index.html";
	string testStr9 = "http://www.com/index.html";
	size_t pos = 6;
	CHECK(GetDomainFromUrl(testStr1, 7, pos) == "www.google.com");
	CHECK(pos == 21);
	CHECK(GetDomainFromUrl(testStr2, 8, pos) == "www.google.com");
	CHECK(pos == 22);
	CHECK(GetDomainFromUrl(testStr3, 7, pos) == "");
	CHECK(GetDomainFromUrl(testStr4, 7, pos) == "");
	CHECK(GetDomainFromUrl(testStr5, 7, pos) == "");
	CHECK(GetDomainFromUrl(testStr6, 7, pos) == "");
	CHECK(GetDomainFromUrl(testStr7, 7, pos) == "www.google.com");
	CHECK(GetDomainFromUrl(testStr8, 7, pos) == "");
	CHECK(GetDomainFromUrl(testStr9, 7, pos) == "");
}

TEST_CASE("GetDocumentFromUrl tests")
{
	cout << "GetDocumentFromUrl tests started" << endl;
	string testStr1 = "http://www.google.com/index.html";
	string testStr2 = "https://www.google.com/main/index.html";
	string testStr3 = "http://www.google.com/";
	CHECK(GetDocumentFromUrl(testStr2, 22) == "/main/index.html");
	CHECK(GetDocumentFromUrl(testStr1, 21) == "/index.html");
	CHECK(GetDocumentFromUrl(testStr3, 21) == "");
}

TEST_CASE("GetProtocol tests")
{
	cout << "GetProtocol tests started" << endl;
	string testStr1 = "http://www.google.com/index.html";
	string testStr2 = "https://www.google.com/index.html";
	string testStr3 = "httpss://www.google.com/index.html";
	string testStr4 = "https:/www.google.com/index.html";
	string testStr5 = "https:://www.google.com/index.html";
	size_t pos;
	CHECK(GetProtocolFromUrl(testStr1, pos) == "http");
	CHECK(pos == 6);
	CHECK(GetProtocolFromUrl(testStr2, pos) == "https");
	CHECK(pos == 7);
	CHECK(GetProtocolFromUrl(testStr3, pos) == "");
	CHECK(GetProtocolFromUrl(testStr4, pos) == "");
	CHECK(GetProtocolFromUrl(testStr5, pos) == "");
}

TEST_CASE("Constructor with only string tests(valid values)")
{
	cout << "Constructor with only string tests(valid values) started" << endl;
	string testStr1 = "http://www.google.com/index.html";
	string testStr2 = "https://www.google.com/main/index.html";
	string testStr3 = "https://www.yandex.ru/main/index.html";
	CHttpUrl testUrl1(testStr1);
	CHttpUrl testUrl2(testStr2);
	CHttpUrl testUrl3(testStr3);
	CHECK(testUrl1.GetDomain() == "www.google.com");
	CHECK(testUrl1.GetDocument() == "/index.html");
	CHECK(testUrl1.GetProtocol() == HTTP);
	CHECK(testUrl1.GetPort() == 80);
	CHECK(testUrl2.GetDomain() == "www.google.com");
	CHECK(testUrl2.GetDocument() == "/main/index.html");
	CHECK(testUrl2.GetProtocol() == HTTPS);
	CHECK(testUrl2.GetPort() == 443);
	CHECK(testUrl3.GetDomain() == "www.yandex.ru");
	CHECK(testUrl3.GetDocument() == "/main/index.html");
	CHECK(testUrl3.GetProtocol() == HTTPS);
	CHECK(testUrl3.GetPort() == 443);
}

TEST_CASE("Constructor with only string tests(invalid values)")
{
	cout << "Constructor with only string tests(invalid values) started" << endl;
	string testStr1 = "htp://www.google.com/index.html";
	string testStr2 = "htttp://www.google.com/index.html";
	string testStr3 = "http//www.google.com/index.html";
	string testStr4 = "http:/www.google.com/index.html";
	string testStr5 = "http:://www.google.com/index.html";
	string testStr6 = "http://wwww.google.com/index.html";
	string testStr7 = "http://wwwwgooglecom/index.html";
	string testStr8 = "http://wwww..com/index.html";
	string testStr9 = "http://wwww.com/index.html";
	string testStr10 = "http://wwwwgoogle.com/index.html";
	string testStr11 = "http://www.google.com//index.html";
	string testStr12 = "http://www.google.com/in//dex.html";
	string testStr13 = "http://www.google.com/";
	string testStr14 = "http://www.google.com/ind?ex.html";

	//invalid protocol
	try
	{
		CHttpUrl testUrl("");
	}
	catch (CUrlParsingError error)
	{
		CHECK(error.GetMessage() == INVALID_PROTOCOL_EXCEPTION);
	}
	try
	{
		CHttpUrl testUrl(testStr1);
	}
	catch (CUrlParsingError error)
	{
		CHECK(error.GetMessage() == INVALID_PROTOCOL_EXCEPTION);
	}
	try
	{
		CHttpUrl testUrl(testStr2);
	}
	catch (CUrlParsingError error)
	{
		CHECK(error.GetMessage() == INVALID_PROTOCOL_EXCEPTION);
	}
	try
	{
		CHttpUrl testUrl(testStr3);
	}
	catch (CUrlParsingError error)
	{
		CHECK(error.GetMessage() == INVALID_PROTOCOL_EXCEPTION);
	}
	try
	{
		CHttpUrl testUrl(testStr4);
	}
	catch (CUrlParsingError error)
	{
		CHECK(error.GetMessage() == INVALID_PROTOCOL_EXCEPTION);
	}
	try
	{
		CHttpUrl testUrl(testStr5);
	}
	catch (CUrlParsingError error)
	{
		CHECK(error.GetMessage() == INVALID_PROTOCOL_EXCEPTION);
	}

	//invalid domain
	try
	{
		CHttpUrl testUrl(testStr6);
	}
	catch (CUrlParsingError error)
	{
		CHECK(error.GetMessage() == INVALID_DOMAIN_EXCEPTION);
	}
	try
	{
		CHttpUrl testUrl(testStr7);
	}
	catch (CUrlParsingError error)
	{
		CHECK(error.GetMessage() == INVALID_DOMAIN_EXCEPTION);
	}
	try
	{
		CHttpUrl testUrl(testStr8);
	}
	catch (CUrlParsingError error)
	{
		CHECK(error.GetMessage() == INVALID_DOMAIN_EXCEPTION);
	}
	try
	{
		CHttpUrl testUrl(testStr9);
	}
	catch (CUrlParsingError error)
	{
		CHECK(error.GetMessage() == INVALID_DOMAIN_EXCEPTION);
	}
	try
	{
		CHttpUrl testUrl(testStr10);
	}
	catch (CUrlParsingError error)
	{
		CHECK(error.GetMessage() == INVALID_DOMAIN_EXCEPTION);
	}

	//invalid document
	try
	{
		CHttpUrl testUrl(testStr11);
	}
	catch (CUrlParsingError error)
	{
		CHECK(error.GetMessage() == INVALID_DOCUMENT_EXCEPTION);
	}
	try
	{
		CHttpUrl testUrl(testStr12);
	}
	catch (CUrlParsingError error)
	{
		CHECK(error.GetMessage() == INVALID_DOCUMENT_EXCEPTION);
	}
	try
	{
		CHttpUrl testUrl(testStr13);
	}
	catch (CUrlParsingError error)
	{
		CHECK(error.GetMessage() == INVALID_DOCUMENT_EXCEPTION);
	}
	try
	{
		CHttpUrl testUrl(testStr14);
	}
	catch (CUrlParsingError error)
	{
		CHECK(error.GetMessage() == INVALID_DOCUMENT_EXCEPTION);
	}
}

TEST_CASE("Constructor with domain, protocol and document tests(valid values)")
{
	cout << "Constructor with domain, protocol and document tests(valid values) started" << endl;
	CHttpUrl testUrl1("www.google.com", "index.html", HTTP);
	CHttpUrl testUrl2("www.yandex.com", "main/index.html", HTTPS);
	CHECK(testUrl1.GetDocument() == "/index.html");
	CHECK(testUrl1.GetProtocol() == HTTP);
	CHECK(testUrl1.GetDomain() == "www.google.com");
	CHECK(testUrl1.GetPort() == 80);
	CHECK(testUrl2.GetDocument() == "/main/index.html");
	CHECK(testUrl2.GetProtocol() == HTTPS);
	CHECK(testUrl2.GetDomain() == "www.yandex.com");
	CHECK(testUrl2.GetPort() == 443);
}

TEST_CASE("Constructor with domain, protocol and document tests(invalid values)")
{
	cout << "Constructor with domain, protocol and document tests(invalid values) started" << endl;
	try
	{
		CHttpUrl testUrl("wwwgoogle.com", "index.html", HTTP);
	}
	catch (invalid_argument error)
	{
		CHECK(error.what() == INVALID_DOMAIN_EXCEPTION);
	}
	try
	{
		CHttpUrl testUrl("www.google.com", "", HTTP);
	}
	catch (invalid_argument error)
	{
		CHECK(error.what() == INVALID_DOCUMENT_EXCEPTION);
	}
	try
	{
		CHttpUrl testUr("www..com", "index.html", HTTP);
	}
	catch (invalid_argument error)
	{
		CHECK(error.what() == INVALID_DOMAIN_EXCEPTION);
	}
	try
	{
		CHttpUrl testUr("www.googlecom", "index.html", HTTP);
	}
	catch (invalid_argument error)
	{
		CHECK(error.what() == INVALID_DOMAIN_EXCEPTION);
	}
	try
	{
		CHttpUrl testUr("www..google.com", "index.html", HTTP);
	}
	catch (invalid_argument error)
	{
		CHECK(error.what() == INVALID_DOMAIN_EXCEPTION);
	}
	try
	{
		CHttpUrl testUr("ww.google.com", "index.html", HTTP);
	}
	catch (invalid_argument error)
	{
		CHECK(error.what() == INVALID_DOMAIN_EXCEPTION);
	}
	try
	{
		CHttpUrl testUr("", "index.html", HTTP);
	}
	catch (invalid_argument error)
	{
		CHECK(error.what() == INVALID_DOMAIN_EXCEPTION);
	}
	try
	{
		CHttpUrl testUrl("www.google.com", "//index.html", HTTP);
	}
	catch (invalid_argument error)
	{
		CHECK(error.what() == INVALID_DOCUMENT_EXCEPTION);
	}
	try
	{
		CHttpUrl testUrl("www.google.com", "/", HTTP);
	}
	catch (invalid_argument error)
	{
		CHECK(error.what() == INVALID_DOCUMENT_EXCEPTION);
	}
	try
	{
		CHttpUrl testUrl("www.google.com", "/in?dex.html", HTTP);
	}
	catch (invalid_argument error)
	{
		CHECK(error.what() == INVALID_DOCUMENT_EXCEPTION);
	}
	try
	{
		CHttpUrl testUrl("www.google.com", "/in*dex.html", HTTP);
	}
	catch (invalid_argument error)
	{
		CHECK(error.what() == INVALID_DOCUMENT_EXCEPTION);
	}
}

TEST_CASE("Constructor with domain, protocol, document and port tests(valid values)")
{
	cout << "Constructor with domain, protocol, document and port tests(valid values) started" << endl;
	CHttpUrl testUrl1("www.google.com", "index.html", HTTP, 80);
	CHttpUrl testUrl2("www.yandex.com", "main/index.html", HTTPS, 443);
	CHECK(testUrl1.GetDocument() == "/index.html");
	CHECK(testUrl1.GetProtocol() == HTTP);
	CHECK(testUrl1.GetDomain() == "www.google.com");
	CHECK(testUrl1.GetPort() == 80);
	CHECK(testUrl2.GetDocument() == "/main/index.html");
	CHECK(testUrl2.GetProtocol() == HTTPS);
	CHECK(testUrl2.GetDomain() == "www.yandex.com");
	CHECK(testUrl2.GetPort() == 443);
}

TEST_CASE("Constructor with domain, protocol, document and port tests(invalid values)")
{
	cout << "Constructor with domain, protocol, document and port tests(invalid values) started" << endl;

	//invalid domain
	try
	{
		CHttpUrl testUrl("wwwgoogle.com", "index.html", HTTP, 80);
	}
	catch (invalid_argument error)
	{
		CHECK(error.what() == INVALID_DOMAIN_EXCEPTION);
	}
	try
	{
		CHttpUrl testUr("www..com", "index.html", HTTP, 80);
	}
	catch (invalid_argument error)
	{
		CHECK(error.what() == INVALID_DOMAIN_EXCEPTION);
	}
	try
	{
		CHttpUrl testUr("www.googlecom", "index.html", HTTP, 80);
	}
	catch (invalid_argument error)
	{
		CHECK(error.what() == INVALID_DOMAIN_EXCEPTION);
	}
	try
	{
		CHttpUrl testUr("www..google.com", "index.html", HTTP, 80);
	}
	catch (invalid_argument error)
	{
		CHECK(error.what() == INVALID_DOMAIN_EXCEPTION);
	}
	try
	{
		CHttpUrl testUr("ww.google.com", "index.html", HTTP, 80);
	}
	catch (invalid_argument error)
	{
		CHECK(error.what() == INVALID_DOMAIN_EXCEPTION);
	}
	try
	{
		CHttpUrl testUr("", "index.html", HTTP, 80);
	}
	catch (invalid_argument error)
	{
		CHECK(error.what() == INVALID_DOMAIN_EXCEPTION);
	}

	//invalid document
	try
	{
		CHttpUrl testUrl("www.google.com", "", HTTP, 80);
	}
	catch (invalid_argument error)
	{
		CHECK(error.what() == INVALID_DOCUMENT_EXCEPTION);
	}
	try
	{
		CHttpUrl testUrl("www.google.com", "//index.html", HTTP, 80);
	}
	catch (invalid_argument error)
	{
		CHECK(error.what() == INVALID_DOCUMENT_EXCEPTION);
	}
	try
	{
		CHttpUrl testUrl("www.google.com", "/", HTTP, 80);
	}
	catch (invalid_argument error)
	{
		CHECK(error.what() == INVALID_DOCUMENT_EXCEPTION);
	}
	try
	{
		CHttpUrl testUrl("www.google.com", "/in?dex.html", HTTP, 80);
	}
	catch (invalid_argument error)
	{
		CHECK(error.what() == INVALID_DOCUMENT_EXCEPTION);
	}
	try
	{
		CHttpUrl testUrl("www.google.com", "/in*dex.html", HTTP, 80);
	}
	catch (invalid_argument error)
	{
		CHECK(error.what() == INVALID_DOCUMENT_EXCEPTION);
	}

	//invalid port
	try
	{
		CHttpUrl testUrl("www.google.com", "index.html", HTTP, 800);
	}
	catch (invalid_argument error)
	{
		CHECK(error.what() == INVALID_PORT_EXCEPTION);
	}
	try
	{
		CHttpUrl testUrl("www.google.com", "index.html", HTTP, -10);
	}
	catch (invalid_argument error)
	{
		CHECK(error.what() == INVALID_PORT_EXCEPTION);
	}
	try
	{
		CHttpUrl testUrl("www.google.com", "index.html", HTTPS, 800);
	}
	catch (invalid_argument error)
	{
		CHECK(error.what() == INVALID_PORT_EXCEPTION);
	}
}