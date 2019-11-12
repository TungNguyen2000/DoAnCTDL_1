#include "Vector.h"



Vector::Vector()
{
	vc = NULL;
	n = 0;
}

Vector::Vector(int size, double value)
{
	n = size;
	vc = new double[n];
	for (int j = 0; j < n; j++)
		vc[j] = value;
}

Vector::Vector(const Vector &t)
{
	vc = new double[t.n];
	n = t.n;
	vc = t.vc;
}

Vector::~Vector()
{
	delete[] vc;
}

Vector& Vector::operator=(const Vector &t)
{
	if (this->vc != NULL)
		delete[] this->vc;
	this->vc = new double[t.n];
	this->n = t.n;
	for (int i = 0; i < n; i++)
		this->vc[i] = t.vc[i];
	return *this;
}

Vector Vector::operator+(const Vector &b)
{
	if (this->n != b.n)
	{
		cout << "Two vectors have to have the same length. \n";
		return *this;
	}
	Vector result(b);
	for (int i = 0; i < n; i++)
		result.vc[i] += this->vc[i];
	return result;
}

Vector Vector::operator*(int a)
{
	Vector r;
	r.n = n;
	r.vc = new double[n];
	for (int i = 0; i < n; i++)
		r.vc[i] = vc[i] * a;
	return r;
}

Vector& Vector::operator+=(const Vector &b)
{
	if (b.n != this->n)
	{
		cout << "Invalid length";
		return *this;
	}
	for (int i = 0; i < n; i++)
		vc[i] = vc[i] + b.vc[i];
	return *this;
}

Vector& Vector::operator*=(int b)
{
	for (int i = 0; i < n; i++)
		vc[i] = vc[i] * b;
	return *this;
}

void Vector::print()
{
	for (int j = 0; j < n; j++)
		cout << vc[j] << " ";
	cout << endl;
}

void Vector::Nhap()
{
	int _n;
	cout << "\nSo phan tu cua vector: "; 
	cin >> _n;
	vc = new double[_n];
	n = _n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu " << i << ":";
		cin >> vc[i];
	}
	
}

istream& operator>> (istream &is, Vector &v)
{
	cout << "\nso phan tu cua vector: "; cin >> v.n;
	v.vc = new double[v.n];
	for (int i = 0; i < v.n; i++)
	{
		is >> v.vc[i];
	}
	return is;
}

ostream& operator<<(ostream& os, Vector& v)
{
	for (int j = 0; j < v.n; j++)
		os << v.vc[j] << " ";
	return os;
}