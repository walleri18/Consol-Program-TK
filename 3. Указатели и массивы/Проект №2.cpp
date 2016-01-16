/*
	Практика программирования. ТК.
	Решение: Указатели и массивы
	Автор: Туров Виталий Александрович
	Группа: 514
*/
/*
	Проект №2.
	С помощью генератора случайных чисел (rand()) сформировать
	одномерный массив из 20 элементов целого типа (значения в диапозоне от -100 до 100).
	Вывести массив на экран. Посчитать количество отрицательных и положительных элементов
	между его максимальным и минимальным элементами массива. Вывести результаты на экран.
*/

/*
	Псевдо код:
	1. Создать целочисленный массив на 20 элементов;
	2. Сгенирировать поэлементно числа массива;
	3. Вывести сгенирированный массив на экран;
	4. Найти индексы максимального элемента и минимального;
	5. От наименьшего индекса до максимального подсчитать количество элементов;
	6. Вывести результат на экран.
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
void conclusion(int*, int);// Функция вывода массива
void countingTheNumberOfElements(int*, int, int, int&, int&);// Функция подсчёта элементов

// Точка входа

int main(void)
{
	setlocale(LC_ALL, ".1251"); // Установка кодировки windows-1251

	// Ядро случайных чисел
	srand(time(NULL));

	// Приветствие
	cout << "Добро пожаловать в программу по работе с массивом!!!" << endl << endl;

	// Количество элементов в массиве
	const int N = 20;

	// Диапозон значений элементов
	const int minElement(-100), maxElement(100);

	// Минимальный и максимальный элемент и их индексы
	int minimunElement(100), maximumElement(-100), maxIndexElement(0), minIndexElement(0);

	// Количество отрицательных и положительных элементов
	int colNegativElement(0), colPozitivElement(0);

	// Ссылки количество отрицательных и положительных элементов
	int &pcolNegativElement(colNegativElement), &pcolPozitivElement(colPozitivElement);

	// Создание целочисленного статического массива на 20 элементов
	int massiv[N];

	// Заполнение массива случайными числами
	for (int i = 0; i < N; i++)
	{
		massiv[i] = rand() % (maxElement - minElement + 1) + minElement;
	}

	// Вывод массива
	cout << endl << "Массив: " << endl;
	conclusion(massiv, N);

	// Поиск максимального и минимального элементов инлексов
	for (int i = 0; i < N; i++)
	{
		if (massiv[i] < minimunElement) {
			minimunElement = massiv[i];
			minIndexElement = i;
		}
		else if (massiv[i] > maximumElement) {
			maximumElement = massiv[i];
			maxIndexElement = i;
		}
	}

	// Подсчёт количества элементов
	if (minIndexElement < maxIndexElement) countingTheNumberOfElements(massiv, minIndexElement, maxIndexElement, pcolNegativElement, pcolPozitivElement);
	else if (minIndexElement > maxIndexElement) countingTheNumberOfElements(massiv, maxIndexElement, minIndexElement, pcolNegativElement, pcolPozitivElement);

	// Результат
	cout << endl << "Минимальный элемент: " << minimunElement << "; её индекс: " << minIndexElement << endl
		<< "Максимальный элемент: " << maximumElement << "; её индекс: " << maxIndexElement << endl
		<< "Количество положительных элементов: " << colPozitivElement << endl
		<< "Количество отрицательных элементов: " << colNegativElement << endl;

	system("pause");
	return 0;
}

// Функция вывода массива
void conclusion(int *massiv, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << endl << "massiv[" << i << "] = " << massiv[i] << endl;
	}
}

// Функция подсчёта количества элементов
void countingTheNumberOfElements(int *massiv, int minIndex, int maxIndex, int &colNegativElement, int &colPozitivElement)
{
	for (int i = minIndex + 1; i < maxIndex; i++)
	{
		if (massiv[i] < 0) ++colNegativElement;
		else if (massiv[i] > 0) ++colPozitivElement;
	}
}