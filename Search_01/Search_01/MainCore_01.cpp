#include <iostream>
#include <cmath>
#include <time.h>
#include <fstream> 
#include <string>
#include <limits.h>
#include <string.h>
#include <stdio.h>

#include "Search_01.h"
using namespace std;

void main()
{
	Search_01 Search_01;

	setlocale(LC_ALL, "rus");
	srand(time(0));

	Search_01.LinearSearch("OutFile", 2);
	Search_01.BinarySearch("OutFile", 2);

	cout << "Поиск успешно завершён" << endl;

	// Сделать один массив, а не 2. Сначала линейный, потом сортируем этот массив, и запускаем бинарный.
	// Если запустили линейный на отсортированном, то ничего страшного
}