#include "Exp.h"

// Конструктор без параметров
Exp::Exp()
{
	this->functionName = "exp";
}

// Деструктор без параметров
Exp::~Exp()
{
}

// Геттер имени
char* Exp::getName()
{
	return this->functionName;
}

// Ввод аргумента
void Exp::setArgument()
{
	cout << endl << "Введите степень экспоненты: ";
	cin >> this->step;
}

// Расчёт
void Exp::calculate()
{
	this->setArgument();

	this->result = exp(this->step);
}

// Вывод
void Exp::show()
{
	this->calculate();

	cout << endl << "Результат работы функции " << this->getName() << "("
		<< this->step << ") = " << this->result << endl;
}