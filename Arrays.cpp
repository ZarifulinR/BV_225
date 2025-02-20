﻿// Arrays.cpp 

#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
const int line = 4;//строка
const int colum = 10;//столбец

enum Color { Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };
enum Direction { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, esc = 27, spase = 32 };
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);//получает дискриптор активного окна

void SetColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void SetCursor(int x, int y)
{
	COORD myCoords = { x,y };//инициализируем передаваемыми значениями объект координат
	SetConsoleCursorPosition(hStdOut, myCoords);
}
int menu();
int menu2();
//Объявление одинарного массива Рандом
void FillRand(int mas[], int n, int a, int b);
void FillRand(double mas[], int n, int a, int b);
void FillRand(float mas[], int n, int a, int b);
void FillRand(char mas[], int n, int a, int b);
//Объявление двойного массива Рандом 
void FillRand(int mas[line][colum], int n, int a);
void FillRand(double mas[line][colum], int n, int a);
void FillRand(float mas[line][colum], int n, int a);
void FillRand(char mas[line][colum], int n, int a);
//Объвявление одинарного массива Рисовка
template <typename T> void Prit(T mas[], int n);


//Объявление двойного массива Рисовка
template <typename T>void Print(T mas[line][colum], int n, int a);

//Объявление Одинарного массива Сумма 
template <typename T>T Sum(T mas[], int n);

//Объявление Одинарного массива Сумма
template <typename T>T Sum(T mas[line][colum], int n, int a);

//Объявление Одинарного массива Среднее значение
template <typename T>T Avg(T Sum, int n);

//Объявление двойного массива Среднее значение
template <typename T>T Avg(T Sum, int n, int a);

//Объявление Одинарного массива Мин значение
template <typename T>T minValueln(T mas[], int n);

//Объявление двойного массива Мин значение
template <typename T>T minValueln(T mas[line][colum], int n, int a);

//Объявление Одинарного массива Макс значение
template <typename T>T maxValueln(T mas[], int n);

//Объявление двойного массива Макс значение
template <typename T>T maxValueln(T mas[line][colum], int n, int a);

//Объявление Одинарного массива Сортировка
template <typename T>void Sort(T mas[], int n);

//Объявление двойного массива Сортировка
template <typename T>void Sort(T mas[line][colum], int n, int a);

//Объявление Одинарного массива Уникальн Рандом
void UniqueRand(int mas[], int n, int a, int b);
double UniqueRand(double mas[], int n, int a, int b);
float UniqueRand(float mas[], int n, int a, int b);
char UniqueRand(char mas[], int n, int a, int b);
//Объявление двойного массива Уникальный Рандом
void UniqueRand(int mas[line][colum], int n, int a);
void UniqueRand(double mas[line][colum], int n, int a);
void UniqueRand(float mas[line][colum], int n, int a);
void UniqueRand(char mas[line][colum], int n, int a);
//Объявление Одинарного массива Повторение
template <typename T>void Search(T mas[], int n);

//Объявление двойного массива Повторение
template <typename T>void Search(T mas[line][colum], int n, int a);

