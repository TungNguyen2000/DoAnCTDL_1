#include "Matrix.h"



//Nhap cac phan tu mo rong cua ma tran
void Matrix::GetB()
{
	_b = new float[_y];
	cout << "Nhap cac phan tu cua phan mo rong cua ma tran" << endl;
	for (int i = 0; i < _y; i++) {
		cin >> _b[i];
	}
}
//Lay hang r1 tru cho n lan hang r2
void Matrix::SubtractionRow(int r1, int r2, float n, int k)
{
	for (int j = k; j < _x; j++) {
		_a[r1][j] -= n * _a[r2][j];
	}
}
//doi vi tri hang r1 va r2
void Matrix::SwapRow(int r1, int r2, int k)
{
	float temp;
	for (int j = k; j < _x; j++) {
		temp = _a[r2][j];
		_a[r2][j] = _a[r1][j];
		_a[r1][j] = temp;
	}


}
// chuyen ma tran thanh ma tran bac thang
void Matrix::DegreeMaxTrix()
{
	int j = 0, i = 0;
	while (j < _x - 1 && i < _y - 1) {
		while (1) {
			if (_a[i][j]) {
				for (int k = i + 1; k < _y; k++) {
					float n = _a[k][j] / _a[i][j];
					SubtractionRow(k, i, n, j);

				}
				i++; j++;
				break;
			}
			else {
				int flag = 0;
				for (int k = i + 1; k < _y; k++) {
					if (_a[k][j]) {
						SwapRow(i, k, j); flag = 1; break;
					}
				}
				if (flag == 0) { j++; break; }
			}

		}
	}
}
//tra ve ma tran chuyen vi
Matrix *Matrix::TransposeMatrix()
{
	Matrix *temp = new Matrix(_x, _y);
	for (int j = 0; j < _y; j++) {
		for (int i = 0; i < _x; i++) {
			temp->_a[i][j] = _a[j][i];
		}
	}
	return temp;
}
//ham xuat ma tran
void Matrix::PrintMatrix()
{
	for (int j = 0; j < _y; j++) {
		for (int i = 0; i < _x; i++) {
			cout.width(6);
			cout << _a[j][i];
		}
		cout << endl;
	}
}
//tra ve ma tran nghich dao
Matrix *Matrix::InvertibleMatrix()
{
	if (_x != _y) { throw "Can not take InvertibleMatrix"; }
	float DetA = Determinant();
	if (!DetA) { throw "Can not take InvertibleMatrix"; }
	Matrix *temp = new Matrix(_x, _y);
	for (int j = 0; j < _x; j++) {
		for (int i = 0; i < _y; i++) {
			temp->_a[j][i] = TransposeMatrix()->DeterminantNotJI(j, i) / DetA;
		}
	}
	return temp;
}
// tinh dinh thuc cua ma tran
float Matrix::Determinant()
{
	Matrix temp(_y, _x);
	for (int j = 0; j < _y; j++) {
		for (int i = 0; i < _x; i++) {
			temp._a[j][i] = _a[j][i];
		}
	}
	temp.DegreeMaxTrix();
	try {
		if (_x != _y) { throw "Can not take Determinant"; return -1; }
	}
	catch (const char* exception)
	{
		std::cerr << "Error: " << exception << '\n';
	}
	if (_x == 1) { return temp._a[0][0]; }
	if (_x == 2) { return temp._a[0][0] * temp._a[1][1] - temp._a[1][0] * temp._a[0][1]; }

	float multi = 1;
	for (int i = 0; i < _x; i++) {
		multi *= temp._a[i][i];
	}
	return multi;
}
// tinh dinh thuc cua  ma tran phu hop hang j cot i
float Matrix::DeterminantNotJI(int row, int col)
{
	Matrix temp(_y - 1, _x - 1);
	for (int j = 0, j2 = 0; j < _y; j++, j2++) {
		if (j == row) { j2--; continue; }
		for (int i = 0, i2 = 0; i < _x; i++, i2++) {
			if (i == col) { i2--; continue; }
			temp._a[j2][i2] = _a[j][i];
		}
	}
	return temp.Determinant();
}

