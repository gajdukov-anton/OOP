// testUrld.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../../../url/CHttpUrl.h"
#include "../../../url/CommandForParsing.h"
#include "../../../url/CUrlParsingError.h"
#include <iostream>
#include <string>

using namespace std;

TEST_CASE("CHttpUrl constructor and main methods tests")
{
	cout << "CHttpUrl constructor and main methods tests started" << endl;
	CHttpUrl testUrl1("www.google.com", "index.html", HTTP);
	CHttpUrl testUrl2("www.yandex.com", "index.html", HTTP, 80);
	CHECK(testUrl1.GetDocument() == "/index.html");
	CHECK(testUrl1.GetProtocol() == HTTP);
	CHECK(testUrl1.GetDomain() == "www.google.com");
	CHECK(testUrl2.GetDocument() == "/index.html");
	CHECK(testUrl2.GetProtocol() == HTTP);
	CHECK(testUrl2.GetDomain() == "www.yandex.com");
	CHECK(testUrl2.GetPort() == 80);
}

TEST_CASE("GetDomainFromUrl tests")
{
	cout << "GetDomainFromUrl tests started" << endl;
	string testStr1 = "http://www.google.com/";
	string testStr2 = "https://www.google.com/index.htlm";
	string testStr3 = "wwwgoogle.com/";
	string testStr4 = "//ww.google.com/";
	string testStr5 = "//wwwgoogle.com/";
	string testStr6 = "//www.googlecom/";
	string testStr7 = "//www.google.com";
	string testStr8 = "http://www.google.comindex.html";
	size_t pos = 6;
	CHECK(GetDomainFromUrl(testStr1, 7, pos) == "www.google.com");
	CHECK(pos == 21);
	CHECK(GetDomainFromUrl(testStr2, 8, pos) == "www.google.com");
	CHECK(pos == 22);
	CHECK(GetDomainFromUrl(testStr3, 0, pos) == "");
	CHECK(GetDomainFromUrl(testStr4, 2, pos) == "");
	CHECK(GetDomainFromUrl(testStr5, 2, pos) == "");
	CHECK(GetDomainFromUrl(testStr6, 2, pos) == "");
	CHECK(GetDomainFromUrl(testStr7, 2, pos) == "");
	CHECK(GetDomainFromUrl(testStr8, 7, pos) == "");
}

TEST_CASE("GetDocumentFromUrl tests")
{
	cout << "GetDocumentFromUrl tests started" << endl;
	string testStr1 = "http//www.google.com/index.html";
	string testStr2 = "//www.google.com/main/index.html";
	string testStr3 = "http//www.google.com/";
	CHECK(GetDocumentFromUrl(testStr2, 16) == "/main/index.html");
	CHECK(GetDocumentFromUrl(testStr1, 20) == "/index.html");
	CHECK(GetDocumentFromUrl(testStr3, 20) == "");
}

TEST_CASE("GetProtocol tests")
{
	cout << "GetProtocol tests started" << endl;
	string testStr1 = "http://www.google.com/index.html";
	string testStr2 = "https://www.google.com/index.html";
	string testStr3 = "httpss://www.google.com/index.html";
	string testStr4 = "https:/www.google.com/index.html";
	size_t pos;
	CHECK(GetProtocolFromUrl(testStr1, pos) == "http");
	CHECK(pos == 6);
	CHECK(GetProtocolFromUrl(testStr2, pos) == "https");
	CHECK(pos == 7);
	CHECK(GetProtocolFromUrl(testStr3, pos) == "");
	CHECK(GetProtocolFromUrl(testStr4, pos) == "");
}

TEST_CASE("Constructor with only string tests")
{
	cout << "Constructor with only string tests" << endl;
	string testStr1 = "http://www.google.com/index.html";
	string testStr2 = "https://www.google.com/main/index.html";
	string testStr3 = "htp://www.google.com/index.html";
	string testStr4 = "http//www.google.com/index.html";
	CHttpUrl testUrl1(testStr1);
	CHttpUrl testUrl2(testStr2);
	try
	{
		CHttpUrl testUrl3(testStr3);
	}
	catch (CUrlParsingError error)
	{
		CHECK(error.GetMessage() == "Invalid type of Protocol.");
	}
	try
	{
		CHttpUrl testUrl4(testStr4);
	}
	catch (CUrlParsingError error)
	{
		CHECK(error.GetMessage() == "Invalid type of Protocol.");
	}
	CHECK(testUrl1.GetDomain() == "www.google.com");
	CHECK(testUrl1.GetDocument() == "/index.html");
	CHECK(testUrl1.GetProtocol() == HTTP);
	CHECK(testUrl1.GetPort() == 80);
	CHECK(testUrl2.GetDomain() == "www.google.com");
	CHECK(testUrl2.GetDocument() == "/main/index.html");
	CHECK(testUrl2.GetProtocol() == HTTPS);
	CHECK(testUrl2.GetPort() == 443);
}