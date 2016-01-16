/*
	Практика программирования. ТК.
	Решение: Задача на тему наследование. Функциональный калькулятор
	Автор: Туров Виталий Александрович
	Группа: 514
*/
/*
	Проект №1.
	Разработать программу, имитирующую работу функционального калькулятора, который
	позволяет выбирать с помщью меню какую-либо из известных ему функций, затем 
	предлагает ввести значение аргумента и после ввода выдаёт соответствующее значение функции.
	Для реализации возможности простой модернизации программы в дальнейшем,
	придерживаться следующих рекомендаций:
	а) Описать абстрактный базовый класс для представления любой функции
	(интерфейс поведения любой функции). Класс должен содержать чисто виртуальную функцию, которая реализуется в классах-потомках
	(конкретных математических функциях). Эта функция организует диалог с пользователем
	(запрос аргумента(ов), вычисление и выдача результата).
	б) В клиентской части программы (main и, возможно, другие функции) объявить и заполнить массив указателей на объекты существующих классов математических функций.
	Данный массив использовать при формировании меню и при вычислении выбранной пользователем функции.
*/

#ifdef UNICODE
#undef UNICODE
#endif

#include <locale.h>
#include <Windows.h>

#include <iostream>

// Библиотека наших классов
#include "LibraryFunctions.h"

using namespace std;

// Точка входа

int main(void)
{
	setlocale(LC_ALL, "ru"); // Установка кодировки windows-1251
	// Приветствие
	cout << "Добро пожаловать в программу функционального калькулятора!!!" << endl
		<< "Защита от идиота не предусмотрена!!!" << endl << endl;
	
	// Переменная выбора функции
	int functionSelection(0);

	// Вывод меню и ввод номера функции плюс защита от неправильного ввода
	do
	{
		// Вывод меню функций
		Function::outputMenu();

		// Ввод номера функции из меню
		cin >> functionSelection;

		// Уменьшаем на единицу из-за того индексация массива начинается с нуля
		functionSelection--;

	} while (functionSelection < ACOS || functionSelection > TANH);

	// Выбор функции
	CalculateFunction *fun(NULL);

	switch (functionSelection)
	{
	case ACOS:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1, function[functionSelection].name);
		break;
	case ASIN:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1, function[functionSelection].name);
		break;
	case ATAN:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1, function[functionSelection].name);
		break;
	case ATAN2:
		fun = new FunctionWithTwoArguments(function[functionSelection].releaseFunction2, function[functionSelection].name);
		break;
	case CEIL:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1, function[functionSelection].name);
		break;
	case COS:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1, function[functionSelection].name);
		break;
	case COSH:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1, function[functionSelection].name);
		break;
	case EXP:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1, function[functionSelection].name);
		break;
	case FABS:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1, function[functionSelection].name);
		break;
	case FLOOR:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1, function[functionSelection].name);
		break;
	case FMOD:
		fun = new FunctionWithTwoArguments(function[functionSelection].releaseFunction2, function[functionSelection].name);
		break;
	case FREXP:
		fun = new FunctionWithTwoArguments(function[functionSelection].releaseFunction2, function[functionSelection].name);
		break;
	case LOG:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1, function[functionSelection].name);
		break;
	case LOG10:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1, function[functionSelection].name);
		break;
	case POW:
		fun = new FunctionWithTwoArguments(function[functionSelection].releaseFunction2, function[functionSelection].name);
		break;
	case SIN:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1, function[functionSelection].name);
		break;
	case SINH:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1, function[functionSelection].name);
		break;
	case SQRT:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1, function[functionSelection].name);
		break;
	case TAN:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1, function[functionSelection].name);
		break;
	case TANH:
		fun = new FunctionWithOneArgument(function[functionSelection].releaseFunction1, function[functionSelection].name);
		break;
	}

	// Установка аргументов
	fun->setArgument();

	// Вывод результатов
	fun->show();

	system("pause >> void");
	return 0;
}