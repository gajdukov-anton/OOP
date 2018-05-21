// CMyArrayTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../../../CMyArray.h"
#include <iostream>
#include <string>

using namespace std;

void FillArr(CMyArray<int>& arrInt, CMyArray<string>& arrString, CMyArray<double>& arrDouble);

TEST_CASE("Constructor tests")
{
	cout << "Constructor tests started" << endl;
	CMyArray<int> arrInt;
	CMyArray<string> arrString;
	CMyArray<double> arrDouble;
	FillArr(arrInt, arrString, arrDouble);
	CMyArray<int> testArr1(arrInt);
	CHECK(testArr1.GetSize() == arrInt.GetSize());
	CHECK(testArr1[0] == arrInt[0]);
}

TEST_CASE("Append tests")
{
	cout << "Append tests started" << endl;
	CMyArray<int> arrInt;
	CMyArray<string> arrString;
	CMyArray<double> arrDouble;

	CHECK(arrString.GetSize() == 0);
	CHECK(arrInt.GetSize() == 0);
	CHECK(arrDouble.GetSize() == 0);
	FillArr(arrInt, arrString, arrDouble);
	CHECK(arrInt.GetSize() == 10);
	CHECK(arrString.GetSize() == 10);
	CHECK(arrDouble.GetSize() == 10);
	//arrDouble.GetAll();
}

TEST_CASE("Resize tests")
{
	cout << "Resize tests started" << endl;
	CMyArray<int> arrInt;
	CMyArray<string> arrString;
	CMyArray<double> arrDouble;
	arrString.Resize(12);
	CHECK(arrString.GetSize() == 12);
	//arrString.GetAll();
	FillArr(arrInt, arrString, arrDouble);
	arrInt.Resize(24);
	//arrInt.GetAll();
	CHECK(arrInt.GetSize() == 24);
	arrInt.Resize(20);
	//arrInt.GetAll();
	CHECK(arrInt.GetSize() == 20);
}

TEST_CASE("Operator = tests")
{
	cout << "Operator = tests started" << endl;
	CMyArray<int> arrInt;
	CMyArray<string> arrString;
	CMyArray<double> arrDouble;
	FillArr(arrInt, arrString, arrDouble);
	CMyArray<int> testArr1;
	CMyArray<string> testArr2 = arrString;
	arrInt = testArr1;
	testArr2.GetAll();
	CHECK(arrInt.GetSize() == testArr1.GetSize());
	CHECK(testArr2.GetSize() == arrString.GetSize());
}

TEST_CASE("Clear tests")
{
	cout << "Clear tests started" << endl;
	CMyArray<int> arrInt;
	CMyArray<string> arrString;
	CMyArray<double> arrDouble;
	FillArr(arrInt, arrString, arrDouble);
	arrInt.Clear();
	CHECK(arrInt.GetSize() == 0);
}

TEST_CASE("Operator [] tests")
{
	cout << "Operator [] tests started" << endl;
	CMyArray<int> arrInt;
	CMyArray<string> arrString;
	CMyArray<double> arrDouble;
	FillArr(arrInt, arrString, arrDouble);

	CHECK(arrInt[0] == 0);
	CHECK(arrInt[3] == 3);
	CHECK(arrString[0] == "0qwerty");
	CHECK(arrString[5] == "5qwerty");
	CHECK(arrDouble[2] == 2.5);
	CHECK(arrDouble[9] == 9.5);

}

void FillArr(CMyArray<int>& arrInt, CMyArray<string>& arrString, CMyArray<double>& arrDouble)
{
	for (int i = 0; i < 10; i++)
	{
		arrInt.Append(i);
	}
	for (int i = 0; i < 10; i++)
	{
		arrString.Append(to_string(i) + "qwerty");
	}
	for (int i = 0; i < 10; i++)
	{
		arrDouble.Append(i + 0.5);
	}
}