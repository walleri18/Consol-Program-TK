#include "CalculateFunction.h"


// конструктор по умолчанию
CalculateFunction::CalculateFunction()
{
}

// конструктор с двум¤ параметрами
CalculateFunction::CalculateFunction(function1 releaseFunction, string nameFunction) : nameFunction(nameFunction)
{
	this->releaseFunction1 = releaseFunction;
}

// конструктор с двум¤ параметрами
CalculateFunction::CalculateFunction(function2 releaseFunction, string nameFunction) : nameFunction(nameFunction)
{
	this->releaseFunction2 = releaseFunction;
}

// деструктор по умолчанию
CalculateFunction::~CalculateFunction()
{
}

// сеттер аргумента
void CalculateFunction::setArgument()
{
	cout << endl << "¬ведите аргумент є1: ";
	cin >> this->argument1;
}

// вычисление функции
double CalculateFunction::calculation()
{
	return this->releaseFunction1(this->argument1);
}
