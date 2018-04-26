// testString.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../../string/CMyString.h"
#include <iostream>
#include <string>

using namespace std;

const string TEST_STR_ONE = "qwerty";
const string TEST_STR_TWO = "pizza";

TEST_CASE("CMyString constructor test")
{
	cout << "Constructor tests started" << endl;
	string strResult;
	CMyString str("qwerty");
	CMyString str1("pizza", 5);
	CHECK(str.GetLength() == 6);
	CHECK(str1.GetLength() == 5);
	CHECK(str.GetStringData() == TEST_STR_ONE);
	CHECK(str1.GetStringData() == TEST_STR_TWO);
}
