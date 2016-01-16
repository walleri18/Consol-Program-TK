#include "Pow.h"

// Конструктор без параметров
Pow::Pow()
{
	this->functionName = "pow";
}

// Деструктор без параметров
Pow::~Pow()
{
}

// Геттер имени
char* Pow::getName()
{
	return this->functionName;
}

// Ввод данных
void Pow::setArgument()
{
	cout << endl << "Введите число, которое должно возвестись в степень: ";
	cin >> this->argument;

	cout << endl << "Введите степень, в которое должно возвестись число: ";
	cin >> this->step;
}

// Расчёт
void Pow::calculate()
{
	this->setArgument();

	this->result = pow(this->argument, this->step);
}

// Вывод результата
void Pow::show()
{
	this->calculate();

	cout << endl << "Результат работы функции " << this->getName() << "(" << this->argument << ", " 
		<< this->step << ") = " << this->result << endl;
}