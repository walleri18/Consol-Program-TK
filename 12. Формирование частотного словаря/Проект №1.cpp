/*
	Практика программирования. ТК.
	Решение: формирование частотного словаря
	Автор: Туров Виталий Александрович
	Группа: 514
	*/
/*
	Проект №1.
	Написать программу формирования частотного словаря появления отдельных слов в
	некотором тексте. Исходных текс читается из файла "readme.txt", результат - 
	частотный словарь - записывается в файл "word_freq.txt", а также выводится на экран.
	Требования:
	а) Файловый ввод-вывод реализовать при помощи файловых потоков ifstream и ofstream.
	б) Словарь организовать при помощи ассоциативного контейнера <map>, в котором в качестве
	элемента - количество вхождений данного слова в текст.
	в) При выводе обеспечить выравнивание текста по правому краю (использовать манипуляторы
	setw(n), left, right).
	*/

#ifdef UNICODE
#undef UNICODE
#endif

#include <locale.h>
#include <Windows.h>

#include <fstream>
#include <iostream>
#include <map>
#include <iomanip>
#include <string>
using namespace std;

// Точка входа

int main(void)
{
	setlocale(LC_ALL, ".1251"); // Установка кодировки windows-1251

	// Приветствие
	cout << "Добро пожаловать в программу формирования частотного словаря!!!" << endl << endl;

	// Создание файлового потока ввода
	ifstream inStream;

	// Попытка открытия файлового потока
	inStream.open("readme.txt", ios::in);

	// Проверка на ошибку открытия
	if (!inStream.is_open()) {
		cout << "Ошибка открытия файла \"readme.txt\"!!!" << endl;
		system("pause >> void");
		exit(0);
	}

	// Создание хранилищя для словаря
	map<string, int> dictionary;

	// Буферное слово
	string word;

	// Создание итератора для map<string, int>
	map<string, int>::iterator it;

	// Считывание в хранилище из потока ввода файла
	for (;;)
	{
		// Cчитывание из файлового потока
		inStream >> word;

		// Если достигнут конец файла
		if (inStream.eof()) break;

		// Увеличение счётчика слова в словаре
		dictionary[word]++;
	}

	// Создание потока вывода в файл "word_freq.txt"
	ofstream outStream;

	// Попытка открытия файлового потока
	outStream.open("word_freq.txt", ios::out | ios::trunc);

	// Проверка на ошибку открытия
	if (!outStream.is_open()) {
		cout << "Ошибка открытия файла \"word_freq.txt\"!!!" << endl;
		system("pause >> void");
		exit(0);
	}

	// Вывод данных из словаря
	for (it = dictionary.begin(); it != dictionary.end(); it++)
	{
		cout << setw(29) << left << it->first << ": " << right << it->second << endl;
		outStream << setw(29) << left << it->first << ": " << right << it->second << endl;
	}

	system("pause >> void");
	return 0;
}