#include <iostream>
#include "BTS.h"
#include "Test.h"
#include <locale.h>

int main() {
	setlocale(LC_ALL, "ru");

	int n;
	std::cout << "���������� ���������: ";
	std::cin >> n;
	std::cout << std::endl << "���� ����������� �������� ���������� BST-������" << std::endl;
	test_rand(n);
	std::cout << std::endl << std::endl << "���� ����������� �������� ������������ BST-������" << std::endl;
	test_ord(n);

	system("pause");
	return 0;
}