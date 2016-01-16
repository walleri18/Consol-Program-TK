/*
	Практика программирования. ТК.
	Решение: Использование операторов
	Автор: Туров Виталий Александрович
	Группа: 514
*/
/*
	Проект №2.
	С помощью оператора switch, написать программу, в которой 
	по введённому номера недели выводила название этого дня недели. 
	При неверном номере дня недели выводилась бы ошибка.
	Написать программу так, что бы она закрывалась только при обнаружении ошибки.
*/

/*
	Псевдо код:
	1. Запросить номер дня недели;
	2. Вывести название это дня недели;
	3. В случае ошибки, вывести ошибку и завершить программу.
*/

#ifdef UNICODE
#undef UNICODE
#endif

#include <locale.h>
#include <Windows.h>

#include <iostream>

using namespace std;

// Точка входа

int main(void)
{
	setlocale(LC_ALL, ".1251"); // Установка кодировки windows-1251

	// Приветствие
	cout << "Добро пожаловать в программу по узнаванию дня неделии!!!" << endl << endl;
	
	// Константы понедельника и воскресенья
	const int MONDAY(1), SUNDAY(7);

	// Номер дня недели
	int dayOfTheWeek(0);

	// Цикличный ввод/вывод
	do
	{
		// Ввод номера дня недели
		cout << "Введите номер дня недели: ";
		cin >> dayOfTheWeek;

		cout << endl << endl;

		// Поиск вариантов
		switch (dayOfTheWeek)
		{
			// Если dayOfTheWeek == 1
			case 1:
			{
				cout << "ПОНЕДЕЛЬНИК" << endl << endl;
				break;// выход из switch
			}

			// Если dayOfTheWeek == 2
			case 2:
			{
				cout << "ВТОРНИК" << endl << endl;
				break;// выход из switch
			}

			// Если dayOfTheWeek == 3
			case 3:
			{
				cout << "СРЕДА" << endl << endl;
				break;// выход из switch
			}

			// Если dayOfTheWeek == 4
			case 4:
			{
				cout << "ЧЕТВЕРГ" << endl << endl;
				break;// выход из switch
			}

			// Если dayOfTheWeek == 5
			case 5:
			{
				cout << "ПЯТНИЦА" << endl << endl;
				break;// выход из switch
			}

			// Если dayOfTheWeek == 6
			case 6:
			{
				cout << "СУББОТА" << endl << endl;
				break;// выход из switch
			}

			// Если dayOfTheWeek == 7
			case 7:
			{
				cout << "ВОСКРЕСЕНЬЕ" << endl << endl;
				break;// выход из switch
			}

			// Если dayOfTheWeek не равно ни одному из данных значений
			default:
			{
				cout << "ОШИБКА!!! НЕТУ ТАКОГО ДНЯ НЕДЕЛИ" << endl;
			}
		}

	} while ((dayOfTheWeek >= MONDAY) && (dayOfTheWeek <= SUNDAY));

	system("pause");
	return 0;
}