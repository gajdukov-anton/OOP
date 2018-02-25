// var2tas3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

double FindMatrixDeterminat(double mat[3][3]);
double FindElementOfMatrixOfAddition(double mat[3][3], size_t ElemX, size_t ElemY);
void FillTheMatrix(double mat[3][3], ifstream& TheMatrixFile);
void FillTheMatrixOfTheAddition(double matOfAdd[3][3], double mat[3][3]);
void ConvertMatrixOfTheAdditToInvertAndPrint(double marOfAdd[3][3], double determinantOfTheMatrix);

int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		printf("You need enter argument for correct work.\n");
		return 1;
	}

	ifstream input_file(argv[1]);

	if (!input_file.is_open())
	{
		cout << "File is not find, please check your data and repeat again.\n";
		return 1;
	}

	double matrix[3][3];
	double matrixOfAddition[3][3];
	double determinat;

	FillTheMatrix(matrix, input_file);
	determinat = FindMatrixDeterminat(matrix);

	if (determinat == 0)
	{
		cout << "Determinat is less then zero. Inverse Matrix is not available. \n";
		return 0;
	}

	FillTheMatrixOfTheAddition(matrixOfAddition, matrix);
	ConvertMatrixOfTheAdditToInvertAndPrint(matrixOfAddition, determinat);

	input_file.close();

    return 0;
}

void ConvertMatrixOfTheAdditToInvertAndPrint(double marOfAdd[3][3], double determinantOfTheMatrix)
{
	double elemOfMatrixOfAddition;
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 3; ++j)
		{
			elemOfMatrixOfAddition = marOfAdd[j][i] / determinantOfTheMatrix;
			if (elemOfMatrixOfAddition < 0.0005f && elemOfMatrixOfAddition > -0.0005f)
			{
				elemOfMatrixOfAddition = 0.000f;
			}
			marOfAdd[j][i] = elemOfMatrixOfAddition;
			printf("%.3f", marOfAdd[j][i]);
			cout << ' ';
		}
		cout << endl;
	}
}

void FillTheMatrixOfTheAddition(double matOfAdd[3][3], double mat[3][3])
{
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 3; ++j)
		{
			matOfAdd[i][j] = FindElementOfMatrixOfAddition(mat, j, i);
		}
	}
}

void FillTheMatrix(double mat[3][3], ifstream& TheMatrixFile)
{
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 3; ++j)
		{
			TheMatrixFile >> mat[i][j];
		}

	}
}

double FindMatrixDeterminat(double mat[3][3])
{
	double result = 0;
	double paramOne;
	double paramTwo;
	paramOne = mat[0][0] * mat[1][1] * mat[2][2] + mat[0][1] * mat[1][2] * mat[2][0] + mat[0][2] * mat[1][0] * mat[2][1];
	paramTwo = mat[0][2] * mat[1][1] * mat[2][0] + mat[0][1] * mat[1][0] * mat[2][2] + mat[0][0] * mat[1][2] * mat[2][1];
	result = paramOne - paramTwo;
	return result;
}

double FindElementOfMatrixOfAddition(double mat[3][3], size_t minorCoordinateX, size_t minorCoordinateY)
{
	double minor[2][2];
	double result = 0;
	int matrixOfAdditionCoordinateX = 0;
	int matrixOfAdditionCoordinateY = 0;

	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 3; ++j)
		{
			if (i != minorCoordinateY && j != minorCoordinateX)
			{
				minor[matrixOfAdditionCoordinateY][matrixOfAdditionCoordinateX] = mat[i][j];
				++matrixOfAdditionCoordinateX;
			}
			if (matrixOfAdditionCoordinateX == 2)
			{
				matrixOfAdditionCoordinateX = 0;
				++matrixOfAdditionCoordinateY;
			}
		}
	}

	double multiplier = 1.0f;
	if ((minorCoordinateY + minorCoordinateX) % 2 != 0)
		multiplier = -1.0f;
	result = multiplier * (minor[0][0] * minor[1][1] - minor[0][1] * minor[1][0]);

	return result;
}