#pragma once
// —имвольные константы
//----------------------------------------------------------------------
#define NULL 0						// Ќулева¤ константа
#define lowerLimitUpperRegisterLatin 65 // нижн¤¤ граница верхнего регистра
#define upperBoundUpperCaseLatin 90     // верхн¤¤ граница верхнего регистра
#define lowerBoundLowerCaseLatin 97     // нижн¤¤ граница нижнего регистра
#define upperBoundLowerCaseLatin 122      // верхн¤¤ граница нижнего регистра
#define lowerLimitUpperRegisterRussia -64 // нижн¤¤ граница верхнего регистра
#define upperBoundUpperCaseRussia -33     // верхн¤¤ граница верхнего регистра
#define lowerBoundLowerCaseRussia -32     // нижн¤¤ граница нижнего регистра
#define upperBoundLowerCaseRussia -1      // верхн¤¤ граница нижнего регистра
//----------------------------------------------------------------------
#include <iostream>
#include <fstream>
using namespace std;

class String
{
	char *massiv; // ћассив символов
	int sizeMassiv;// –азмер массива символов
	bool isUpperCase(char);// ћетод проверки на верхний регистр
	bool isLowerCase(char);// ћетод проверки на нижний регистр
public:
	// ѕрототипы
	String();//  онструктор по умолчанию, без параметров
	~String();// ƒеструктор по умолчанию, без параметров
	String(const char*);//  онструктор  из строки символов
	String(String* obj);//  онструктор копировани¤
	char *getMassiv();// √еттер указател¤ массива
	int getSizeMassiv();// √еттер размера массива
	void show();// ¬ывод данных на экран
	bool operator > (String&);// ќпераци¤ больше
	void operator = (String&);// ќпераци¤ присваивани¤ нового объекта к текущему
	void upperCase();// ћетод перевода в верхний регистр
	void lowerCase();// ћетод перевода в нижний регистр
};
String operator + (String&, String&);// ќпераци¤ контаканаци¤