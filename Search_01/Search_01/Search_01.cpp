#include "Search_01.h"

#include <iostream>
#include <cmath>
#include <time.h>
#include <fstream> 
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>     
#include <errno.h>   

using namespace std;

// Если вам мешают уведомления об ошибках, то просто отключите их))
#pragma warning(disable : 4996)

// Главный счётчик для размеров всех массивов
// Столько записей мы будем создавать и сортировать
int const AllCount = 20;

// Распознаём и записываем данные из файла во внутреннй массив программы, для дальнейшей сортировки
Search_01::AQ* Search_01::Processing_data_from_the_input_file(string NameFile)
{
	int const AllCount = 20;
	Search_01::AQ* mass = new Search_01::AQ[AllCount];

	Search_01 Search_01;


	string S[AllCount];
	int n = 0;

	NameFile = NameFile + ".txt";

	fstream DataFile(NameFile, fstream::in);

	if (DataFile.is_open())
	{
		string str = "";

		string nam, fam, oth;

		int intMass = 0;
		n = 0;

		while (n < AllCount) //(!DataFile.eof())
		{
			getline(DataFile, S[n]);
			//cout << S[n] << endl;

			string input = S[n];

			char r;
			int y = 0;

			str = "";
			r = input[y];

			while (r != ' ')
			{
				r = input[y];
				if (r != ' ')
				{
					str = str + r;
				}
				y++;
			}

			//cout << "Имя (str) = " << str << endl;

			nam = str;
			str = "";

			r = input[y];

			while (r != ' ')
			{
				r = input[y];
				if (r != ' ')
				{
					str = str + r;
				}
				y++;
			}

			//cout << "Фамилия (str) = " << str << endl;

			fam = str;
			str = "";

			r = input[y];

			while (r != ',')
			{
				r = input[y];
				if (r != ',')
				{
					str = str + r;
				}
				y++;
			}

			//cout << "Отество (str) = " << str << endl;
			oth = str;

			str = "";

			r = input[y];

			while (r != ',')
			{
				r = input[y];
				if (r != ',')
				{
					str = str + r;
				}
				y++;
			}

			mass[intMass].fio = nam + " " + fam + " " + oth;

			//cout << "Профессия (str) = " << str << endl;
			mass[intMass].d = str;

			str = "";
			y++;
			r = input[y];

			while (r != ',') 
			{
				r = input[y];
				y++;
			}

			y++;
			r = input[y];

			while (r != ' ')
			{
				r = input[y];
				if (r != ' ')
				{
					str = str + r;
				}
				y++;
			}

			//cout << "Стаж (str) = " << str << endl;

			char* strng = new char[str.length() + 1];
			strcpy(strng, str.c_str());

			mass[intMass].s = atoi(strng);

			mass[intMass].id = intMass;

			n++;
			intMass++;
		}
	}
	else
	{
		cout << "Ошибка! Файл с именем " << NameFile << " не найден!" << endl;
		exit(000);
	}

	DataFile.close();
	return mass;
}


// Выводит данные в консоль
void Search_01::coutM(AQ* mass, int n)
{
	int f = 0;

	for (int i = 0; i < n; i++)
	{
		if (mass[i].d != "")
		{
			cout << "[" << mass[i].fio << ", " << mass[i].d << ", " << mass[i].s << " лет" << "]" << endl;
			//cout << "[" << mass[i].fio << ", " << mass[i].d << ", " << mass[i].s << " лет" << ", id = " << mass[i].id << "]" << endl;
			f++;
		}
	}

	if (f == 0)
	{
		cout << "<Поиск не дал результатов>" << endl;
	}
}
// Выводит в консоль только нужную нам строку данных
void Search_01::coutQ(AQ mass)
{
	cout << "[" << mass.fio << ", " << mass.d << ", " << mass.s << " лет" << "]" << endl;
	//cout << "[" << mass.fio << ", " << mass.d << ", " << mass.s << " лет" << ", id = " << mass.id << "]" << endl;
}






//// ----- Бинарный рекурсивный:

int countIteration = -1; // Количесво итераций, за которые бинарный поиск найдёт нужный элемент

// Алгоритм бинарного рекурсивного поиска
int Search_01::binaryS(Search_01::AQ* massNS, int l, int r, int x)
{
	countIteration++;

	if (r >= l)
	{
		int mid = l + (r - l) / 2;

		//cout << "Рассматриваем строку "; coutQ(massNS[mid]);

		if (massNS[mid].s == x)  return massNS[mid].id; //mid;
		if (massNS[mid].s > x) return Search_01::binaryS(massNS, l, mid - 1, x);
		return Search_01::binaryS(massNS, mid + 1, r, x);
	}
	return -2;
}

