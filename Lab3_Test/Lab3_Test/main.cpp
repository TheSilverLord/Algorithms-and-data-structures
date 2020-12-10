#include <iostream>
#include <time.h>
#include <math.h>
#include "BTS.h"
#include "RBTS.h"
#include <locale.h>
using namespace std;
typedef unsigned long long INT_64;

//переменная и константы генератора LineRand()
static INT_64 RRand = 15750; const INT_64 mRand = (1 << 63) - 1;
const INT_64 aRand = 6364136223846793005;
const INT_64 cRand = 1442695040888963407;

//функция установки первого случайного числа от часов компьютера
void sRand() { srand(time(0)); RRand = (INT_64)rand(); }

//функция генерации случайного числа
//линейный конгруэнтный генератор    Xi+1=(a*Xi+c)%m
//habr.com/ru/post/208178
INT_64 LineRand()
{
    INT_64 y1, y2;
    y1 = (aRand * RRand + cRand) % mRand;
    y2 = (aRand * y1 + cRand) % mRand;
    RRand = y1 & 0xFFFFFFFF00000000LL ^ (y2 & 0xFFFFFFFF00000000LL) >> 32;
    //RRand = rand();
    return RRand;
}


// Тест трудоёмкости операций случайного BST-дерева
void test_rand(int n)
{
    //создание деревьев для 64 – разрядных ключей типа INT_64
    Binary_tree< INT_64, int >* tree = new Binary_tree<INT_64, int>();
    Random_tree< INT_64, int >* rtree = new Random_tree<INT_64, int>();
    //массив для ключей, которые присутствуют в дереве 
    INT_64* m = new INT_64[n];
    //установка первого случайного числа
    sRand();
    //заполнение дерева и массива элементами со случайными ключами
    for (int i = 0; i < n; i++)
    {
        m[i] = LineRand();
        tree->insert(m[i], 1);
        rtree->insert(m[i], 1);
    }
    //вывод размера дерева до теста
    cout << "BST items count:" << tree->getSize() << "\t\tRandom items count:" << rtree->getSize() << endl;
    //обнуление счётчиков трудоёмкости вставки, удаления и поиска
    int I = 0; int rI = 0;
    int D = 0; int rD = 0;
    int S = 0; int rS = 0;
    //генерация потока операций, 10% - промахи операций
    for (int i = 0; i < n / 2; i++)
        if (i % 10 == 0)		//10% промахов
        {
            tree->remove(LineRand());
            rtree->remove(LineRand());
            D += tree->getSeenValCount();
            rD += rtree->getSeenValCount();
            tree->insert(m[rand() % n], 1);
            rtree->insert(m[rand() % n], 1);
            I += tree->getSeenValCount();
            rI += rtree->getSeenValCount();
            try {
                tree->get(LineRand());
                S += tree->getSeenValCount();
            }
            //обработка исключения при ошибке операции поиска
            catch (...) { S += tree->getSeenValCount(); }
            try
            {
                rtree->get(LineRand());
                rS += rtree->getSeenValCount();
            }
            catch (...) { rS += rtree->getSeenValCount(); }
        }
        else  //90% успешных операций
        {
            int ind = rand() % n;
            tree->remove(m[ind]);
            rtree->remove(m[ind]);
            D += tree->getSeenValCount();
            rD += rtree->getSeenValCount();
            INT_64 key = LineRand();
            tree->insert(key, 1);
            rtree->insert(key, 1);
            I += tree->getSeenValCount();
            rI += rtree->getSeenValCount();
            m[ind] = key;
            try {
                tree->get(m[rand() % n]);
                S += tree->getSeenValCount();
            }
            //обработка исключения при ошибке операции поиска
            catch (...) { S += tree->getSeenValCount(); }
            try {
                rtree->get(m[rand() % n]);
                rS += rtree->getSeenValCount();
            }
            //обработка исключения при ошибке операции поиска
            catch (...) { rS += rtree->getSeenValCount(); }
        }	//конец теста

     //вывод результатов:
     //вывод размера дерева после теста
    cout << "BST items count:" << tree->getSize() << "\t\tRandom items count:" << rtree->getSize() << endl;
    //теоретической оценки трудоёмкости операций BST
    cout << "1.39*log2(n)=" << 1.39 * (log((double)n) / log(2.0)) << endl;
    //экспериментальной оценки трудоёмкости вставки
    cout << "BST Count insert: " << (double)I / (n / 2) << "\t\tRandom Count insert: " << (double)rI / (n / 2) << endl;
    //экспериментальной оценки трудоёмкости удаления
    cout << "BST Count delete: " << (double)D / (n / 2) << "\t\tRandom Count delete: " << (double)rD / (n / 2) << endl;
    //экспериментальной оценки трудоёмкости поиска
    cout << "BST Count search: " << (double)S / (n / 2) << "\t\tRandom Count search: " << (double)rS / (n / 2) << endl;
    //освобождение памяти массива m[]
    delete[] m;
}


