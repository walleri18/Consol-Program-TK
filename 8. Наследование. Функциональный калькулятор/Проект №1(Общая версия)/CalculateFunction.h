#pragma once
#include <iostream>
using namespace std;

// Абстрактный общий класс для функций
class CalculateFunction
{	
protected:
	char *functionName;// Имя функции

// Функции(методы)
public:
	virtual char *getName() = 0;// Чисто виртуальная функция геттера имени
	virtual void setArgument() = 0;// Чисто виртуальная функция сеттера аргумента
	virtual void calculate() = 0;// Чисто виртуальная функция вычисления необходимой функции
	virtual void show() = 0;// Чисто виртуальная функция вывода
};