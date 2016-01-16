#include "FunctionWithTwoArguments.h"


// конструктор по умолчанию
FunctionWithTwoArguments::FunctionWithTwoArguments()
{
}

// конструктор с двумя параметрами
FunctionWithTwoArguments::FunctionWithTwoArguments(function2 releaseFunction, string nameFunction) : CalculateFunction(releaseFunction, nameFunction)
{
}

// деструктор по умолчанию
FunctionWithTwoArguments::~FunctionWithTwoArguments()
{
}

void FunctionWithTwoArguments::setArgument()
{
	// Ввод первого аргумента
	CalculateFunction::setArgument();

	// Ввод второго аргумента
	cout << endl << "Введите аргумент №2: ";
	cin >> this->argument2;
}

void FunctionWithTwoArguments::show()
{
	if (releaseFunction2 == NULL) {
		cout << endl << "Не корректный ввод!!!" << endl;
		exit(1);
	}
	else
		cout << endl << nameFunction << "(" << argument1 << ", " << argument2 << ") = " << calculation() << endl;
}

double FunctionWithTwoArguments::calculation()
{
	return releaseFunction2(argument1, argument2);
}
