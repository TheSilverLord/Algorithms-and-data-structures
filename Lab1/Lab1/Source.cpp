//2 вариант
#include <iostream>
#include <locale.h>
#include <String>
#include "List.h"

int main() {
	setlocale(LC_ALL, "Rus");
	List<int> *list= NULL;
	bool n = true;
	List<int>::Iterator* it = NULL;
	List<int>::reverse_Iterator* it1 = NULL;
	while (n) {
		int k;
		std::cout << "\t\tMenu\n" << "1. Добавить элемент в массив\n" << "2. Добавить элемент по номеру\n"
			<< "3. Размер массива\n" << "4.Удалить элемент\n" << "5. Удалить элемент по номеру\n"
			<< "6. Очистить массив\n" << "7. Проверить на пустоту\n" << "8. Проверить, есть ли элемент в массиве\n"
			<< "9. Изменить значение по номеру\n" << "10. Вывести значение по номеру\n" << "11. Вывести позицию заданного элемента\n"
			<< "12. Вывести массив на экран\n" << "13. Число просмотренных элементов\n" << "14. Итератор: Операция *\n" << "15. Итератор: Операция ++\n"
			<< "16. Итератор: Операция --\n" << "17. Риверс Итератор: Операция *\n" << "18. Риверс Итератор: Операция ++\n" << "19. Риверс Итератор: Операция --\n" 
			<< "20. Задание емкости\n" << "21. Проверка итератора на конец\n" << "22. Проверка реверсного итератора на конец\n" << "23. Установка итератора на начало\n"
			<< "24. Установка реверсного итератора на начало\n" << "25. Запись с помощью итератора\n" << "26. Запись с помощью реверсного итератора\n";
		std::cin >> k;

		switch (k)
		{
		case 1: { // Добавить элемент в массив
			int value;
			std::cin >> value;
			list->add(value);
			std::cout << std::endl;
			break; }
		case 2: { // Добавить элемент по номеру
			int value, index;
			std::cin >> index >> value;
			std::cout << list->add(index, value);
			std::cout << std::endl;
			break; }
		case 3: { // Размер массива
			std::cout << list->getSize() << " " << list->getCapacity() << std::endl;
			break; }
		case 4: { // Удалить элемент
			int value;
			std::cin >> value;
			std::cout << list->deleteValue(value) << std::endl;
			break; }
		case 5: { // Удалить элемент по номеру
			int index;
			std::cin >> index;
			std::cout << list->deleteIndexVal(index) << std::endl;
			break; }
		case 6: { // Очистить массив
			list->clear();
			break; }
		case 7: { // Проверить на пустоту
			std::cout << list->isEmpty() << std::endl;
			break; }
		case 8: { // Проверить, есть ли элемент в массиве
			int value;
			std::cin >> value;
			std::cout << list->contains(value) << std::endl;
			break; }
		case 9: { // Изменить значение по номеру
			int value, index;
			std::cin >> index >> value;
			std::cout << list->set(index, value) << std::endl;
			break; }
		case 10: { // Вывести значение по номеру
			int index;
			std::cin >> index;
			try
			{
				std::cout << list->get(index) << std::endl;
			}
			catch (...)
			{
				std::cout << "Exception" << std::endl;
			}
			break; }
		case 11: { // Вывести позицию заданного элемента
			int value;
			std::cin >> value;
			std::cout << list->getIndex(value) << std::endl;
			break; }
		case 12: { // Вывести массив на экран
			int size = list->getSize();
			for (int i = 0; i < size; i++) {
				try
				{
					std::cout << list->get(i) << " ";
				}
				catch (...)
				{
					std::cout << "Exception" << std::endl;
				}
			}
			std::cout << std::endl;

			break; }
		case 13: { // Число просмотренных элементов
			std::cout << list->getSeenValCount() << std::endl;
			break; }
		case 14: {
			if (it == NULL)
			{
				std::cout << "Error" << std::endl;
				break;
			}
			try
			{
				std::cout << *(*it) << std::endl;
			}
			catch (...)
			{
				std::cout << "Exception" << std::endl;
			}
			break;
		}
		case 15: {
			if (it == NULL)
			{
				std::cout << "Error" << std::endl;
				break;
			}
			try
			{
				++(*it);
			}
			catch (...)
			{
				std::cout << "Exception" << std::endl;
			}
			break; }
		case 16: {
			if (it == NULL)
			{
				std::cout << "Error" << std::endl;
				break;
			}
			try
			{
				--(*it);
			}
			catch (...)
			{
				std::cout << "Exception" << std::endl;
			}
			break; }
		case 17: {
			if (it1 == NULL)
			{
				std::cout << "Error" << std::endl;
				break;
			}
			try
			{
				std::cout << **it1 << std::endl;
			}
			catch (...)
			{
				std::cout << "Exception" << std::endl;
			}
			break; }
		case 18: {
			if (it1 == NULL)
			{
				std::cout << "Error" << std::endl;
				break;
			}
			try
			{
				++(*it1);
			}
			catch (...)
			{
				std::cout << "Exception" << std::endl;
			}
			break; }
		case 19: {
			if (it1 == NULL)
			{
				std::cout << "Error" << std::endl;
				break;
			}
			try
			{
				--(*it1);
			}
			catch (...)
			{
				std::cout << "Exception" << std::endl;
			}
			break;
		}
		case 20: {
			int capacity;
			std::cin >> capacity;
			list = new List<int>(capacity);
			break;
		}
		case 21:
		{
			if (it == NULL)
			{
				std::cout << "Error" << std::endl;
				break;
			}
			if (*it != *list->end()) std::cout << 0 << std::endl;
			else {
				std::cout << 1 << std::endl;
			}
			break;
		}
		case 22:
		{
			if (it1 == NULL)
			{
				std::cout << "Error" << std::endl;
				break;
			}
			if (*it1 != *list->rend()) std::cout << 0 << std::endl;
			else {
				std::cout << 1 << std::endl;
			}
			break;
		}
		case 23:
		{
			if (it == NULL) it = new List<int>::Iterator(list);
			it = list->begin();
			break;
		}
		case 24:
		{
			if (it1 == NULL) it1 = new List<int>::reverse_Iterator(list);
			it1 = list->rbegin();
			break;
		}
		case 25:
		{
			int val;
			std::cin >> val;
			if (it == NULL)
			{
				std::cout << "Error" << std::endl;
				break;
			}
			try
			{
				**it = val;
			}
			catch (...)
			{
				std::cout << "Exception" << std::endl;
			}
			break;
		}
		case 26:
		{
			int val;
			std::cin >> val;
			if (it1 == NULL)
			{
				std::cout << "Error" << std::endl;
				break;
			}
			try
			{
				**it1 = val;
			}
			catch (...)
			{
				std::cout << "Exception" << std::endl;
			}
			break;
		}
		default: {
			n = false;
			break;
		}
		}


	}



	return 0;
}