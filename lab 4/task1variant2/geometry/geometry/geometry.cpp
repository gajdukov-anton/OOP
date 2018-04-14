// geometry.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "CGeometry.h"

using namespace std;

int main()
{
	ifstream inputFile("test2.txt");
	CGeometry geometry(cin, cout);
	while (!cin.eof())
	{
		geometry.HandleCommand();
	}
	geometry.GetMaxShape();
	geometry.GetMinShape();
    return 0;
}

