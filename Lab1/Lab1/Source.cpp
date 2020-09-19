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
			std::cout << list.getSize() << " " << list.getCapacity() << std::endl;
			break; }
		case 4: { // Удалить элемент
			int value;
			std::cin >> value;
			std::cout << list.deleteValue(value) << std::endl;
			break; }
		case 5: { // Удалить элемент по номеру
			int index;
			std::cin >> index;
			std::cout << list.deleteIndexVal(index) << std::endl;
			break; }
		case 6: { // Очистить массив
			list.clear();
			break; }
		case 7: { // Проверить на пустоту
			std::cout << list.isEmpty() << std::endl;
			break; }
		case 8: { // Проверить, есть ли элемент в массиве
			int value;
			std::cin >> value;
			std::cout << list.contains(value) << std::endl;
			break; }
		case 9: { // Изменить значение по номеру
			int value, index;
			std::cin >> index >> value;
			std::cout << list.set(index, value) << std::endl;
			break; }
		case 10: { // Вывести значение по номеру
			int index;
			std::cin >> index;
			std::cout << list.get(index) << std::endl;
			break; }
		case 11: { // Вывести позицию заданного элемента
			int value;
			std::cin >> value;
			std::cout << list.getIndex(value) << std::endl;
			break; }
		case 12: { // Вывести массив на экран
			int size = list.getSize();
			for (int i = 0; i < size; i++) {
				std::cout << list.get(i) << " ";
			}
			std::cout << std::endl;

			break; }
		case 13: { // Число просмотренных элементов
			std::cout << list.getSeenValCount() << std::endl;
			break; }
		case 14: {break; }
		case 15: {break; }
		default:
			break;
		}


	}



	return 0;
}