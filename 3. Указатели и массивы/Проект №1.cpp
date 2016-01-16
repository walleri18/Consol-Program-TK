/*
	Практика программирования. ТК.
	Решение: Указатели и массивы
	Автор: Туров Виталий Александрович
	Группа: 514
*/
/*
	Проект №1.
	С помощью генератора случайных чисел (rand()) сформировать 
	одномерный массив из 20 элементов целого типа (значения в диапозоне от -100 до 100).
	Вывести массив на экран. Посчитать количество отрицательных и положительных элементов.
	Упорядочить массив по возростанию методом выбора. Вывести результат на экран.
*/

/*
	Псевдо код:
	1. Создать целочисленный массив на 20 элементов;
	2. Сгенирировать поэлементно числа массива;
	3. Вывести сгенирированный массив на экран;
	4. Подсчитать количество отрицательных и положительных элементов;
	5. Упорядочить массив по возростанию методом выбора;
	Вывести результат на экран.
*/

#ifdef UNICODE
#undef UNICODE
#endif

#include <locale.h>
#include <Windows.h>

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Прототипы
void conclusion(int*, int);// Функция вывода
template <class Type> void selestSort(Type*, int);// Функция сортировки выбором

// Точка входа

int main(void)
{
	setlocale(LC_ALL, ".1251"); // Установка кодировки windows-1251

	// Ядро случайных чисел
	srand(time(NULL));

	// Приветствие
	cout << "Добро пожаловать в программу по работе с массивов!!!" << endl << endl;

	// Количество элементов в массиве
	const int N = 20;

	// Диапозон значений элементов
	const int minElement(-100), maxElement(100);

	// Количество отрицательных и положительных элементов
	int colNegativElement(0), colPozitivElement(0);

	// Создание целочисленного статического массива на 20 элементов
	int massiv[N];

	// Заполнение массива случайными числами
	for (int i = 0; i < N; i++)
	{
		massiv[i] = rand() % (maxElement - minElement + 1) + minElement;
	}

	// Вывод массива
	cout << endl << "Исходный массив: " << endl;
	conclusion(massiv, N);

	// Подсчёт количества отрицательных и положительных элементов
	for (int i = 0; i < N; i++)
	{
		if (massiv[i] < 0) ++colNegativElement;
		else if (massiv[i] > 0) ++colPozitivElement;
	}

	// Сортировка выбором
	selestSort(massiv, N);

	// Вывод окончательных результатов
	cout << endl << "Окончательный вид массива: " << endl;
	conclusion(massiv, N);// Вывод отсортированного массива
	cout << endl << "Количество положительных элементов: " << colPozitivElement << endl
		<< "Количество отрицательных элементов: " << colNegativElement << endl << endl;

	system("pause >> void");
	return 0;
}

// Функция вывода
void conclusion(int *massiv, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << endl << "massiv[" << i << "] = " << massiv[i] << endl;
	}
}

// Функция сортировки выбором
template <class Type>
void selestSort(Type *massiv, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int indexMinElement = i;

		for (int j = i + 1; j < size; j++)
		{
			if (massiv[j] < massiv[indexMinElement]) indexMinElement = j;
		}

		// Перестановка элементов
		swap(massiv[i], massiv[indexMinElement]);
	}
}