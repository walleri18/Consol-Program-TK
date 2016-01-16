/*
	Практика программирования. ТК.
	Решение: Типы данных, определяемые пользователем
	Автор: Туров Виталий Александрович
	Группа: 514
*/
/*
	Проект №1.
	Описать структуру с именем STUDENT, содержащую следующие поля:
	1. Фамилия и инициалы(строка);
	2. Номер группы(целое число);
	3. Успеваемость (плавающее число).
	Объявить массив структур из 5 элементов и инициализировать его. 
	Упорядочить массив по возростанию номера группы. Вывести на экран фамилии и номера групп
	тех студентов, успеваемость которых превышает 4.0. Сортировку организовать в виде отдельной функции.
*/

/*
	Псевдо код:
	1. Создать структуру студент;
	2. Создать массив из 5 элементов этой структуры;
	3. Заполнить этот мыссив структуры;
	4. Поупорядочить массив по возростанию группы;
	5. Вывести на экран фамилии и номера групп, чья успеваемость выше либо равно 4.0.
*/

#ifdef UNICODE
#undef UNICODE
#endif

#include <locale.h>
#include <Windows.h>

#include <iostream>
#include <string>

using namespace std;

// Объявление структуры STUDENT
struct STUDENT
{
	char fullName[20];// Фамилия и инициалы
	int groupNumber;// Номер группы
	double performance;// Успеваемость
};

// Прототипы
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
	STUDENT massiv[sizeMassiv];

	// Заполнение массива
	for (int i = 0; i < sizeMassiv; i++)
	{
		// Ввод фамилии и инициалов студента
		cout << endl << endl << "Введите Фамилию и инициалы студента(вводите без пробелов!!!): ";
		cin >> massiv[i].fullName;
		
		// Перевод символов
		OemToCharA(massiv[i].fullName, massiv[i].fullName);

		// Ввод номера группы студента
		cout << endl << "Студент " << massiv[i].fullName << " состоит в группе(целое число): ";
		cin >> massiv[i].groupNumber;

		do
		{

			//Ввод успеваемости студента
			cout << endl << "Студент " << massiv[i].fullName << " из группы №" << massiv[i].groupNumber << " учится на(от 0 до 5): ";
			cin >> massiv[i].performance;

		} while ((massiv[i].performance < 0)||(massiv[i].performance > 5));
	}

	// Сортировка массива сортировкой выбора
	selestSort(massiv, sizeMassiv);

	// Вывод студентов хорошистов и отличников
	cout << endl << "Список студентов, чья успеваемость выше 4.0: " << endl << endl;
	for (int i = 0; i < sizeMassiv; i++)
	{
		if (massiv[i].performance >= 4.0) {
			cout << "Студент " << massiv[i].fullName << " из группы №" << massiv[i].groupNumber << endl << endl;
		}
	}

	system("pause");
	return 0;
}

// Функция сортировки массива структуры STUDENT
void selestSort(STUDENT *massiv, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int indexMinElement = i;

		for (int j = i + 1; j < size; j++)
		{
			if (massiv[j].groupNumber < massiv[indexMinElement].groupNumber) indexMinElement = j;
		}

		// Перестановка элементов
		swap(massiv[i], massiv[indexMinElement]);
	}
}