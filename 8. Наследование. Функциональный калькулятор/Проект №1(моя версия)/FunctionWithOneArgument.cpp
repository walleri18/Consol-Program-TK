#include "FunctionWithOneArgument.h"


// конструктор по умолчанию
FunctionWithOneArgument::FunctionWithOneArgument()
{
}

// конструктор с двумя параметрами
FunctionWithOneArgument::FunctionWithOneArgument(function1 releaseFunction, string nameFunction) : CalculateFunction(releaseFunction, nameFunction)
{
}

// деструктор по умолчанию
FunctionWithOneArgument::~FunctionWithOneArgument()
{
}

// функция вывода
void FunctionWithOneArgument::show()
{
	if (this->releaseFunction1 == NULL) {
		cout << endl << "Не корректный ввод!!!" << endl;
		exit(1);
	}
	else
		cout << endl << nameFunction << "(" << argument1 << ") = " << calculation() << endl;
}
