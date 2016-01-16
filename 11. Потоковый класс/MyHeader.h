#ifdef UNICODE
#undef UNICODE 
#endif

#include <locale>
#include <Windows.h>
#include <iostream>

// Наш потоковый класс вывода для строк
class COut
{	
// Функции (методы)
public:
	
	// Операция вывода в поток для остальных типов данных
	template <typename Type>
	void operator << (Type message)
	{
		// Выводим на экран
		std::cout << message << std::endl;
	}

	// Операция вывода в поток для символов
	void operator << (const char *message)
	{
		// Создаём буферный массив, где будет перевод
		char *tmp = new char[strlen(message) + 1];

		// Перевод
		CharToOemA(message, tmp);

		// Выводим на экран
		printf("%s\n", tmp);
	}
	
	
};

// Создаём объект потока
COut COUT;

// Подменяем поток своим
#define cout COUT