#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string CheckStrForShape(string strForCheck);
bool FillVertex(istream& input,vector<double>& vectorOfVertex, size_t amountOfVertex);
void FillColors(istream& input, string& outlineColor, string& fillColor);