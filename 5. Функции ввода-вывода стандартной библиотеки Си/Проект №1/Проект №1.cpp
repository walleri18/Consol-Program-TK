/*
	Практика программирования. ТК.
	Решение: функции ввода/вывода стандартной библиотеки СИ
	Автор: Туров Виталий Александрович
	Группа: 514
*/
/*
	Проект №1.
	Использовать массив структур STUDENT из предыдущего проекта. Сохранить массив в двоичном файле.
	Прочитать из файла запись под номером, введённым пользователем, и вывести её на экран.
*/

/*
	Псевдо код:
	1. Создать структуру студент;
	2. Создать массив из 5 элементов этой структуры;
	3. Заполнить этот массив структуры;
	4. Поупорядочить массив по возростанию успеваемости;
	5. Сохранить массив в двоичный файл;
	6. Запросить пользователя номер записи;
	7. Вынуть запись с определённым номером из файла.
*/

#ifdef UNICODE
#undef UNICODE
#endif

#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <Windows.h>

#include <stdio.h>
#include <iostream>

using namespace std;

// Объявление структуры STUDENT
struct STUDENT
{
	char fullName[30];// Фамилия и инициалы
	int groupNumber;// Номер группы
	double performance;// Успеваемость
};

// Прототипы
void conclusionStudents(STUDENT &massiv);// Функция вывода студентов
void selestSort(STUDENT*, int);// Функция сортировки массива структуры STUDENT

// Точка входа

int main(void)
{
	setlocale(LC_ALL, ".1251"); // Установка кодировки windows-1251

	// Приветствие
	cout << "Добро пожаловать в программу по работе со структурами!!!" << endl << endl;

	// Размер заданного массива
	const int sizeMassiv(5);

	// Создание массива структуры STUDENT
	STUDENT massiv[sizeMassiv] = {
		{"Туров Виталий", 514, 5},
		{"Рапанов Сергей", 514, 4},
		{"Курицын Сергей", 514, 4},
		{"Напылов Роман", 514, 3},
		{"Угольник", 514, 5}
	};

	// Сортировка массива сортировкой выбора
	selestSort(massiv, sizeMassiv);

	// Указатель на файл для записи
	FILE *file;

	// Открытие файла для записи и чтения в бинарном режиме
	if (!(file = fopen("file.dat", "w+b"))) {
		cout << "Неудалось открыть файл на запись и чтение в бинарном режиме!!!" << endl;
		system("pause >> void");
		exit(1);
	}

	// Запись в файл
	fwrite(massiv, sizeof(STUDENT), 5, file);

	// Номер записи
	int numberWrite(0);

	do
	{
		// Запрос номера записи
		cout << endl << "Введите номер записи(1 - 5): ";
		cin >> numberWrite;
	} while (!(numberWrite > 0 && numberWrite <= sizeMassiv));
	
	cout << endl << endl;

	// Расчёт смещения
	int seek = (numberWrite - 1) * sizeof(STUDENT);

	// Выполнение смещения
	fseek(file, seek, SEEK_SET);

	// Чтение определённой записи
	STUDENT tmp;
	fread(&tmp, sizeof(STUDENT), 1, file);

	// Вывод
	conclusionStudents(tmp);

	// Закрытие бинарного файла
	fclose(file);

	system("pause >> void");
	return 0;
}

// Функция вывода студентов
void conclusionStudents(STUDENT &massiv)
{
	cout << endl << massiv.fullName << " из группы №" << massiv.groupNumber << " учится на " << massiv.performance << endl;
}

// Функция сортировки массива структуры STUDENT
void selestSort(STUDENT *massiv, int size)
{
	for (int i = 0; i < size; i++)
	{
		int indexMinElement = i;

		for (int j = i + 1; j < size; j++)
		{
			if (massiv[j].performance < massiv[indexMinElement].performance) indexMinElement = j;
		}

		// Переставить местами
		swap(massiv[i], massiv[indexMinElement]);
	}
}