//Объявление Сдвиг одинарного массива
void Shift_Left_And_Right(int mas[], int n);
//Объявление Сдвиг двойного массива
void Shift_Left_And_Right(int mas[line][colum], int n, int a);


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RUS");
	const int n = 10;
	int mas[n];
	double mas_d[n];
	float mas_f[n];
	char mas_ch[n];
	int arr[line][colum];
	double arr_d[line][colum];
	float arr_f[line][colum];
	char arr_ch[line][colum];

	int a = 0, b = 10;



	int poz = 0, poz2 = 0;
	int key;
	SetColor(LightBlue, Black);//Заставка
	/*for (int i = -10 + 1; i < 10; i++)
	{

		for (int j = -10 + 1; j < 10; j++)
		{
			if (abs(j) + 1 >= 10 - abs(i))
			{
				cout << (char)(64 + (10 - abs(j))) << " ";
			}
			else
			{
				cout << "  ";
			}
			Sleep(1);
		}

		cout << endl;
	}*/
	SetColor(White, Black);
	Sleep(200);
	do
	{
		system("cls");
		poz = menu();
		system("cls");
		switch (poz)
		{
		case 1:
		{
			system("cls");
			poz2 = menu2();
			switch (poz2)
			{
			case 0:
			{
				Shift_Left_And_Right(mas, n);
				break;
			}
			case 1:
			{
				Shift_Left_And_Right(arr, line, colum);
				break;
			}
			default:
			{
				break;
			}

			}


			/*const int n = 10;
			int mas[n];
			int size = 0;
			for (int i = 0; i < 10; i++)
			{

				mas[i] = i + 1;
				cout << mas[i] << "\t";
			}

			do {
				system("cls");

				for (int i = 0; i < 10; i++)
				{


					cout << mas[i] << "\t";
				}

				cout << endl;
				cout << "Нажмите Enter для выхода";



				key = _getch();
				switch (key)
				{
				case Left:
				{
					size--;
					break;
				}
				case Right:
				{
					size++;
					break;
				}
				case Enter:
				{
					break;
				}

				}
				if (size < 0)
				{
					size = 9;
				}
				if (size > 9 && key == Right)
				{
					size = 0;
				}
				size = n - size;
				for (int i = 0; i < size; i++)
				{
					int d = mas[0];
					for (int i = 0; i < n; i++)
					{

						mas[i] = mas[i + 1];

					}
					mas[n - 1] = d;
				}


			} while (key != Enter);*/
			break;
		}

		case 0:
		{
			do {
				system("cls");
				//cout << "Введите диапазон от "; cin >> a; cout << " до "; cin >> b;

				system("cls");
				FillRand(mas, n, a, b);
				FillRand(mas_d, n, a, b);
				FillRand(mas_f, n, a, b);
				FillRand(mas_ch, n, a, b);

				FillRand(arr, line, colum);
				FillRand(arr_d, line, colum);
				FillRand(arr_f, line, colum);
				FillRand(arr_ch, line, colum);
				SetColor(Red, Black);
				cout << "------------------------------Одномерный массив--------------------------------\n";
				//SetColor(White, Black);
				Prit(mas, n);
				cout << endl;
				Prit(mas_d, n);
				cout << endl;
				Prit(mas_f, n);
				cout << endl;
				Prit(mas_ch, n);
				SetColor(LightBlue, Black);
				cout << "\n------------------------------Двумерный массив--------------------------------\n";

				Print(arr, line, colum);
				cout << "\n-----------------------------------|double|-----------------------------------\n";
				Print(arr_d, line, colum);
				cout << "\n-----------------------------------|float|------------------------------------\n";
				Print(arr_f, line, colum);
				cout << "\n------------------------------------|char|------------------------------------\n";
				Print(arr_ch, line, colum);
				SetColor(Red, Black);
				cout << "\n---------Сумма одномерных массивов----------\n";


				cout << endl << "[" << Sum(mas, n) << "]" << " |int|";
				cout << "\n--------------------------------------------\n";
				cout << endl << "[" << Sum(mas_d, n) << "]" << " |double|";
				cout << "\n--------------------------------------------\n";
				cout << endl << "[" << Sum(mas_f, n) << "]" << " |float|";
				cout << "\n--------------------------------------------\n";
				cout << endl << "[" << Sum(mas_ch, n) << "]" << " |char|";
				SetColor(LightBlue, Black);
				cout << "\n----------Сумма двумерных массивов----------\n";
				cout << endl << "[" << Sum(arr, line, colum) << "]" << " |int|";
				cout << "\n--------------------------------------------\n";
				cout << endl << "[" << Sum(arr_d, line, colum) << "]" << " |double|";
				cout << "\n--------------------------------------------\n";
				cout << endl << "[" << Sum(arr_f, line, colum) << "]" << " |float|";
				cout << "\n--------------------------------------------\n";
				cout << endl << "[" << Sum(arr_ch, line, colum) << "]" << " |char|";
				SetColor(Red, Black);
				cout << "\n--------Среднее значение одномерного--------\n";

				cout << endl << "[" << Avg(Sum(mas, n), n) << "]" << " |int|";
				cout << "\n--------------------------------------------\n";
				cout << endl << "[" << Avg(Sum(mas_d, n), n) << "]" << " |double|";
				cout << "\n--------------------------------------------\n";
				cout << endl << "[" << Avg(Sum(mas_f, n), n) << "]" << " |float|";
				cout << "\n--------------------------------------------\n";
				cout << endl << "[" << Avg(Sum(mas_ch, n), n) << "]" << " |char|";
				SetColor(LightBlue, Black);
				cout << "\n---------Среднее значение двумерного--------\n";

				cout << endl << "[" << Avg(Sum(arr, line, colum), line, colum) << "]" << " |int|";
				cout << "\n--------------------------------------------\n";
				cout << endl << "[" << Avg(Sum(arr_d, line, colum), line, colum) << "]" << " |double|";
				cout << "\n--------------------------------------------\n";
				cout << endl << "[" << Avg(Sum(arr_f, line, colum), line, colum) << "]" << " |float|";
				cout << "\n--------------------------------------------\n";
				cout << endl << "[" << Avg(Sum(arr_ch, line, colum), line, colum) << "]" << " |char|";
				SetColor(Red, Black);
				cout << "\n--------Минимальное значение одномерного--------\n";

				cout << endl << "[" << minValueln(mas, n) << "]" << " |int|";
				cout << "\n--------------------------------------------\n";
				cout << endl << "[" << minValueln(mas_d, n) << "]" << " |double|";
				cout << "\n--------------------------------------------\n";
				cout << endl << "[" << minValueln(mas_f, n) << "]" << " |float|";
				cout << "\n--------------------------------------------\n";
				cout << endl << "[" << minValueln(mas_ch, n) << "]" << " |char|";
				SetColor(LightBlue, Black);
				cout << "\n-------Минимальное значение двумерного------\n";

				cout << endl << "[" << minValueln(arr, line, colum) << "]" << " |int|";
				cout << "\n--------------------------------------------\n";
				cout << endl << "[" << minValueln(arr_d, line, colum) << "]" << " |double|";
				cout << "\n--------------------------------------------\n";
				cout << endl << "[" << minValueln(arr_f, line, colum) << "]" << " |float|";
				cout << "\n--------------------------------------------\n";
				cout << endl << "[" << minValueln(arr_ch, line, colum) << "]" << " |char|";
				SetColor(Red, Black);
				cout << "\n-------Максимальное значение одномерного------\n";

				cout << endl << "[" << maxValueln(mas, n) << "]" << " |int|";
				cout << "\n--------------------------------------------\n";
				cout << endl << "[" << maxValueln(mas_d, n) << "]" << " |double|";
				cout << "\n--------------------------------------------\n";
				cout << endl << "[" << maxValueln(mas_f, n) << "]" << " |float|";
				cout << "\n--------------------------------------------\n";
				cout << endl << "[" << maxValueln(mas_ch, n) << "]" << " |char|";
				SetColor(LightBlue, Black);
				cout << "\n-------Максимальное значение двумерного------\n";

				cout << endl << "[" << maxValueln(arr, line, colum) << "]" << " |int|";
				cout << "\n--------------------------------------------\n";
				cout << endl << "[" << maxValueln(arr_d, line, colum) << "]" << " |double|";
				cout << "\n--------------------------------------------\n";
				cout << endl << "[" << maxValueln(arr_f, line, colum) << "]" << " |float|";
				cout << "\n--------------------------------------------\n";
				cout << endl << "[" << maxValueln(arr_ch, line, colum) << "]" << " |char|";
				cout << "\n--------------------------------------------\n";
				SetColor(White, Black);

				cout << "\nESC-для Выхода";
				key = _getch();
			} while (key != esc);
			break;

		}

		case 2:
		{
			do {
				system("cls");
				SetColor(Red, Black);
				cout << "------------------------------Одномерный массив--------------------------------\n";
				//SetColor(White, Black);
				Prit(mas, n);
				cout << endl;
				Prit(mas_d, n);
				cout << endl;
				Prit(mas_f, n);
				cout << endl;
				Prit(mas_ch, n);
				SetColor(LightBlue, Black);
				cout << "\n------------------------------Двумерный массив--------------------------------\n";

				Print(arr, line, colum);
				cout << "\n-----------------------------------|double|-----------------------------------\n";
				Print(arr_d, line, colum);
				cout << "\n-----------------------------------|float|------------------------------------\n";
				Print(arr_f, line, colum);
				cout << "\n------------------------------------|char|------------------------------------\n";
				Print(arr_ch, line, colum);


				Sort(mas, n);
				Sort(mas_d, n);
				Sort(mas_f, n);
				Sort(mas_ch, n);

				Sort(arr, line, colum);
				Sort(arr_d, line, colum);
				Sort(arr_f, line, colum);
				Sort(arr_ch, line, colum);

				SetColor(Red, Black);
				cout << "------------------------------Одномерный массив--------------------------------\n";
				//SetColor(White, Black);
				Prit(mas, n);
				cout << endl;
				Prit(mas_d, n);
				cout << endl;
				Prit(mas_f, n);
				cout << endl;
				Prit(mas_ch, n);
				SetColor(LightBlue, Black);
				cout << "\n------------------------------Двумерный массив--------------------------------\n";

				Print(arr, line, colum);
				cout << "\n-----------------------------------|double|-----------------------------------\n";
				Print(arr_d, line, colum);
				cout << "\n-----------------------------------|float|------------------------------------\n";
				Print(arr_f, line, colum);
				cout << "\n------------------------------------|char|------------------------------------\n";
				Print(arr_ch, line, colum);
				SetColor(White, Black);
				cout << "\nESC-для Выхода";
				key = _getch();
			} while (key != esc);
			break;
		}

		case 3:
		{
			do {
				system("cls");
				//cout << "Введите диапазон от "; cin >> a; cout << "до "; cin >> b;
				system("cls");

				UniqueRand(mas, n, a, b);
				UniqueRand(mas_d, n, a, b);
				UniqueRand(mas_f, n, a, b);
				UniqueRand(mas_ch, n, a, b);

				UniqueRand(arr, line, colum);
				UniqueRand(arr_d, line, colum);
				UniqueRand(arr_f, line, colum);
				UniqueRand(arr_ch, line, colum);

				SetColor(Red, Black);
				cout << "------------------------------Одномерный массив--------------------------------\n";
				//SetColor(White, Black);
				Prit(mas, n);
				cout << endl;
				Prit(mas_d, n);
				cout << endl;
				Prit(mas_f, n);
				cout << endl;
				Prit(mas_ch, n);
				SetColor(LightBlue, Black);
				cout << "\n------------------------------Двумерный массив--------------------------------\n";

				Print(arr, line, colum);
				cout << "\n-----------------------------------|double|-----------------------------------\n";
				Print(arr_d, line, colum);
				cout << "\n-----------------------------------|float|------------------------------------\n";
				Print(arr_f, line, colum);
				cout << "\n------------------------------------|char|------------------------------------\n";
				Print(arr_ch, line, colum);
				SetColor(White, Black);
				cout << "\nESC-для Выхода";
				key = _getch();
			} while (key != esc);
			break;
		}
		case 4:
		{
			do
			{
				system("cls");
				FillRand(mas, n, a, b);
				FillRand(mas_d, n, a, b);
				FillRand(mas_f, n, a, b);
				FillRand(mas_ch, n, a, b);
				FillRand(arr, line, colum);
				FillRand(arr_d, line, colum);
				FillRand(arr_f, line, colum);
				FillRand(arr_ch, line, colum);
				SetColor(Red, Black);
				cout << "------------------------------Одномерный массив--------------------------------\n";
				Prit(mas, n);
				Search(mas, n);
				cout << "\n" << endl;
				cout << "\n-----------------------------------|double|-----------------------------------\n";
				Prit(mas_d, n);
				Search(mas_d, n);
				cout << "\n" << endl;
				cout << "\n-----------------------------------|float|------------------------------------\n";
				Prit(mas_f, n);
				Search(mas_f, n);
				cout << "\n" << endl;
				cout << "\n------------------------------------|char|------------------------------------\n";
				Prit(mas_ch, n);
				Search(mas_ch, n);
				cout << "\n" << endl;
				SetColor(LightBlue, Black);
				cout << "\n------------------------------Двумерный массив--------------------------------\n";

				Print(arr, line, colum);
				Search(arr, line, colum);
				cout << "\n" << endl;
				cout << "\n-----------------------------------|double|-----------------------------------\n";
				Print(arr_d, line, colum);
				Search(arr_d, line, colum);
				cout << "\n" << endl;
				cout << "\n-----------------------------------|float|------------------------------------\n";
				Print(arr_f, line, colum);
				Search(arr_f, line, colum);
				cout << "\n" << endl;
				cout << "\n------------------------------------|char|------------------------------------\n";
				Print(arr_ch, line, colum);
				Search(arr_ch, line, colum);
				SetColor(White, Black);

				cout << endl;
				cout << "\nESC-для Выхода";
				key = _getch();
			} while (key != esc);

		}
		case 5:
		{
			break;
		}

		}

	} while (poz != 5);
}

