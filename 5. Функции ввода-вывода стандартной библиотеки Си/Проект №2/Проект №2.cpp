/*
	Практика программирования. ТК.
	Решение: функции ввода/вывода стандартной библиотеки СИ
	Автор: Туров Виталий Александрович
	Группа: 514
	*/
/*
	Проект №2.
	Прочитать слова из текстового файла и сохранить их в массив строк.
	Вывести текст на экран, посчитать количество слов, найти самое длинное
	и самое короткое слово.
	*/

/*
	Псевдо код:
	1. Заранее создать текстовый файл - readme.txt;
	2. Создать двумерный массив для считывания слов;
	3. Считать слова из файла в двумерный массив;
	4. Вывести массив на экран;
	5. Подсчитать количества слов и вывести их количество;
	6. Найти самое длинное слово и вывести на экран;
	7. Найти самое короткое слово и вывести на экран;
	*/

#ifdef UNICODE
#undef UNICODE
#endif

#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <Windows.h>

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

typedef unsigned long int sizeFileSymbol;

// Точка входа

int main(void)
{
	setlocale(LC_ALL, ".1251"); // Установка кодировки windows-1251

	// Приветствие
	cout << "Добро пожаловать в программу по работе с текстовыми файлами!!!" << endl << endl;

	// Создание переменной для работы с текстовым файлом
	FILE *file;

	// Открываем файл для чтения в текстовом режиме
	if (!(file = fopen("readme.txt", "r"))) {
		cout << endl << "Ошибка открытия файла!!!" << endl;
		system("pause >> void");
		exit(1);
	}

	// Определим массив для символов
	char massiv[1000][100] = { 0 };

	// Переменная для посчёта количества слов
	int colSlovMassiv(0);

	// Считаем слова в матрицу
	for (int i = 0;; i++)
	{
		fscanf(file, "%s", massiv[i]);

		if (feof(file)) break;

		colSlovMassiv++;
	}

	// Закрытие файла
	fclose(file);

	// Вывод массива на экран
	for (int i = 0; i <= colSlovMassiv; i++)
	{
		cout << massiv[i] << " ";
	}

	// Вывод количества слов
	cout << endl << endl << "Количества слов в файле: " << colSlovMassiv << endl;

	// Ищем самое длинное  и самое короткое слово
	int tmpDlinaMax = strlen(massiv[0]), tmpDlinaMin = strlen(massiv[0]);
	string tmpSlovoMax = massiv[0], tmpSlovoMin = massiv[0];

	for (int i = 1; i < colSlovMassiv - 1; i++)
	{
		if (strlen(massiv[i]) > tmpDlinaMax) {
			tmpDlinaMax = strlen(massiv[i]);
			tmpSlovoMax = massiv[i];
		}
		else if (strlen(massiv[i]) < tmpDlinaMin) {
			tmpDlinaMin = strlen(massiv[i]);
			tmpSlovoMin = massiv[i];
		}
	}

	// Вывод самого длинного и самого короткого слова
	cout << endl << endl << "Самое длинное слово: " << tmpSlovoMax << endl
		<< "Его длина: " << tmpDlinaMax << endl << endl
		<< "Самое короткое слово: " << tmpSlovoMin << endl
		<< "Его длина: " << tmpDlinaMin << endl;

	system("pause >> void");
	return 0;
}