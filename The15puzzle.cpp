#include <iostream>
using namespace std;
#include<windows.h>
#include <ctime>
void DrawField(short array[4][4], int counter)
{
	short* zero = &array[0][0];
	char move;
	bool flag = true;
	cout << "\t   Всего ходов: " << counter << endl << endl;

	for (short i = 0; i < 4; i++)
	{
		cout << "  " << char(124)<<" ";
		for (short j = 0; j < 4; j++)
		{
			if (array[i][j] / 10 == 0)cout << " ";
			if (array[i][j] == 0)
			{
				cout << "  ";
				zero = &array[i][j];
			}
			else cout << array[i][j] << " ";
			if ((array[i][j] != (j + 1 + 4 * i))&&(!(i==3&&j==3)))flag = false;
		}

		cout  << char(124) << " ";
		if (i == 0) cout << "Введите действие:" << endl << endl;
		else if (i == 1) cout << "        " << char(30) << endl << "                          8" << endl;
		else if (i == 2) cout << "   " << char(17) << " 4     6 " << char(16) << endl << "                          2" << endl;
		else if (i == 3) cout << "        " << char(31) << endl;
	}
	cout << endl;
	if (flag == false)
	{
		cin >> move;
		if (move == '8' && zero + 4 >= &array[0][0] && zero + 4 <= &array[3][3])swap(*zero, *(zero + 4));
		else if (move == '4' && zero + 1 >= &array[0][0] && zero + 1 <= &array[3][3] && zero + 1 != &array[1][0] && zero + 1 != &array[2][0] && zero + 1 != &array[3][0])swap(*zero, *(zero + 1));
		else if (move == '6' && zero - 1 >= &array[0][0] && zero - 1 <= &array[3][3] && zero - 1 != &array[1][3] && zero - 1 != &array[2][3] && zero - 1 != &array[3][3])swap(*zero, *(zero - 1));
		else if (move == '2' && zero - 4 >= &array[0][0] && zero - 4 <= &array[3][3])swap(*zero, *(zero - 4));
		else
		{
			cout << "Ошибка ввода";
			Sleep(1500);
			move = char(2);
		}
		std::system("cls");

		if (move == char(2))DrawField(array, counter);
		else DrawField(array, counter + 1);
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	std::system("mode con cols=38 lines=13");
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
	cout << "\n\n\n\n       П  Я  Т  Н  А  Ш  К  И\n\n\n\n";
	std::system("pause");
	std::system("cls");
	int counter = 0;
	short field[4][4]{}, insert;
	bool flag;
	for (short i = 1; i < 16; i++)
	{
		flag = false;
		insert = 1 + rand() % 15;
		for (short j = 0; j < 4; j++)
		{
			if (flag == true) break;
			for (short k = 0; k < 4; k++)
			{
				if (field[j][k] == 0)
				{
					field[j][k] = insert;
					flag = true;
					break;
				}
				else if (field[j][k] != insert)continue;
				else if (insert != 15)
				{
					insert++;
					j = -1;
					break;
				}
				else insert = 1;
			}
		}
	}
	swap(field[3][3], field[rand() % 4][rand() % 4]);

	//Debug mode
	//int n = 1;
	//for (short i = 0; i < 4; i++)
	//{
	//	for (short j = 0; j < 4; j++, n++)
	//	{
	//		field[i][j] = n;
	//	}
	//}
	//field[3][3] = 15;
	//field[3][2] = 0;


	DrawField(field, counter);
	cout << "\aПоздравляю!" << endl << "Вам удалось решить эту головоломку!";
	Sleep(10000);
	std::system("cls");
}
