#include <iostream>
#include "BTS.h"
#include <locale.h>
void menu() {
	std::cout << "1. Добавить элемент в дерево" << std::endl
		<< "2. Размер дерева" << std::endl
		<< "3. Проверка дерева на пустоту" << std::endl
		<< "4. Вывести значение по ключу" << std::endl
		<< "5. Изменить значение по ключу" << std::endl
		<< "6. Удалить значение по ключу" << std::endl
		<< "7. Список ключей" << std::endl
		<< "8. Вывести дерево" << std::endl
		<< "9. Очистить дерево" << std::endl
		<< "10. Подсчет элементов, которые больше заданного числа" << std::endl
		<< "11. Итератор: Операция *\n" 
		<< "12. Итератор: Операция ++\n"
		<< "13. Итератор: Операция --\n" 
		<< "14. Риверс Итератор: Операция *\n" 
		<< "15. Риверс Итератор: Операция ++\n" 
		<< "16. Риверс Итератор: Операция --\n"
		<< "17. Проверка итератора на конец\n" 
		<< "18. Проверка реверсного итератора на конец\n" 
		<< "19. Установка итератора на начало\n"
		<< "20. Установка реверсного итератора на начало\n" 
		<< "21. Запись с помощью итератора\n" 
		<< "22. Запись с помощью реверсного итератора\n";

}


int main() {
	setlocale(LC_ALL, "ru");
	Binary_tree<int, int> tree;
	Binary_tree<int, int>::Iterator* it = NULL;
	Binary_tree<int, int>::r_Iterator* it1 = NULL;
	bool k = true;
	while (k) {
		menu();
		int _k;
		std::cin >> _k;
		switch (_k)
		{
		case 1: {
			int val, key;
			std::cin >> key >> val;
			tree.insert(key,val);
			break; }
		case 2: {
			std::cout << tree.getSize() << std::endl;
			break; }
		case 3: {
			std::cout << tree.is_empty() << std::endl;
			break; }
		case 4: {
			int  key;
			std::cin >> key;
			try
			{
				std::cout << tree.get(key) << std::endl;
			}
			catch (...)
			{
				std::cout << "Exception" << std::endl;
			}
			break; }
		case 5: {
			int val, key;
			std::cin >> key >> val;
			std::cout << tree.change(key, val) << std::endl;
			break; }
		case 6: {
			int  key;
			std::cin >> key;
			std::cout << tree.remove(key) << std::endl;
			break; }
		case 7: {
			int* x = tree.keys();
			for (int i = 0; i < tree.getSize(); i++) {
				std::cout << x[i] << " ";
			}
			std::cout << std::endl;
			break; }
		case 8: {
			tree.show();
			break; }
		case 9: {
			tree.clear();
			break; }
		case 10: {
			int val;
			std::cin >> val;
			std::cout << tree.count(val);
			break; }
		case 11: {
			if (it == NULL){
				std::cout << "Error" << std::endl;
				break;
			}
			try{
				std::cout << *(*it) << std::endl;
			}
			catch (...){
				std::cout << "Exception" << std::endl;
			}
			break;
		}
		case 12: {
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
		case 13: {
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
		case 14: {
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
		case 15: {
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
		case 16: {
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
		case 17:
		{
			if (it == NULL)
			{
				std::cout << "Error" << std::endl;
				break;
			}
			if (*it != tree.end()) std::cout << 0 << std::endl;
			else {
				std::cout << 1 << std::endl;
			}
			break;
		}
		case 18:
		{
			if (it1 == NULL)
			{
				std::cout << "Error" << std::endl;
				break;
			}
			if (*it1 != tree.rend()) std::cout << 0 << std::endl;
			else {
				std::cout << 1 << std::endl;
			}
			break;
		}
		case 19:
		{
			if (it == NULL) it = new Binary_tree<int, int >::Iterator(&tree);
			it = tree.begin();
			break;
		}
		case 20:
		{
			if (it1 == NULL) it1 = new Binary_tree<int, int >::r_Iterator(&tree);
			it1 = tree.rbegin();
			break;
		}
		case 21:
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
		case 22:
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
			k = false;
			break; }
		}

	}

	return 0;
}