// Тест трудоёмкости операций вырожденного BST-дерева
void test_ord(int n)
{
    //создание дерева для 64 – разрядных ключей типа INT_64
    Binary_tree< INT_64, int > tree;
    Random_tree< INT_64, int > rtree;
    //массив для ключей, которые присутствуют в дереве 
    INT_64* m = new INT_64[n];

    //заполнение дерева и массива элементами с возрастающими чётными ключами на интервале [0, 10000, 20000, ... ,10000*n]
    for (int i = 0; i < n; i++) {
        m[i] = i * 10000;
        tree.insert(m[i], 1);
        rtree.insert(m[i], 1);
    }
    //вывод размера дерева до теста 
    cout << "BST items count:" << tree.getSize() << "\t\tRandom items count:" << rtree.getSize() << endl;
    //обнуление счётчиков трудоёмкости вставки, удаления и поиска
    int I = 0; int rI = 0;
    int D = 0; int rD = 0;
    int S = 0; int rS = 0;
    //установка первого случайного числа 
    sRand();
    //генерация потока операций, 10% - промахи операций
    for (int i = 0; i < n / 2; i++)
    {
        if (i % 10 == 0)		//10% промахов
        {
            int k = LineRand() % (10000 * n);
            k = k + !(k % 2);	//случайный нечётный ключ
            tree.remove(k);
            D += tree.getSeenValCount();
            rtree.remove(k);
            rD += rtree.getSeenValCount();
            tree.insert(m[rand() % n], 1);
            I += tree.getSeenValCount();
            rtree.insert(m[rand() % n], 1);
            rI += rtree.getSeenValCount();
            k = LineRand() % (10000 * n);
            k = k + !(k % 2);	// случайный нечётный ключ
            try {
                tree.get(k);
                S += tree.getSeenValCount();
            }
            //обработка исключения при ошибке операции поиска
            catch (...) { S += tree.getSeenValCount(); }
            try {
                rtree.get(k);
                rS += rtree.getSeenValCount();
            }
            //обработка исключения при ошибке операции поиска
            catch (...) { rS += rtree.getSeenValCount(); }
        }
        else  //90% успешных операций
        {
            int ind = rand() % n;
            tree.remove(m[ind]);
            D += tree.getSeenValCount();
            rtree.remove(m[ind]);
            rD += rtree.getSeenValCount();
            int k = LineRand() % (10000 * n);
            k = k + k % 2;		// случайный чётный ключ
            tree.insert(k, 1);
            I += tree.getSeenValCount();
            rtree.insert(k, 1);
            rI += rtree.getSeenValCount();
            m[ind] = k;
            try {
                tree.get(m[rand() % n]);
                S += tree.getSeenValCount();
            }
            //обработка исключения при ошибке операции поиска
            catch (...) { S += tree.getSeenValCount(); }
            try {
                rtree.get(m[rand() % n]);
                rS += rtree.getSeenValCount();
            }
            //обработка исключения при ошибке операции поиска
            catch (...) { rS += rtree.getSeenValCount(); }
        }
    }
    //вывод результатов:
    // вывод размера дерева после теста
    cout << "BST items count:" << tree.getSize() << "\t\tRandom items count:" << rtree.getSize() << endl;
    //теоретической оценки трудоёмкости операций BST
    cout << "n/2 =" << n / 2 << "\t\t1.39*log2(n)=" << 1.39 * (log((double)n) / log(2.0)) << endl;
    //экспериментальной оценки трудоёмкости вставки
    cout << "BST Count insert: " << (double)I / (n / 2) << "\t\tRandom Count insert: " << (double)rI / (n / 2) << endl;
    //экспериментальной оценки трудоёмкости удаления
    cout << "BST Count delete: " << (double)D / (n / 2) << "\t\tRandom Count delete: " << (double)rD / (n / 2) << endl;
    //экспериментальной оценки трудоёмкости поиска
    cout << "BST Count search: " << (double)S / (n / 2) << "\t\tRandom Count search: " << (double)rS / (n / 2) << endl;
    //освобождение памяти массива m[]
    delete[] m;
}	//конец теста

int main() {
	setlocale(LC_ALL, "ru");

	int n;
	std::cout << "Количество элементов: ";
	std::cin >> n;
	std::cout << std::endl << "Тест трудоёмкости операций случайных деревьев" << std::endl;
	test_rand(n);
	std::cout << std::endl << std::endl << "Тест трудоёмкости операций вырожденных деревьев" << std::endl;
	test_ord(n);

	system("pause");
	return 0;
}