#pragma once
#include "CalculateFunction.h"
#include "FunctionWithOneArgument.h"
#include "FunctionWithTwoArguments.h"

enum {
	ACOS, ASIN, ATAN, ATAN2, CEIL, COS, COSH, EXP, FABS, FLOOR, FMOD, FREXP, LOG, LOG10, POW, SIN, SINH, SQRT, TAN, TANH
};

struct Function
{
	string name;// им¤ функции
	CalculateFunction::function1 releaseFunction1;// указатель на функцию первого типа с одним аргументом
	CalculateFunction::function2 releaseFunction2;// указатель на функцию второго типа с двум¤ аргументами

	static inline void outputMenu()
	{
		cout << endl << "¬ведите номер интерисующей вас функции" << endl
		<< "1. acos" << endl
		<< "2. asin" << endl
		<< "3. atan" << endl
		<< "4. atan2" << endl
		<< "5. ceil" << endl
		<< "6. cos" << endl
		<< "7. cosh" << endl
		<< "8. exp" << endl
		<< "9. fabs" << endl
		<< "10. floor" << endl
		<< "11. fmod" << endl
		<< "12. frexp (не существует!!!)" << endl
		<< "13. log" << endl
		<< "14. log10" << endl
		<< "15. pow" << endl
		<< "16. sin" << endl
		<< "17. sinh" << endl
		<< "18. sqrt" << endl
		<< "19. tan" << endl
		<< "20. tanh" << endl
			<< endl << endl;
	}

} function[20] = 
{
	{ "acos", acos, NULL },
	{ "asin", asin, NULL },
	{ "atan", atan, NULL },
	{ "atan2", NULL, atan2 },
	{ "ceil", ceil, NULL },
	{ "cos", cos, NULL },
	{ "cosh", cosh, NULL },
	{ "exp", exp, NULL },
	{ "fabs", fabs, NULL },
	{ "floor", floor, NULL },
	{ "fmod", NULL, fmod },
	//{ "frexp", NULL, frexp },
	{ "log", log, NULL },
	{ "log10", log10, NULL },
	{ "pow", NULL, pow },
	{ "sin", sin, NULL },
	{ "sinh", sinh, NULL },
	{ "sqrt", sqrt, NULL },
	{ "tan", tan, NULL },
	{ "tanh", tanh, NULL },
};