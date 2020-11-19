#include <time.h>
#include <math.h>
#include <iostream>
#include "BTS.h"
using namespace std;
typedef unsigned long long INT_64;

//���������� � ��������� ���������� LineRand()
static INT_64 RRand = 15750; const INT_64 mRand = (1 << 63) - 1;
const INT_64 aRand = 6364136223846793005;
const INT_64 cRand = 1442695040888963407;

//������� ��������� ������� ���������� ����� �� ����� ����������
void sRand() { srand(time(0)); RRand = (INT_64)rand(); }

//������� ��������� ���������� �����
//�������� ������������ ���������    Xi+1=(a*Xi+c)%m
//habr.com/ru/post/208178
INT_64 LineRand()
{
    INT_64 y1, y2;
    y1 = (aRand * RRand + cRand) % mRand;
    y2 = (aRand * y1 + cRand) % mRand;
    RRand = y1 & 0xFFFFFFFF00000000LL ^ (y2 & 0xFFFFFFFF00000000LL) >> 32;
    return RRand;
}


// ���� ����������� �������� ���������� BST-������
void test_rand(int n)
{
    //�������� ������ ��� 64 � ��������� ������ ���� INT_64
    Binary_tree< INT_64, int > tree;
    //������ ��� ������, ������� ������������ � ������ 
    INT_64* m = new INT_64[n];
    //��������� ������� ���������� �����
    sRand();
    //���������� ������ � ������� ���������� �� ���������� �������
    for (int i = 0; i < n; i++)
    {
        m[i] = LineRand();
        tree.insert(m[i], 1);
    }
    //����� ������� ������ �� �����
    cout << "items count:" << tree.getSize() << endl;
    //��������� ��������� ����������� �������, �������� � ������
    double I = 0;
    double D = 0;
    double S = 0;
    //��������� ������ ��������, 10% - ������� ��������
    for (int i = 0; i < n / 2; i++)
        if (i % 10 == 0)		//10% ��������
        {
            tree.remove(LineRand());
            D += tree.getSeenValCount();
            tree.insert(m[rand() % n], 1);
            I += tree.getSeenValCount();
            try {
                tree.get(LineRand());
                S += tree.getSeenValCount();
            }
            //��������� ���������� ��� ������ �������� ������
            catch (...) { S += tree.getSeenValCount(); }
        }
        else  //90% �������� ��������
        {
            int ind = rand() % n;
            tree.remove(m[ind]);
            D += tree.getSeenValCount();
            INT_64 key = LineRand();
            tree.insert(key, 1);
            I += tree.getSeenValCount();
            m[ind] = key;
            try {
                tree.get(m[rand() % n]);
                S += tree.getSeenValCount();
            }
            //��������� ���������� ��� ������ �������� ������
            catch (...) { S += tree.getSeenValCount(); }
        }	//����� �����

     //����� �����������:
     //����� ������� ������ ����� �����
    cout << "items count:" << tree.getSize() << endl;
    //������������� ������ ����������� �������� BST
    cout << "1.39*log2(n)=" << 1.39 * (log((double)n) / log(2.0)) << endl;
    //����������������� ������ ����������� �������
    cout << "Count insert: " << I / (n / 2) << endl;
    //����������������� ������ ����������� ��������
    cout << "Count delete: " << D / (n / 2) << endl;
    //����������������� ������ ����������� ������
    cout << "Count search: " << S / (n / 2) << endl;
    //������������ ������ ������� m[]
    delete[] m;
}


// ���� ����������� �������� ������������ BST-������
void test_ord(int n)
{
    //�������� ������ ��� 64 � ��������� ������ ���� INT_64
    Binary_tree< INT_64, int > tree;
    //������ ��� ������, ������� ������������ � ������ 
    INT_64* m = new INT_64[n];

    //���������� ������ � ������� ���������� � ������������� ������� //������� �� ��������� [0, 10000, 20000, ... ,10000*n]
    for (int i = 0; i < n; i++) {
        m[i] = i * 10000;
        tree.insert(m[i], 1);
    }
    //����� ������� ������ �� ����� 
    cout << "items count:" << tree.getSize() << endl;
    //��������� ��������� ����������� �������, �������� � ������
    double I = 0;
    double D = 0;
    double S = 0;
    //��������� ������� ���������� ����� 
    sRand();
    //��������� ������ ��������, 10% - ������� ��������
    for (int i = 0; i < n / 2; i++)
    {
        if (i % 10 == 0)		//10% ��������
        {
            int k = LineRand() % (10000 * n);
            k = k + !(k % 2);	//��������� �������� ����
            tree.remove(k);
            D += tree.getSeenValCount();
            tree.insert(m[rand() % n], 1);
            I += tree.getSeenValCount();
            k = LineRand() % (10000 * n);
            k = k + !(k % 2);	// ��������� �������� ����
            try {
                tree.get(k);
                S += tree.getSeenValCount();
            }
            //��������� ���������� ��� ������ �������� ������
            catch (...) { S += tree.getSeenValCount(); }
        }
        else  //90% �������� ��������
        {
            int ind = rand() % n;
            tree.remove(m[ind]);
            D += tree.getSeenValCount();;
            int k = LineRand() % (10000 * n);
            k = k + k % 2;		// ��������� ������ ����
            tree.insert(k, 1);
            I += tree.getSeenValCount();;
            m[ind] = k;
            try {
                tree.get(m[rand() % n]);
                S += tree.getSeenValCount();;
            }
            //��������� ���������� ��� ������ �������� ������
            catch (...) { S += tree.getSeenValCount(); }
        }
    }
    //����� �����������:
    // ����� ������� ������ ����� �����
    cout << "items count:" << tree.getSize() << endl;
    //������������� ������ ����������� �������� BST
    cout << "n/2 =" << n / 2 << endl;
    //����������������� ������ ����������� �������
    cout << "Count insert: " << I / (n / 2) << endl;
    //����������������� ������ ����������� ��������
    cout << "Count delete: " << D / (n / 2) << endl;
    //����������������� ������ ����������� ������
    cout << "Count search: " << S / (n / 2) << endl;
    //������������ ������ ������� m[]
    delete[] m;
}	//����� �����
