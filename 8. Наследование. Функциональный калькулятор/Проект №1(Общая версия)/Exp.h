#pragma once
#include "CalculateFunction.h"
class Exp :
	public CalculateFunction
{
// Данные 
	long step;// Возводимая степень
	
	double result;// Результат
// Функции (методы)
public:
	Exp();// Конструктор без параметров
	~Exp();// Деструктор без параметров
	char *getName();// Геттер имени
	void show();// Вывод
private:
	void setArgument();// установка аргумента
	void calculate();// Расчёт
};