//реализация Массива Рандом
void FillRand(int mas[], int n, int a, int b)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		mas[i] = a + rand() % (b - a);

	}

}
void FillRand(double mas[], int n, int a, int b)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		mas[i] = a + rand() % (b - a) * 1.1;

	}

}
void FillRand(float mas[], int n, int a, int b)
{
	srand(time(NULL) + 256);
	for (int i = 0; i < n; i++)
	{
		mas[i] = a + rand() % (b - a) * 1.1;

	}

}
void FillRand(char mas[], int n, int a, int b)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		mas[i] = rand() % 256;

	}

}
//Реализация двойного массива 
void FillRand(int mas[line][colum], int n, int a)
{
	//srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a; j++)
		{

			mas[i][j] = rand() % 20;
		}

	}

}
void FillRand(double mas[line][colum], int n, int a)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a; j++)
		{
			mas[i][j] = rand() % 20 * 1.1;

		}

	}
}
void FillRand(float mas[line][colum], int n, int a)
{
	srand(time(NULL) + 256);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a; j++)
		{
			mas[i][j] = rand() % 20 * 1.1;

		}

	}
}
void FillRand(char mas[line][colum], int n, int a)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a; j++)
		{
			mas[i][j] = rand() % 256;

		}

	}

}
//Реализация Массива Рисовка

