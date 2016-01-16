#include "MyHeaderFunction.h"

// Функция №1
double function1(double var1, double var2)
{
	#ifdef rounding //если известен rounding
		return rounding(var1 + var2);
	#endif
		return (var1 + var2); // если неизвестен rounding
}

#undef rounding //Директива отменяющая действие макроса округления

// Функция №2
double function2(double var1, double var2)
{
	#ifdef rounding //если известен rounding
		return rounding(var1 + var2);
	#endif
		return (var1 + var2); // если неизвестен rounding
}