// Сортировка пузырьком
Search_01::AQ* Search_01::BubbleSort(Search_01::AQ* massNS)
{
	Search_01::AQ* mass = new Search_01::AQ[AllCount];

	for (int i = 0; i < AllCount; i++)
	{
		mass[i] = massNS[i];
	}
	
	int n = AllCount;

	// Сортируем массив по возрастанию:
	for (int i = 1; i < n; ++i)
	{
		for (int r = 0; r < n - i; r++)
		{
			if (mass[r].s > mass[r + 1].s)
			{
				swap(mass[r], mass[r + 1]);
			}
		}
	}

	return mass;
}

// Основная процедура запуска бинарного поиска
int Search_01::BinRecSearch(Search_01::AQ* massNS, int pattStaj)
{
	int n = AllCount;

	Search_01::AQ* massSB = new Search_01::AQ[AllCount];
	massSB = massNS;
	massSB = BubbleSort(massSB);

	//cout << "Неотсортированный массив: " << endl;
	//coutM(massNS, AllCount);
	//cout << endl;

	//cout << "Отсортированный массив: " << endl;
	//coutM(massSB, AllCount);
	//cout << endl;

	countIteration = 0;
	int result = binaryS(massSB, 0, n - 1, pattStaj);

	PrintFromOutFile_BinarySearch(result+1, pattStaj, massNS);

	return result + 1;
}

// Печать результатов в файл
void Search_01::PrintFromOutFile_BinarySearch(int i, int pattStaj, Search_01::AQ* massNS)
{
	fstream OutSortFile1("ResultBinarySearch.txt", ios::out); // Удаляем все данные из файла
	(OutSortFile1).close();

	fstream OutSortFile("ResultBinarySearch.txt", ios::app);

	OutSortFile << "Бинарный поиск: " << endl;
	OutSortFile << endl;

	if (i != -1)
	{
		OutSortFile << "Шаблон поиска по полю «Стаж»: " << pattStaj << endl;
		OutSortFile << "Строка, в которой был найден элемент: ";
		i = i - 1;
		OutSortFile << "[" << massNS[i].fio << ", " << massNS[i].d << ", " << massNS[i].s << " лет" << "]" << endl;
		OutSortFile << endl;
		i = i + 1;
		OutSortFile << "Строка, в которой находится найденный элемент: " << i << endl;
		OutSortFile << "Количество шагов, за которые был получен ответ: " << countIteration << endl;
	}
	else
	{
		OutSortFile << "<Поиск не дал результатов>" << endl;
	}

	OutSortFile << endl;
	OutSortFile << "-----------------" << endl;
	(OutSortFile).close();
}

// Процедура, для пользователя
int Search_01::BinarySearch(string NameFile, int pattStaj)
{
	Search_01 Search_01;

	Search_01::AQ* massNS = new Search_01::AQ[AllCount];

	massNS = Search_01.Processing_data_from_the_input_file(NameFile);

	int ret = Search_01::BinRecSearch(massNS, pattStaj);
	return(ret); // Возвращаю для нужд пользователя
}





//// ----- Линейный поиск

int Search_01::LinearSearch(string NameFile, int pattStaj)
{
	Search_01 Search_01;

	Search_01::AQ* massNS = new Search_01::AQ[AllCount];

	massNS = Search_01.Processing_data_from_the_input_file(NameFile);

	int ret = LinearSearchInsideProc(massNS, pattStaj);

	PrintFromOutFile_LinearSearch(ret, pattStaj, massNS);
	return(ret); // Возвращаю для нужд пользователя
}

void Search_01::PrintFromOutFile_LinearSearch(int i, int pattStaj, Search_01::AQ* massNS)
{
	fstream OutSortFile1("ResultLinearSearch.txt", ios::out); // Удаляем все данные из файла
	(OutSortFile1).close();

	fstream OutSortFile("ResultLinearSearch.txt", ios::app);

	OutSortFile << "Линейный поиск: " << endl;
	OutSortFile << endl;

	if (i != -1)
	{
		OutSortFile << "Шаблон поиска по полю «Стаж»: " << pattStaj << endl;
		OutSortFile << "Строка, в которой был найден элемент: ";
		i = i - 1;
		OutSortFile << "[" << massNS[i].fio << ", " << massNS[i].d << ", " << massNS[i].s << " лет" << "]" << endl;
		OutSortFile << endl;
		i = i + 1;
		OutSortFile << "Строка, в которой находится найденный элемент: " << i << endl;
		OutSortFile << "Количество шагов, за которые был получен ответ: " << i << endl;
	}
	else
	{
		OutSortFile << "<Поиск не дал результатов>" << endl;
	}

	OutSortFile << endl;
	OutSortFile << "-----------------" << endl;
	(OutSortFile).close();
}

int Search_01::LinearSearchInsideProc(Search_01::AQ* massNS, int pattStaj)
{
	for (int i = 0; i < AllCount; i++)
	{
		if (massNS[i].s == pattStaj)
		{
			//cout << "i = " << i << " "; coutQ(massNS[i]);
			return(i + 1);
		}		
	}

	return(-1); // При неудачном поиске возвращает это
}