template <typename T>void Prit(T mas[], int n)
{
	for (int i = -0; i < n; i++)
	{
		cout << mas[i] << "\t";

	}

}
//Реализация двойного массива
template <typename T>void Print(T mas[line][colum], int n, int a)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a; j++)
		{

			cout << mas[i][j] << "\t";


		}
		cout << endl;
	}

}

//Реализация одинарного массива Сумма
template <typename T>T Sum(T mas[], int n)
{
	T Sum = 0;

	for (int i = 0; i < n; i++)
	{
		Sum = Sum + mas[i];

	}



	return Sum;
}

//Реализация двойного массива
template <typename T>T Sum(T mas[line][colum], int n, int a)
{
	T Sum = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a; j++)
		{
			Sum = Sum + mas[i][j];
		}


	}



	return Sum;

}

//Реализация одинарного массива Среднее значение
template <typename T>T Avg(T Sum, int n)
{
	T Avg = 0;
	Avg = Sum / n;

	return Avg;
}

//Реализация двойного массива
template <typename T>T Avg(T Sum, int n, int a)
{
	n = n * a;
	return Sum / n;

}

//Реализация одинарного массива Мин значение
template <typename T>T minValueln(T mas[], int n)
{
	T Min = mas[0];

	for (int i = 1; i < n; i++)
	{
		if (mas[i] < Min)
		{
			Min = mas[i];
		}


	}


	return Min;
}

