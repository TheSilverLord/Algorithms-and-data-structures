//2 вариант
#include <iostream>
#include <locale.h>
#include <String>
#include "List.h"

int main() {
	setlocale(LC_ALL, "Rus");
	List<int> list;
	bool n = true;
	while (n) {
		int k;
		std::cout << "\t\tMenu\n" << "1. Добавить элемент в массив\n" << "2. Добавить элемент по номеру\n"
			<< "3. Размер массива\n" << "4.Удалить элемент\n" << "5. Удалить элемент по номеру\n"
			<< "6.Очистить массив\n" << "7. Проверить на пустоту\n" << "8. Проверить, есть ли элемент в массиве\n"
			<< "9. Изменить значение по номеру\n" << "10. Вывести значение по номеру\n" << "11. Вывести позицию заданного элемента\n"
			<< "12. Вывести массив на экран\n" << "13. Число просмотренных элементов\n" << "14. ИТЕРАТОРЫ(ПОТОМ)\n";
		std::cin >> k;

		switch (k)
		{
		case 1: { // Добавить элемент в массив
			int value;
			std::cin >> value;
			list.add(value);
			std::cout << std::endl;
			break; }
		case 2: { // Добавить элемент по номеру
			int value,index;
			std::cin  >> index >> value;
			std::cout << list.add(index,value);
			std::cout << std::endl;
			break; }
		case 3: { // Размер массива
			std::cout << list.getSize() << std::endl;
			break; }
		case 4: { // Удалить элемент
			break; }
		case 5: { // Удалить элемент по номеру
			break; }
		case 6: { // Очистить массив
			break; }
		case 7: { // Проверить на пустоту
			break; }
		case 8: { // Проверить, есть ли элемент в массиве
			break; }
		case 9: { // Изменить значение по номеру

			break; }
		case 10: { // Вывести значение по номеру
			break; }
		case 11: { // Вывести позицию заданного элемента
			break; }
		case 12: { // Вывести массив на экран
			int size = list.getSize();
			for (int i = 0; i < size; i++) {
				std::cout << list.get(i) << " ";
			}
			std::cout << std::endl;

			break; }
		case 13: { // Число просмотренных элементов
			break; }
		case 14: {break; }
		case 15: {break; }
		default:
			break;
		}


	}



	return 0;
}