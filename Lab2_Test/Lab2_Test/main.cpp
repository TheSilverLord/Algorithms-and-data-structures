#include <iostream>
#include "BTS.h"
#include "Test.h"
#include <locale.h>

int main() {
	setlocale(LC_ALL, "ru");

	int n;
	std::cout << "Количество элементов: ";
	std::cin >> n;
	std::cout << std::endl << "Тест трудоёмкости операций случайного BST-дерева" << std::endl;
	test_rand(n);
	std::cout << std::endl << std::endl << "Тест трудоёмкости операций вырожденного BST-дерева" << std::endl;
	test_ord(n);

	system("pause");
	return 0;
}