//Реализация двойного массива
template <typename T>T minValueln(T mas[line][colum], int n, int a)
{
	T Min = mas[0][0];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (mas[i][j] < Min)
			{
				Min = mas[i][j];
			}
		}



	}


	return Min;
}

//Реализация одинарного массива Макс значение
template <typename T>T maxValueln(T mas[], int n)
{

	T Max = mas[0];

	for (int i = 1; i < n; i++)
	{
		if (mas[i] > Max)
		{
			Max = mas[i];
		}


	}


	return Max;


}

//Реализация двойного массива
template <typename T>T maxValueln(T mas[line][colum], int n, int a)
{
	T Max = mas[0][0];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (mas[i][j] > Max)
			{
				Max = mas[i][j];
			}
		}



	}


	return Max;
}

//Реализация одинарного массива Сортировка
template <typename T>void Sort(T mas[], int n)
{
	T boof = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++) {
			if (mas[j] > mas[j + 1])
			{
				boof = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = boof;
			}
		}
	}
}

//Реализация двойного массива
template <typename T>void Sort(T mas[line][colum], int n, int a)
{
	T boof = 0;

	/*for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < a; k++)
		{
			for (int j = 0; j < a - k - 1; j++)
			{
				if (mas[i][j] > mas[i][j+1])
				{
					boof = mas[i][j];
					mas[i][j] = mas[i][j+1];
					mas[i][j+1] = boof;
				}
			}
		}

	}
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < a; k++)
		{
			for (int j = 0; j < n - i - 1; j++)
			{
				if (mas[j][k] > mas[j + 1][k])
				{
				boof = mas[j][k];
				mas[j][k] = mas[j + 1][k];
				mas[j + 1][k] = boof;
				}
			}
		}

	}*/

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a; j++)
		{

			for (int f = 0; f < n; f++)
			{

				for (int h = 0; h < a; h++)
				{

					if (mas[f][h] > mas[i][j])
					{
						boof = mas[i][j];
						mas[i][j] = mas[f][h];
						mas[f][h] = boof;

					}
				}
			}



		}
	}

}
//void Sort(double mas[line][colum], int n, int a)
//{
//	double boof = 0;
//
//	/*for (int i = 0; i < n; i++)
//	{
//		for (int k = 0; k < a; k++)
//		{
//			for (int j = 0; j < a - k - 1; j++)
//			{
//				if (mas[i][j] > mas[i][j + 1])
//				{
//					boof = mas[i][j];
//					mas[i][j] = mas[i][j + 1];
//					mas[i][j + 1] = boof;
//				}
//			}
//		}
//
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int k = 0; k < a; k++)
//		{
//			for (int j = 0; j < n - i - 1; j++)
//			{
//				if (mas[j][k] > mas[j + 1][k])
//				{
//					boof = mas[j][k];
//					mas[j][k] = mas[j + 1][k];
//					mas[j + 1][k] = boof;
//				}
//			}
//		}
//
//	}*/
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < a; j++)
//		{
//
//			for (int f = 0; f < n; f++)
//			{
//
//				for (int h = 0; h < a; h++)
//				{
//
//					if (mas[f][h] > mas[i][j])
//					{
//						boof = mas[i][j];
//						mas[i][j] = mas[f][h];
//						mas[f][h] = boof;
//
//					}
//				}
//			}
//
//
//
//		}
//	}
//}
//void Sort(float mas[line][colum], int n, int a)
//{
//	float boof = 0;
//
//	/* for (int i = 0; i < n; i++)
//	 {
//		 for (int k = 0; k < a; k++)
//		 {
//			 for (int j = 0; j < a - k - 1; j++)
//			 {
//				 if (mas[i][j] > mas[i][j + 1])
//				 {
//					 boof = mas[i][j];
//					 mas[i][j] = mas[i][j + 1];
//					 mas[i][j + 1] = boof;
//				 }
//			 }
//		 }
//
//	 }
//	 for (int i = 0; i < n; i++)
//	 {
//		 for (int k = 0; k < a; k++)
//		 {
//			 for (int j = 0; j < n - i - 1; j++)
//			 {
//				 if (mas[j][k] > mas[j + 1][k])
//				 {
//					 boof = mas[j][k];
//					 mas[j][k] = mas[j + 1][k];
//					 mas[j + 1][k] = boof;
//				 }
//			 }
//		 }
//
//	 }*/
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < a; j++)
//		{
//
//			for (int f = 0; f < n; f++)
//			{
//
//				for (int h = 0; h < a; h++)
//				{
//
//					if (mas[f][h] > mas[i][j])
//					{
//						boof = mas[i][j];
//						mas[i][j] = mas[f][h];
//						mas[f][h] = boof;
//
//					}
//				}
//			}
//
//
//
//		}
//	}
//}
//void Sort(char mas[line][colum], int n, int a)
//{
//	char boof = ' ';
//
//	/*for (int i = 0; i < n; i++)
//	{
//		for (int k = 0; k < a; k++)
//		{
//			for (int j = 0; j < a - k - 1; j++)
//			{
//				if (mas[i][j] > mas[i][j + 1])
//				{
//					boof = mas[i][j];
//					mas[i][j] = mas[i][j + 1];
//					mas[i][j + 1] = boof;
//				}
//			}
//		}
//
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int k = 0; k < a; k++)
//		{
//			for (int j = 0; j < n - i - 1; j++)
//			{
//				if (mas[j][k] > mas[j + 1][k])
//				{
//					boof = mas[j][k];
//					mas[j][k] = mas[j + 1][k];
//					mas[j + 1][k] = boof;
//				}
//			}
//		}
//
//	}*/
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < a; j++)
//		{
//
//			for (int f = 0; f < n; f++)
//			{
//
//				for (int h = 0; h < a; h++)
//				{
//
//					if (mas[f][h] > mas[i][j])
//					{
//						boof = mas[i][j];
//						mas[i][j] = mas[f][h];
//						mas[f][h] = boof;
//
//					}
//				}
//			}
//
//
//
//		}
//	}
//}
//Реализация одинарного массива Уникальный Рандом
void UniqueRand(int mas[], int n, int a, int b)
{
	FillRand(mas, n, a, b);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mas[j] == mas[i] && i != j)
			{
				mas[i] = a + rand() % (b - a);
				j = -1;
			}
		}

	}


}
double UniqueRand(double mas[], int n, int a, int b)
{
	FillRand(mas, n, a, b);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mas[j] == mas[i] && i != j)
			{
				mas[i] = a + rand() % (b - a);
				j = -1;
			}
		}

	}

	return 0;
}
float UniqueRand(float mas[], int n, int a, int b)
{
	FillRand(mas, n, a, b);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mas[j] == mas[i] && i != j)
			{
				mas[i] = a + rand() % (b - a);
				j = -1;
			}
		}

	}

	return 0;
}
char UniqueRand(char mas[], int n, int a, int b)
{
	FillRand(mas, n, a, b);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mas[j] == mas[i] && i != j)
			{
				mas[i] = a + rand() % (b - a);
				j = -1;
			}
		}

	}

	return 0;
}
//Реализация двойного массива
void UniqueRand(int mas[line][colum], int n, int a)
{
	FillRand(mas, line, colum);
	srand(time(NULL));
	for (int i = 0; i < n; i++)//столб
	{
		for (int k = 0; k < a; k++)//строка
		{
			for (int f = 0; f < n; f++)
			{
				for (int j = 0; j < a; j++)
				{

					if (mas[i][k] == mas[f][j] && (i != f || k != j))
					{
						mas[i][k] = rand() % 50;

						f = 0;
						j = -1;
					}
				}

			}

		}


	}
}
void UniqueRand(double mas[line][colum], int n, int a)
{
	FillRand(mas, line, colum);
	srand(time(NULL));
	for (int i = 0; i < n; i++)//столб
	{
		for (int k = 0; k < a; k++)//строка
		{
			for (int f = 0; f < n; f++)
			{
				for (int j = 0; j < a; j++)
				{

					if (mas[i][k] == mas[f][j] && (i != f || k != j))
					{
						mas[i][k] = rand() % 50 * 1.1;

						f = 0;
						j = -1;
					}
				}

			}

		}


	}
}
void UniqueRand(float mas[line][colum], int n, int a)
{
	FillRand(mas, line, colum);
	srand(time(NULL) + 35);
	for (int i = 0; i < n; i++)//столб
	{
		for (int k = 0; k < a; k++)//строка
		{
			for (int f = 0; f < n; f++)
			{
				for (int j = 0; j < a; j++)
				{

					if (mas[i][k] == mas[f][j] && (i != f || k != j))
					{
						mas[i][k] = rand() % 50 * 1.1;

						f = 0;
						j = -1;
					}
				}

			}

		}


	}
}
void UniqueRand(char mas[line][colum], int n, int a)
{
	FillRand(mas, line, colum);
	srand(time(NULL));
	for (int i = 0; i < n; i++)//столб
	{
		for (int k = 0; k < a; k++)//строка
		{
			for (int f = 0; f < n; f++)
			{
				for (int j = 0; j < a; j++)
				{

					if (mas[i][k] == mas[f][j] && (i != f || k != j))
					{
						mas[i][k] = rand() % 256;

						f = 0;
						j = -1;
					}
				}

			}

		}


	}
}
//Реализация одинарного массива Повтор
template <typename T>void Search(T mas[], int n)
{
	T arr[10]{};
	cout << endl;
	int coll = 0, cikl = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mas[i] == mas[j])
			{
				coll++;
			}


		}

		if (coll > 0)
		{

			for (int g = 0; g < n; g++)
			{
				if (mas[i] == arr[g])
				{
					cikl++;
				}

			}

			if (cikl == 0)
			{
				arr[i] = mas[i];
				cout << mas[i] << "|" << coll;
			}
			cikl = 0;


		}
		coll = 0;
		cout << "\t";
	}

}

