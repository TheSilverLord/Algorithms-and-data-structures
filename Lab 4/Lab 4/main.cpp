#include <iostream>
#include "MainHashTable.h"
#include <locale>
void menu() {

	std::cout << "1. Добавить элемент по ключу" << std::endl <<
		"2. Вывести максимальный размер" << std::endl <<
		"3. Вывести количество элементов в таблице" << std::endl <<
		"4. Опрос пустоты таблицы" << std::endl <<
		"5. Очистить таблицу" << std::endl <<
		"6. Поиск по ключу" << std::endl <<
		"7. Удаление по ключу" << std::endl <<
		"8. Вывести таблицу" << std::endl <<
		"9. Задать форму: Хэш таблица с цепочками значений" << std::endl <<
		"10. Задать форму: Хэш-таблица с открытой адресацией" << std::endl <<
		"11. Опрос формы представления" << std::endl <<
		"12. Итератор: Операция *\n"
		<< "13. Итератор: Операция ++\n"
		<< "14. Проверка итератора на конец\n"
		<< "15. Установка итератора на начало\n"
		<< "16. Запись с помощью итератора\n";
}


int main() {
	setlocale(LC_ALL, "rus");
	MainHashTable<std::string, int> HT;
	MainHashTable<std::string, int>::Iterator* it = NULL;
	bool is = true;
	while (is) {
		menu();
		int k;
		std::cin >> k;
		switch (k)
		{
		case 1: {
			std::string k;
			std::cin >> k;
			int data;
			std::cin >> data;
			std::cout << HT.insert(k, data) << std::endl;
			break;
		}
		case 2: {
			std::cout << HT.getMax_size()<< std::endl;
			break;
		}
		case 3: {
			std::cout << HT.getSize() << std::endl;
			break;
		}
		case 4: {
			std::cout << HT.is_empty() << std::endl;
			break;
		}
		case 5: {
			HT.clear();
			break;
		}
		case 6: {
			std::string k;
			std::cin >> k;
			std::cout << HT.find(k) << std::endl;
			break;
		}
		case 7: {
			std::string k;
			std::cin >> k;
			std::cout << HT.remove(k) << std::endl;
			break;
		}
		case 8: {
			HT.show();
			break;
		}
		case 9: {
			HT.changeTable(true);
			break;
		}
		case 10: {
			HT.changeTable(false);
			break;
		}
		case 11: {
			std::cout << HT.isChain() << std::endl;
			break;
		}
		case 12: {
			if (it == NULL) {
				std::cout << "Error" << std::endl;
				break;
			}
			try {
				
				std::cout << *(*it) << std::endl;
			}
			catch (int) {
				std::cout << "Nothing" << std::endl;

			}
			catch (...) {
				std::cout << "Exception"  << std::endl;
			}
			break;
		}
		case 13: {
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
			break; 
		}
		case 14: {
			if (it == NULL)
			{
				std::cout << "Error" << std::endl;
				break;
			}
			if (*it != HT.end()) std::cout << 0 << std::endl;
			else {
				std::cout << 1 << std::endl;
			}
			break;
		}
		case 15: {
			if (it == NULL) it = new MainHashTable<std::string, int>::Iterator(&HT);
			it = HT.begin();
			break;
		}
		case 16: {
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
		default:
			break;
		}
	}





	return 0;
}