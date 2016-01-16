#include "Sin.h"

// Конструктор по умолчанию
Sin::Sin()
{
	this->functionName = "sin";
}

// Геттер имени аркосинуса
char* Sin::getName()
{
	return this->functionName;
}

// Сеттер аргумента функции
void Sin::setArgument()
{
	// Запрос и ввод аргумента
	cout << endl << "Введите аргумент (в градусах): ";
	cin >> this->argument;

	// Перевод аргумента в радианы
	this->argument = this->translateGradus(this->argument);
}

// Вычисление функции acos
void Sin::calculate()
{
	// Ввод аргумента и преобразование его в радианы
	this->setArgument();

	// Вычисление и возврат результата
	this->result = sin(this->argument);

	this->result = this->translateRadian(this->result);
}

// Вывод
void Sin::show()
{
	// Вычисления
	this->calculate();

	// Вывод
	cout << endl << "Результаты работы функции " << this->getName() << "(" << this->argument << ") = " << this->result << endl;
}

// Функция перевода градусов в радианы
double Sin::translateGradus(double gradus)
{
	double radian = (gradus * M_PI) / 180;

	return radian;
}

// Функция перевода радиан в градусы
double Sin::translateRadian(double radian)
{
	double gradus = (radian * 180) / M_PI;

	return gradus;
}