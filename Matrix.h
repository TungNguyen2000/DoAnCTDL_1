#pragma once
#include<iostream>
using namespace std;
class Matrix
{
private:
	int  _x, _y;
	float **_a;
	float *_b; //Phan mo cua ma tran
private:
	void GetB();
	void SubtractionRow(int r1, int r2, float n, int k);
	void SwapRow(int r1, int r2, int k);
	float DeterminantNotJI(int j, int i);
	bool IsZeroRow(int j);
public:
	void DegreeMaxTrix();
	Matrix *TransposeMatrix();
	void PrintMatrix();

	Matrix *InvertibleMatrix();

	float Determinant();

	Matrix *MultiMatrix(Matrix *_2);
	int RankOfMatrix();
	float *SolveSystemOfLinearEquations();

public:
	Matrix();
	Matrix(int y, int x);
	Matrix(float* a, int y, int x);

	~Matrix();
};

