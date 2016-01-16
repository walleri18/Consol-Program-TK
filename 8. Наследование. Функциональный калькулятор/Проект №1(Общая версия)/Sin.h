#pragma once
#define _USE_MATH_DEFINES
#include "CalculateFunction.h"
#include <cmath>

class Sin :
	public CalculateFunction
{
// Данные
private:
	double argument;// Аргумент для функции asin
	double result;// результат вычислений
// Функции (методы)
public:
	Sin();// Конструктор без параметров
	char *getName();// Геттер имени asin
	void show();// Вывод
private:
	void calculate();// Вычисление функции asin
	void setArgument();// Сеттер аргумента функции
	static double translateGradus(double);// Функция перевода градусов в радианы
	static double translateRadian(double);// Функция перевода радиан в градусы
};