//Реализация двойного массива
template <typename T>void Search(T mas[line][colum], int n, int a)
{
	T arr[line][colum];
	int coll = 0, cikl = 0;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a; j++)
		{
			for (int f = 0; f < n; f++)
			{
				for (int k = 0; k < a; k++)
				{
					if (mas[i][j] == mas[f][k])
					{
						coll++;

					}

				}
			}


			if (coll > 0)
			{

				for (int g = 0; g < n; g++)
				{
					for (int q = 0; q < a; q++)
					{
						if (mas[i][j] == arr[g][q])
						{
							cikl++;
						}

					}


				}

				if (cikl == 0)
				{
					arr[i][j] = mas[i][j];
					cout << "[" << mas[i][j] << "]-" << coll;
				}
				cikl = 0;
				coll = 0;
			}
		}

	}



}

//Реализация сдвиг одинарного массива
void Shift_Left_And_Right(int mas[], int n)
{
	int key;

	int size = 0;
	do {
		system("cls");

		for (int i = 0; i < 10; i++)
		{


			cout << mas[i] << "\t";
		}

		cout << endl;
		cout << "Нажмите Enter для выхода";



		key = _getch();
		switch (key)
		{
		case Left:
		{
			size--;
			break;
		}
		case Right:
		{
			size++;
			break;
		}
		case Enter:
		{
			break;
		}

		}
		if (size < 0)
		{
			size = 9;
		}
		if (size > 9 && key == Right)
		{
			size = 0;
		}
		size = n - size;
		for (int i = 0; i < size; i++)
		{
			int d = mas[0];
			for (int i = 0; i < n; i++)
			{

				mas[i] = mas[i + 1];

			}
			mas[n - 1] = d;
		}


	} while (key != Enter);



}
// Реализация двойного массива
void Shift_Left_And_Right(int mas[line][colum], int n, int a)
{
	int key;
	 int cool = 0;
	do
	{
		int size = 0;
		system("cls");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < a; j++)
			{
				if (cool == 0 && i == 0)
				{
					SetColor(Red, Black);
				}
				if (cool == 1 && i == 1)
				{
					SetColor(Red, Black);
				}
				if (cool == 2 && i == 2)
				{
					SetColor(Red, Black);
				}
				if (cool == 3 && i == 3)
				{
					SetColor(Red, Black);
				}
				cout << mas[i][j] << "\t";
			}
			cout << endl;
			SetColor(White, Black);
		}

		cout << endl;
		cout << "Нажмите Enter для выхода";

		key = _getch();

		switch (key)
		{
		case Left:	size--; break;
		case Right:	size++; break;
		case Up:	cool--; break;
		case Down:	cool++; break;
		case 224:
		case -32:continue;
		case Enter:	break;
		}
		if (size < 0 && key == Left)
		{
			size = 11;
		}
		/*if (size > 9 && key == Right)
		{
			size = 0;
		}*/
		if (key == Right)size = a - size;

		if (cool < 0)
		{
			cool = 3;
		}
		if (cool > 3 && key == Down)
		{
			cool = 0;
		}
		//for (int i = cool; i < n; i++)
		{
			for (int j = 0; j < size; j++)
			{
				int d = mas[cool][0];
				for (int j = 0; j < a; j++)
				{
					mas[cool][j] = mas[cool][j + 1];
				}
				mas[cool][a - 1] = d;
			}
			//			break;
		}
	} while (key != Enter);
}
//Меню
int menu()
{
	char menu[6][50] = { "Вывод массива и работа с ним","Движение массива","Сортировка массива","Заполнение массива уник числами","Нахожденеи повторений","Выход" };//Пункты меню
	int poz = 0, key;//поз-пункта меню, кей-кнопка нажатия

	for (int i = 0; i < 6; i++)//Рисовка меню
	{
		SetCursor(15, 10 + i);
		cout << menu[i];

	}
	do {
		for (int i = 0; i < 6; i++)//изменения цвета выбронного пункта
		{
			SetCursor(15, 10 + i);

			if (i == poz)
			{
				SetColor(Yellow, Black);

			}
			else
			{
				SetColor(White, Black);

			}

			cout << menu[i];

		}

		key = _getch();
		switch (key)
		{
		case Up:
		{	poz--;
		if (poz < 0)
		{
			poz = 5;
		}
		break;
		}
		case Down:
		{
			poz++;
			if (poz > 5)
			{
				poz = 0;
			}
			break;
		}
		case Enter:
		{
			SetColor(White, Black);
			return(poz);//возвращение выбронного пункта меню
		}


		}

	} while (true);







}
int menu2()
{
	char menu[3][50] = { "Сдвиг одномерного массива","Сдвиг Двумерного массива","Назад" };//Пункты меню
	int poz = 0, key;//поз-пункта меню, кей-кнопка нажатия

	for (int i = 0; i < 3; i++)//Рисовка меню
	{
		SetCursor(15, 10 + i);
		cout << menu[i];

	}
	do {
		system("cls");
		for (int i = 0; i < 3; i++)//изменения цвета выбронного пункта
		{
			SetCursor(15, 10 + i);

			if (i == poz)
			{
				SetColor(Yellow, Black);
				cout << "-->" << menu[i] << "<--";
			}
			else
			{
				SetColor(White, Black);
				cout << menu[i];
			}

			//cout << menu[i];

		}

		key = _getch();
		switch (key)
		{
		case Up:
		{	poz--;
		if (poz < 0)
		{
			poz = 2;
		}
		break;
		}
		case Down:
		{
			poz++;
			if (poz > 2)
			{
				poz = 0;
			}
			break;
		}
		case Enter:
		{
			SetColor(White, Black);
			return(poz);//возвращение выбронного пункта меню
		}


		}

	} while (true);
}


//Шаблонной называеться функция котороая может работать с любым типом данныхдля того что бы сделать функцию шаблонной 
//перед ней достаточно просто создать шаблон след образом template<typename T>
//где template - создает шаблон
//typename - создает шаблонный тип данных
//Т-имя шаблонного типа
//После создания шаблона любой принемаеммый параметр возвращаеммое значение и локальная переменная могут быть шаблонного типа
//