#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;


/* tim ham Boole bang cach su dung thuat toan quine - mccluskey chi tiet: https://core.ac.uk/download/pdf/46907775.pdf*/
class BooleNum {
public:
	int number; // gia tri cua so
	bool used; // da duoc su dung hay chua
	int dashes; // am chi nhung vi tri khong ton tai bien
};

class Boole
{
private:
	vector<vector<BooleNum>> table;
	vector<int> values;
	vector<vector<BooleNum>> mid;
	vector<vector<BooleNum>> finale;
	vector<BooleNum> printTable;
	int _n;
public:
	void getinput(); // nhap gia tri input
	void print(); // in ra Ket qua cuoi cung
	Boole();
	void printBinary(int a, int d); // chuyen so thanh binary
	int count_1(int a); // dem so phan tu 1 trong day
	BooleNum initB(int in, bool use, int din); // khoi tao 1 phan tu BooleNum
	void DoAn(); // chay chuong trinh
	void midprocess(); //xu ly bang dau tien, nap Gia tri vao bang thu 2 
	void firstTable(); //nap gia tri vao bang dau tien
	void finalTable(); //nap vao bang cuoi cung
	bool duplicate(BooleNum b); // KT phan tu trung trong bang in ra
	~Boole();
};

