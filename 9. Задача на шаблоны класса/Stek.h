#pragma once
#include <iostream>
using namespace std;

// Шаблонный класс стека
template <typename Type>
class Stek
{
// Данные
private:

	/*
	Структура элемента стека
	*/
	struct Item
	{
		Type info;// Информация элемента стека
		Item *previos;// Указатель на предыдущий элемент

		// Конструктор с двумя параметрами
		Item(Type info) : info(info), previos(NULL) {}
	};

	/*
	Данные стека
	*/
	Item* header;// Указатель на голову стека
	int size;// Размер стека
	int indexHeader;// Индекс вершины стека

// Функции (методы)
public:

	// Конструктор 1 параметром
	Stek(int size) : size(size), indexHeader(0), header(NULL)
	{
	}

	// Деструктор без параметров
	~Stek()
	{
		// Текущий элемент
		Item *current = this->header;

		// Удаление элементов стека
		while (current != NULL)
		{
			// Установление новой вершины стека
			this->header = current->previos;

			// Удаление старой вершины стека
			delete current;

			// Установление текущей вершины стека
			current = this->header;
		}
	}
	
	// Добавление элемента в стек
	void push(Type info)
	{
		// Проверка на выход за пределы стека
		if (this->indexHeader == this->size) {
			cout << endl << "Ошибка!!! Попытка переполнения стека!!!" << endl << endl;

			// Выход из метода
			return;
		}

		// Создаём новый элемент и заполняем его поля
		Item *element = new Item(info);

		// Проверяем на первенство элемента
		if (this->indexHeader == 0) {
			// Заносим адрес вершины стека
			this->header = element;
		}
		else {
			// Запоминаем старую вершину
			Item *oldHeader = this->header;

			// Заносим адрес вершины стека
			this->header = element;

			// Заносим адрес предыдущего элемента
			this->header->previos = oldHeader;
		}

		// Увеличиваем индекс
		this->indexHeader++;
	}

	// Считывание элемента из стека и удаление его
	Type pop()
	{
		// Проверка на нулевой элемент
		if (this->header == NULL) {
			cout << endl << "Ошибка!!! Попытка извлечения не существующего элемента стека!!!" << endl << endl;

			// Выход из метода
			return 0;
		}

		// Получаем информацию из вершины стека
		Type tmpInfoElement = this->header->info;

		// Уменьшение индекса вершины стека
		this->indexHeader--;

		// Запоминаем старую вершину стека
		Item *oldHeader = this->header;

		// Установление новой вершины стека
		this->header = this->header->previos;

		// Удалаяем старую вершину стека
		delete oldHeader;

		// Возвращаем информацию из элемента
		return tmpInfoElement;
	}

	// Дружественная операция вывода в поток
	friend ostream& operator << (ostream &stream, Stek& stek)
	{
		// Текущий элемент
		Item *current = stek.header;

		// Выводим все элементы стека в поток
		while (current != NULL)
		{
			// Вывод в поток
			stream << current->info << " ";

			// Спуск вниз по стеку
			current = current->previos;
		}

		// Для красоты
		stream << endl;

		// Возвращение потока
		return stream;
	}
};