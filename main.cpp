#include "App.h"

int main()
{
	while (1) {
	int flag=0;
	int n = App();
	system("cls");
	switch (n)
	{
	case 1:
	{
		cout << "Ham Boole. " << endl << " Nhan r de thoat." << endl << "Nhap phim bat ki de tiep tuc" << endl;
		while (1)
		{
			if (_kbhit())
			{
				int h = _getch();
				if (h == 114)
					break;
				else {
					Boole boo;
					boo.DoAn();
				}
				cout << "Nhap 0 de thoat !" << endl;
				cout << "Nhap 1 de hien Menu" << endl;
				int o;
				cin >> o;
				if (o == 0)
					break;
				else
					if (o == 1)
					{
						flag = 1;
						break;
					}
			}
		}
		if (flag)
		{
			flag = 0;
			continue;
		}
		break;
	}
	case 2:
	{
		cout << "Su dung Matrix."<<endl<<" Nhan r de thoat." << endl << "Nhap phim bat ki de tiep tuc" << endl;
		while (1)
		{
		
			if (_kbhit())
			{
				int h = _getch();
				if (h == 114)
					break;
				else 
				{
					Matrix matran1, matran2;
					cout << "Matran 1 la" << endl;
					matran1.PrintMatrix();
					cout << "**********************" << endl;
					cout << endl;
					cout << "Matran 2 la" << endl;
					matran2.PrintMatrix();
					cout << "**********************" << endl;
					cout << endl;
					cout << "Dinh thuc la " << matran1.Determinant() << endl;
					matran1.MultiMatrix(&matran2);
					cout << "**********************" << endl;
					cout << endl;
					cout << "Hang cua tran la " << matran1.RankOfMatrix() << endl;
					cout << "**********************" << endl;
					cout << endl;
					matran1.PrintMatrix();
					try {
						float *p = matran1.SolveSystemOfLinearEquations();
						cout << "nghiem" << endl;
						for (int i = 0; i < 3; i++) {
							cout << p[i] << endl;
						}
					}
					catch (const char* exception) {
						cout << exception << endl;
					}
					cout << "Nhap 0 de thoat !" <<endl;
					cout << "Nhap 1 de hien Menu" << endl;
					int o;
					cin >> o;
					if (o == 0)
						break;
					else
						if (o == 1)
						{
							flag = 1;
							break;
						}
				}
			}
		}
		if (flag)
		{ 
			flag = 0;
			continue; 
		}
		break;
	}
	case 3:
	{
		cout << "Vector. "<<endl<<" Nhan r de thoat." << endl << "Nhap phim bat ki de tiep tuc" << endl;
		while (1)
		{
			if (_kbhit())
			{
				int h = _getch();
				if (h == 114)
					break;
				else {
					Vector v1;
					int n, a;
					cout <<" 1/Cong 2 vector"<<endl<< " 2/Nhan vector voi 1 so" <<endl;
					cout << " Nhap: " << endl;
					cin >> a;
					switch (a)
					{
					case 1:
					{
						Vector v2;
						v1.Nhap(); v2.Nhap();
						v1 += v2;
						v1.print(); break;
					}
					case 2:
					{
						v1.Nhap();
						cin >> n;
						v1 *= n;
						v1.print();
					}
					}
					cout << "Nhap 0 de thoat !" << endl;
					cout << "Nhap 1 de hien Menu" << endl;
					int o;
					cin >> o;
					if (o == 0)
						break;
					else
						if (o == 1)
						{
							flag = 1;
							break;
						}
				}
			}
		}
		if (flag)
		{
			flag = 0;
			continue;
		}
		break;
	}
	default:
		return 0;
	}
	}
	return 0;
}