#pragma once
#include <iostream>
#include <cmath>
#include <time.h>
#include <fstream> 

using namespace std;

class Search_01
{
public:
	struct AQ // Структура нужных нам данных
	{
		string d;	// Должность
		int s;		// Стаж
		string fio; // ФИО
		int id = 0; // id
	};
	

	// Получаем на вход имя файла, и потом загружаем из него во внутренние массивы программы данные
	Search_01::AQ* Processing_data_from_the_input_file(string NameFile); 

	void coutM(AQ* mass, int n); // Выводим данные в консоль
	void coutQ(AQ mass); // Выводим в консоль только нужную нам строку данных 


	//// ----- Линейный поиск:

	// Процедура, для пользователя
	int LinearSearch(string NameFile, int pattStaj); 

	// Основная процедура запуска линейного поиска
	int LinearSearchInsideProc(Search_01::AQ* massNS, int pattStaj); 

	// Печать результатов в файл
	void PrintFromOutFile_LinearSearch(int i, int pattStaj, Search_01::AQ* massNS);



	//// ----- Бинарный (рекурсивная реализация):

	// Основная процедура запуска бинарного поиска
	int BinRecSearch(Search_01::AQ* massNS, int pattStaj);

	// Алгоритм бинарного рекурсивного поиска
	int binaryS(Search_01::AQ* massNS, int l, int r, int x);

	// Процедура, для пользователя
	int BinarySearch(string NameFile, int pattStaj);

	// Печать результатов в файл
	void PrintFromOutFile_BinarySearch(int i, int pattStaj, Search_01::AQ* massNS);

	// Сортировка пузырьком
	Search_01::AQ* BubbleSort(Search_01::AQ* massNS);

};

/*
	Создатель кода: Gogik Ortey (Орлов Георгий)
	https://vk.com/gog.ortey

	Этот код предоставляется на условиях открытого доступа.
	Все, кому нужно, могут скопировать и использовать его когда и где захотят.
*/

