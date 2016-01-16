#include "String.h"

// Конструктор по уполчанию, без параметров
String::String()
{
	this->massiv = NULL;
	this->sizeMassiv = 1;
}

// Деструктор по умолчанию, без параметров
String::~String()
{
	//cout << endl << endl << "Уничтожение объекта..." << endl << endl;
}

// Конструктор из строки
String::String(const char *massiv)
{
	// Локальная переменная размера массива
	int sizeMassiv(1);

	// Определение размера массива до нуля символа
	for (int i = 0; massiv[i]; i++) sizeMassiv++;

	// Создание массива определённого размера
	char *massivString = new char[sizeMassiv];

	// Копирование в новый массив
	for (int i = 0; i < sizeMassiv; i++) {
		if (i == sizeMassiv) massivString[i] = '\0';
		else massivString[i] = massiv[i];
	}
	// Присвоение адреса новво созданного массива
	this->massiv = massivString;

	//Присвоение размера массива
	this->sizeMassiv = sizeMassiv + 1;
}

// Конструктор копирования
String::String(String *obj)
{
	this->massiv = obj->getMassiv();
	this->sizeMassiv = obj->getSizeMassiv();
}

// Геттер массива
char *String::getMassiv()
{
	return this->massiv;
}

// Геттер размера массива
int String::getSizeMassiv()
{
	return this->sizeMassiv;
}

// Вывод
void String::show()
{
	cout << "Значения массива: " << this->getMassiv() << endl << endl
		<< "Размер массива: " << this->sizeMassiv << endl << endl;
}

// Операция больше
bool String::operator > (String &str)
{
	return (this->sizeMassiv > str.getSizeMassiv());
}

// Операция присваивание или контаканация
String operator + (String& str1, String &str2)
{
	// Выяснение необходимого размера нового массива
	int sizeKnowMassiv = (str1.getSizeMassiv() + str2.getSizeMassiv()) - 1;

	// Создание нового массива
	char *knowMassiv = new char[sizeKnowMassiv];

	// Перепись массива
	for (int i = 0; i < str1.getSizeMassiv(); i++)
	{
		if (!str1.getMassiv()[i]) {
			for (int j(0), d(i); j < str2.getSizeMassiv(); j++, d++)
			{
				knowMassiv[d] = str2.getMassiv()[j];
			}
			break;
		}
		else knowMassiv[i] = str1.getMassiv()[i];
	}

	String knowObject(knowMassiv);

	return knowObject;
}

// Присваивание нового объекта к текущему
void String::operator = (String &str)
{
	this->massiv = str.getMassiv();
	this->sizeMassiv = str.getSizeMassiv();
}

// Метод перевода в верхний регистр
void String::upperCase()
{
	for (int i = 0; i < sizeMassiv; i++)
	{
		if (isLowerCase(massiv[i])) massiv[i] -= 32;
	}
}

// Метод перевода в нижний регистр
void String::lowerCase()
{
	for (int i = 0; i < sizeMassiv; i++)
	{
		if (isUpperCase(massiv[i])) massiv[i] += 32;
	}
}

// Метод проверки на верхний регистр
bool String::isUpperCase(char letter)
{
	if ((letter >= lowerLimitUpperRegisterLatin && letter <= upperBoundUpperCaseLatin) || (letter >= lowerLimitUpperRegisterRussia && letter <= upperBoundUpperCaseRussia)) return true;
	else return false;
}

// Метод проверки на нижний регистр
bool String::isLowerCase(char letter)
{
	if ((letter >= lowerBoundLowerCaseLatin && letter <= upperBoundLowerCaseLatin) || (letter >= lowerBoundLowerCaseRussia && letter <= upperBoundLowerCaseRussia)) return true;
	else return false;
}