bool Matrix::IsZeroRow(int j)
{
	for (int i = 0; i < _x; i++) {
		if (_a[j][i] != 0) { return false; }
	}
	return true;
}
// nhan hai ma tran
Matrix *Matrix::MultiMatrix(Matrix *_2)
{
	try {
		if (_x != _2->_y) { throw "Can not multi Matrix"; }
	}
	catch (const char* exception)
	{
		cerr << "Error: " << exception << '\n';
	}
	Matrix *_3 = new Matrix(_y, _2->_x);
	float sum;
	for (int i = 0; i < _y; i++) {
		for (int j = 0; j < _2->_x; j++) {
			sum = 0;
			for (int k = 0; k < _x; k++) {
				sum += _a[i][k] * _2->_a[k][j];
			}
			_3->_a[i][j] = sum;
		}
	}
	cout << "Tich 2 ma tran la " << endl;
	_3->PrintMatrix();
	cout << endl;
	return _3;
}
// tim hang cua ma tran
int Matrix::RankOfMatrix()
{
	Matrix temp(_y, _x);
	for (int j = 0; j < _y; j++) {
		for (int i = 0; i < _x; i++) {
			temp._a[j][i] = _a[j][i];
		}
	}
	temp.DegreeMaxTrix();
	temp.PrintMatrix();
	int count = 0;
	for (int j = 0; j < _y; j++) {
		if (temp.IsZeroRow(j) == false) { count++; }
		else { break; }
	}
	return count;
}
// giai he phuong trinh tuyen tinh
float *Matrix::SolveSystemOfLinearEquations()
{
	GetB();
	float *result = new float[_x];
	Matrix temp(_y, _x);
	for (int j = 0; j < _y; j++) {
		for (int i = 0; i < _x; i++) {
			temp._a[j][i] = _a[j][i];
		}
	}
	float DetA = Determinant();
	float *temp2 = new float[_y];
	for (int k = 0; k < _x; k++) {
		for (int j = 0; j < _y; j++) {
			temp2[j] = temp._a[j][k];
			temp._a[j][k] = _b[j];

		}
		float DetB = temp.Determinant();
		if (DetA == 0 && DetB != 0) { throw "Phuong trinh vo nghiem"; return nullptr; }
		if (DetA == 0 && DetB == 0) { throw "Phuong trinh vo so nghiem"; }

		result[k] = DetB / DetA;
		for (int j = 0; j < _y; j++) {
			temp._a[j][k] = temp2[j];
		}
	}
	return result;
}
Matrix::Matrix()     //ham tao ma tran
{
	cout << "moi ban nhap so dong ma tran" << endl;
	cin >> _y;
	cout << "moi ban nhap so cot ma tran" << endl;
	cin >> _x;
	_a = new float*[_y];
	for (int i = 0; i < _y; i++) {
		_a[i] = new float[_x];
	}
	for (int j = 0; j < _y; j++) {
		for (int i = 0; i < _x; i++) {
			cout << "nhap phan tu dong" << j << " cot" << i << endl;
			cin >> _a[j][i];
		}
	}
}
Matrix::Matrix(int y, int x)     //ham tao ma tran
{
	this->_x = x;
	this->_y = y;

	_a = new float*[y];
	for (int i = 0; i < y; i++) {
		_a[i] = new float[x];
	}

}

Matrix::Matrix(float* a, int y, int x)
{
	this->_x = x;
	this->_y = y;
	_a = new float*[y];
	for (int j = 0; j < y; j++) {
		_a[j] = new float[x];
		for (int i = 0; i < x; i++) {
			_a[j][i] = *(a + j * x + i);
		}
	}

}

Matrix::~Matrix()
{
	delete _a;
	delete _b;
}
