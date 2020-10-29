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
		<< "10. ИТЕРАТОРЫ" << std::endl;

}


int main() {
	setlocale(LC_ALL, "ru");
	Binary_tree<int, int> tree;
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
			std::cout << tree.get(key) << std::endl;
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
		default:
			k = false;
			break;
		}

	}


	system("Pause");
	return 0;
}