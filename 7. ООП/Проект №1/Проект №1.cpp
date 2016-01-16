/*
	Практика программирования. ТК.
	Решение: объектно-ориентированное программирование
	Автор: Туров Виталий Александрович
	Группа: 514
*/
/*
	Проект №1.
	Создание простейшего класса комплексных чисел. Реализовать конструкторы (по
	умолчанию и с двумя параметрами для инициализации реальной и мнимой частей),
	операции для сложения и вычитани чисел, а также метод для вывода чисел на экран.
	Дополнительно: определить конструктор копирования и убедиться, что конструктор
	копирования, создаваемый компилятором по умолчанию, работает аналогично.
*/

#ifdef UNICODE
#undef UNICODE
#endif

#include <locale.h>
#include <Windows.h>

#include <iostream>
using namespace std;

// Класс комплексных чисел
class Сomplex
{
	// Поля класса
	double mnima;// Мнимая часть
	double realmnima;// Действительная часть
public:
	// Прототипы
	Сomplex();// Конструктор без параметров
	~Сomplex();// Деструктор без параметров
	Сomplex(double, double);// Конструктор с двумя параметрами
	Сomplex(const Сomplex&);//Конструктор копирования
	double summaRealСomplex(double);// Метод суммы действительных частей данного объекта с чем-то
	double summaMnimaСomplex(double);// Метод суммы мнимых частей данного объекта с чем-то
	double raznostRealСomplex(double);// Метод разности действительной части данного объекта с чем-то
	double razostMnimaСomplex(double);// Метод раности мнимой части данного объекта с чем-то
	void showСomplex();// Метод вывода действительной части и мнимой на экран
	double getMnima();// Геттер мнимой части
	double getRealMnima();// Геттер действительной части
};

// Конструктор без параметров
Сomplex::Сomplex()
{
	this->mnima = 0;
	this->realmnima = 0;
}

// Деструктор без параметров
Сomplex::~Сomplex()
{
	cout << "Уничтожение объекта" << endl;
}

// Конструктор с двумя параметрами
Сomplex::Сomplex(double mnima, double realmnima)
{
	this->mnima = mnima;
	this->realmnima = realmnima;
}

//Конструктор копирования
Сomplex::Сomplex(const Сomplex & obj)
{
	this->realmnima = obj.getRealMnima();
	this->mnima = obj.getMnima();
}

// Метод суммы действительных частей данного объекта с чем-то
double Сomplex::summaRealСomplex(double realmnima2)
{
	return (this->realmnima + realmnima2);
}

// Метод суммы мнимых частей данного объекта с чем-то
double Сomplex::summaMnimaСomplex(double mnima2)
{
	return (this->mnima + mnima2);
}

// Метод разности действительной части данного объекта с чем-то
double Сomplex::raznostRealСomplex(double realmnima2)
{
	return (this->realmnima - realmnima2);
}

// Метод раности мнимой части данного объекта с чем-то
double Сomplex::razostMnimaСomplex(double mnima2)
{
	return (this->mnima - mnima2);
}

// Метод вывода действительной части и мнимой на экран
void Сomplex::showСomplex()
{
	cout << "Действительная часть: " << this->realmnima << endl
		<< "Мнимая часть: " << this->mnima << endl;
}

// Геттер мнимой части
double Сomplex::getMnima()
{
	return this->mnima;
}

//Геттер Действительной части
double Сomplex::getRealMnima()
{
	return this->realmnima;
}

// Точка входа

int main(void)
{
	setlocale(LC_ALL, "ru"); // Установка кодировки windows-1251
	// Приветствие
	cout << "Добро пожаловать в программу по работе с классом комплексных чисел!!!" << endl << endl;

	// Первое комплексное число
	Komplex chislo1;

	// Второе комплексное число
	Komplex chislo2(10, -5);

	// Третье комплексное число
	Komplex chislo3(1, 1);

	//Демонстрация методов

	chislo1.summaRealKomplex(chislo2.getRealMnima());// Прибавление к действительной части первого комплексного числа действительную часть второго комплексного числа

	chislo1.summaMnimaKomplex(chislo2.getMnima());// Прибавление к мнимой части первого комплексного числа мнимую часть второго комплексного числа

	chislo1.showKomplex();// Вывод первого комплексного числа

	chislo2.raznostRealKomplex(chislo3.getRealMnima());// Вычитание из действительной части второго комплексного числа действительную часть третьего комплексного числа

	chislo2.razostMnimaKomplex(chislo3.getMnima());// Вычистание из мнимой части второго комплексного числа мнимую часть третьего комплексного числа

	chislo2.showKomplex();// Вывод второго комплексного числа

	chislo3.showKomplex();// Вывод третьего комплексного числа

	// Создание четвёртого комплексного числа на основе третьего
	Komplex chislo4(chislo3);

	chislo4.showKomplex();// Вывод четвёртого комплексного числа

	system("pause >> void");
	return 0;
}