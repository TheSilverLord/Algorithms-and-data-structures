#include <iostream>
#include "MainHashTable.h"
#include <locale>
void menu() {

	std::cout << "1. �������� ������� �� �����" << std::endl <<
		"2. ������� ������������ ������" << std::endl <<
		"3. ������� ���������� ��������� � �������" << std::endl <<
		"4. ����� ������� �������" << std::endl <<
		"5. �������� �������" << std::endl <<
		"6. ����� �� �����" << std::endl <<
		"7. �������� �� �����" << std::endl <<
		"8. ������� �������" << std::endl <<
		"9. ������ �����: ��� ������� � ��������� ��������" << std::endl <<
		"10. ������ �����: ���-������� � �������� ����������" << std::endl <<
		"11. ����� ����� �������������" << std::endl <<
		"12. ��������: �������� *\n"
		<< "13. ��������: �������� ++\n"
		<< "14. �������� ��������� �� �����\n"
		<< "15. ��������� ��������� �� ������\n"
		<< "16. ������ � ������� ���������\n";
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