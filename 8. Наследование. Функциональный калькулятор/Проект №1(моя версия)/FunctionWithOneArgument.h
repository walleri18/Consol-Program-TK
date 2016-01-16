#pragma once
#include "CalculateFunction.h"

//  ласс функций с одним аргументом
class FunctionWithOneArgument :
	public CalculateFunction
{
// ‘ункции(методы)
public:
	FunctionWithOneArgument();// конструктор по умолчанию
	FunctionWithOneArgument(function1, string);// конструктор с двум¤ параметрами
	~FunctionWithOneArgument();// деструктор по умолчанию
	void show();// функци¤ вывода
};

