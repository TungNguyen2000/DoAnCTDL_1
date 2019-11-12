#include "App.h"

void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

int App()
{
	Intro();
	int h, chon = 1, choncu = 0;
	while (1)
	{
		if (_kbhit())
		{
			h = _getch();
			if (h == 13 || h == 8)
			{
				return chon;
			}

			if (h == 72)
			{
				if (chon != 1)
				{
					choncu = chon;
					chon--;
				}
				BangChon(chon, choncu);
			}

			if (h == 80)
			{
				if (chon != 4)
				{
					choncu = chon;
					chon++;
				}
				BangChon(chon, choncu);
			}
		}
		gotoxy(0, 20);
	}
}

int BangChon(int chon, int choncu)
{
	if (chon == 1)
	{
		if (choncu == 2)
		{
			gotoxy(22, 11); cout << "  ";
		}

		gotoxy(22, 10); cout << "|>";
	}

	else if (chon == 2)
	{
		if (choncu == 1)
		{
			gotoxy(22, 10); cout << "  ";
		}
		if (choncu == 3)
		{
			gotoxy(22, 12); cout << "  ";
		}
		gotoxy(22, 11); cout << "|>";

	}

	else if (chon == 3)
	{
		if (choncu == 2)
		{
			gotoxy(22, 11); cout << "  ";
		}
		if (choncu == 4)
		{
			gotoxy(22, 13); cout << "  ";
		}
		gotoxy(22, 12); cout << "|>";
	}
	else {
		gotoxy(22, 12); cout << "  ";
		gotoxy(22, 13); cout << "|>";
	}
	return 1;
}

int Intro()
{
	system("cls");
	gotoxy(17, 4); cout << " ____  _____       __   __        ___  _______ ____         " << endl;
	gotoxy(17, 5); cout << "|    \\/     \\     /  \\  | \\  |   /   \\    |   |    \\ |      " << endl;
	gotoxy(17, 6); cout << "|    ||      |   /____\\ |  \\ |   |        |   |     ||      " << endl;
	gotoxy(17, 7); cout << "|___ /\\_____/   /      \\|   \\|   \\___/    |   |___ / |____  " << endl;

	gotoxy(23, 9); cout << "Chon Chuc Nang Tinh Toan: ";
	gotoxy(23, 10); cout << "        Ham Boole        ";
	gotoxy(23, 11); cout << "         Ma Tran         ";
	gotoxy(23, 12); cout << "          Vector         ";
	gotoxy(23, 13); cout << "          Thoat          ";
	BangChon(1, 0);
	return 0;
}