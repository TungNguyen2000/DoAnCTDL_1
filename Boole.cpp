#include "Boole.h"


Boole::Boole()
{
	table.resize(1);
	mid.resize(1);
	finale.resize(1);
}

Boole::~Boole()
{
}

void Boole::firstTable()
{
	for (int i = 0; i < values.size(); i++)
	{
		int tp = count_1(values[i]);
		if (tp + 1 > table.size())
			table.resize(tp + 1);
		BooleNum temp = initB(values[i], false, 0);
		table[tp].push_back(temp);
	}
}

BooleNum Boole::initB(int in, bool use, int din)
{
	BooleNum b;
	b.number = in;
	b.used = use;
	b.dashes = din;
	return b;
}

int Boole::count_1(int a)
{
	int re = 0;
	while (a > 0)
	{
		re += a % 2;
		a /= 2;
	}
	return re;
}

void Boole::getinput()
{
	int n, x;
	cout << "\nso luong phan tu nhap vao: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x > 15)
			cout << "ham chi co the nhan gia tri <= 15.";
		while (x > 15)
			cin >> x;
		values.push_back(x);
	}
}

void Boole::DoAn()
{
	getinput();
	firstTable();
	midprocess();
	finalTable();
	this->print();
}

void Boole::midprocess()
{
	int tnum, tdash;
	for (int i = 0; i < table.size() - 1; i++)
	{
		for (int j = 0; j < table[i].size(); j++)
		{
			for (int k = 0; k < table[i + 1].size(); k++)
			{
				tnum = table[i][j].number & table[i + 1][k].number; // tim giao cua 2 so
				tdash = table[i][j].number ^ table[i + 1][k].number; // vi tri khong trung nhau: 0010 ^ 0000 = 0010
				if (count_1(table[i][j].number ^ table[i + 1][k].number) == 1)
				{
					table[i][j].used = true;
					table[i + 1][k].used = true;
					int temp = count_1(tnum);
					if (temp + 1 > mid.size())
					{
						mid.resize(temp + 1);
					}
					BooleNum t = initB(tnum, false, tdash);
					mid[temp].push_back(t);
				}
			}
		}
	}
}

void Boole::finalTable()
{
	int tnum, tdas;
	for (int i = 0; i < mid.size() - 1; i++)
	{
		for (int j = 0; j < mid[i].size(); j++)
		{
			for (int t = 0; t < mid[i + 1].size(); t++)
			{
				if (mid[i][j].dashes == mid[i + 1][t].dashes)
				{
					tnum = mid[i][j].number & mid[i + 1][t].number;
					tdas = mid[i][j].number ^ mid[i + 1][t].number;
					if (count_1(tdas) == 1)
					{
						tdas ^= mid[i][j].dashes;
						mid[i][j].used = true;
						mid[i + 1][t].used = true;
						int tmp = count_1(tnum);
						if (tmp + 1 > finale.size())
							finale.resize(tmp + 1);
						BooleNum b = initB(tnum, false, tdas);
						finale[tmp].push_back(b);
					}
				}
			}
		}
	}
}

void PrintAll(int ar[], int i, int n)
{
	if (i == 0)
		cout << " ";
	if (i < 0)
		return;
	if (ar[i] != 2)
	{
		cout << ar[i];
		PrintAll(ar, i - 1, n);
	}
	else {
		ar[i] = 1;
		PrintAll(ar, n - 1, n);
		ar[i] = 0;
		PrintAll(ar, n - 1, n);
	}
}

void Boole::printBinary(int a, int d)
{
	int bits[4];
	int count = 0;
	while (a > 0 || count < 4)
	{
		if (!(d % 2))
			bits[count] = a % 2;
		else bits[count] = 2;
		a >>= 1;
		d >>= 1;
		count++;
	}

	for (int i = count - 1; i >= 0; i--)
	{
		if (bits[i] == 2)
			cout << "-";
		else cout << bits[i];
	}
}

bool Boole::duplicate(BooleNum b)
{
	for (int t = 0; t < printTable.size(); t++)
		if (b.number == printTable[t].number && b.dashes == printTable[t].dashes)
			return 1;
	return 0;
}

void Boole::print()
{
	for (int i = 0; i < finale.size(); i++)
	{
		for (int j = 0; j < finale[i].size(); j++)
		{
			if (!finale[i][j].used && !duplicate(finale[i][j]))
				printTable.push_back(finale[i][j]);
		}
	}

	for (int i = 0; i < mid.size(); i++)
	{
		for (int j = 0; j < mid[i].size(); j++)
		{
			if (!mid[i][j].used)
				printTable.push_back(mid[i][j]);
		}
	}

	for (int i = 0; i < table.size() - 1; i++)
	{
		for (int j = 0; j < table[i].size(); j++)
		{
			if (!table[i][j].used)
				printTable.push_back(table[i][j]);
		}
	}

	for (int i = 0; i < printTable.size(); i++)
	{
		printBinary(printTable[i].number, printTable[i].dashes);
		cout << " ";
	}
}