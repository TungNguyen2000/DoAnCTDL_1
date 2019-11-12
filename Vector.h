#pragma once
#include<iostream>

using namespace std;

class Vector
{
	int n;
	double* vc;
public:
	Vector();
	Vector(const Vector &t);
	Vector(int size, double value);
	Vector& operator=(const Vector &t);
	Vector operator+(const Vector &b);
	Vector& operator+=(const Vector &b);
	Vector operator*(int a);
	Vector& operator*=(int b);
	friend istream& operator>> (istream &is, Vector &v);
	friend ostream&operator<<(ostream&os, Vector&v);
	void Nhap();
	~Vector();
	void print();
};

