#pragma once
#include "CalculateFunction.h"

// Класс функций с двумя аргументами
class FunctionWithTwoArguments :
	public CalculateFunction
{
// Данные
protected:
	double argument2;// аргумент номер 2
// Функции(методы)
public:
	FunctionWithTwoArguments();// конструктор по умолчанию
	FunctionWithTwoArguments(function2, string);// конструктор с двумя параметрами
	~FunctionWithTwoArguments();// деструктор по умолчанию
	void setArgument();// сеттер аргументов
	void show();// функция вывода вычислений
protected:
	double calculation();// вычисление функции
};

