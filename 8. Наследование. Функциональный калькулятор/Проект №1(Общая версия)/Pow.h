#pragma once
#include "CalculateFunction.h"
class Pow :
	public CalculateFunction
{
// Данные
private:
	double argument;// Аргумент 
	double step;// Возводимая степень

	double result;// Результат возведения в степень
// Функции (методы)
public:
	Pow(); // Конструктор без параметров
	~Pow();// Деструктор без параметров
	char *getName();// Геттер имени
	void show();// Вывод результата
private:
	void setArgument();// Сеттер аргумента и степени
	void calculate();// Расчёт
};

