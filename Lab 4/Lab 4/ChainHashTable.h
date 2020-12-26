#pragma once
#include <iostream>
#include "HashTable.h"
template <class Key, class Data>
class ChainHashTable {
public:
	int first_size = 8;
	int max_size;
	class Node {
	public:
		Key key;
		Data value;
		bool state = false;
		Node* next;
		Node(Key k, Data val) {
			value = val;
			key = k;
			state = true;
			next = NULL;
		};
	};
	int size;
	Node* it_node = NULL;
	Node** arr;

	/*void resize() {
		int past_size = max_size;
		max_size *= 2;
		size = 0;

		Node** arr2 = new Node * [max_size];
		for (int i = 0; i < max_size; i++)
			arr[i] = NULL;

		std::swap(arr, arr2);

		for (int i = 0; i < past_size; i++)
			if (arr2[i] && arr2[i]->state)
				add(arr2[i]->key, arr2[i]->value);

		for (int i = 0; i < max_size; i++)
			if (arr2[i])
				delete arr2[i];
		delete[] arr2;
	}*/
	void resize()
	{
		int past_buffer_size = max_size;
		max_size *= 2;
		size = 0;
		Node** arr2 = new Node * [max_size];
		for (int i = 0; i < max_size; ++i)
			arr2[i] = nullptr;
		std::swap(arr, arr2);
		for (int i = 0; i < past_buffer_size; ++i)
		{
			if (arr2[i] && arr2[i]->state)
				while (arr2[i])
				{
					add(arr2[i]->key, arr2[i]->value); // добавляем элементы в новый массив
					arr2[i] = arr2[i]->next;
				}
		}
		// удаление предыдущего массива
		for (int i = 0; i < past_buffer_size; ++i)
			if (arr2[i])
				delete arr2[i];
		delete[] arr2;
	}

	int nut_k(Key k) {
		int k1 = (int)k[0];
		for (int i = 1; k[i] != 0; i++) {
			k1 = k1 * 32 + (int)k[i];
		}
		k1++;
		return k1;
	}

	int hashfunc(Key k) {
		int new_k = nut_k(k);
		int kA = new_k * A;
		//std::cout << kA << std::endl;
		//std::cout << max_size * abs((kA - new_k * A)) << std::endl;
		int h = max_size * abs((kA - new_k * A));
		return h;
	}

	ChainHashTable() {
		max_size = first_size;
		size = 0;
		arr = new Node * [max_size];
		for (int i = 0; i < max_size; i++) {
			arr[i] = NULL;
		}
	}

	~ChainHashTable() {
		for (int i = 0; i < max_size; i++) {
			if (arr[i]) {
				delete[] arr[i];
			}
		}
		delete[] arr;
	}

	bool add(Key k, Data d) {
		if (!arr) {
			arr = new  Node * [max_size];
			for (int i = 0; i < max_size; i++)
				arr[i] = NULL;
		}
		if (size + 1 >= max_size) resize();

		int i = hashfunc(k);
		Node* first_del = NULL;
		Node* tmp = arr[i];
		Node* pred = arr[i];
		while (tmp != NULL) {
			if (tmp->key == k && tmp->state) return false;
			
			if (!tmp->state && !first_del)
				first_del = tmp;

			pred = tmp;
			tmp = tmp->next;
		}

		if (!first_del) {
			if (pred) {
				pred->next = new Node(k, d);
			}
			else {
				arr[i] = new Node(k, d);
			}
		}
		else {
			first_del->value = d;
		}

		size++;
		return true;
	}

	bool remove(Key k) {
		int i = hashfunc(k);
		Node* find = arr[i];
		Node* pred = NULL;
		while (find != NULL) {
			if (find->key == k) {
				if (pred) {
					pred->next = find->next;
					delete find;
				}
				else {
					if (find->next)
					{
						Node* next = find->next;
						delete find;
						arr[i] = next;
					}
					else arr[i] = NULL;
				}
				return true;
			}
			pred = find;
			find = find->next;
		}

		return false;
	}

	Data find(Key k) {
		int i = hashfunc(k);
		Node* find = arr[i];

		while (find != NULL) {
			if (find->key == k) {
				return find->value;
			}
			find = find->next;
		}

		throw "Exeption";
	}
	int getMax_size() {
		return max_size;
	}

	int getSize() {
		return size;
	}

	void clear() {
		max_size = 8;
		size = 0;

		for (int i = 0; i < max_size; i++)
			while (arr[i]) {
				Node* pred = arr[i]->next;
				delete arr[i];
				arr[i] = pred;
			}
		delete[] arr;
		arr = new Node * [max_size];
		for (int i = 0; i < max_size; ++i)
			arr[i] = nullptr;
	}

	bool is_empty() {
		if (size) return false;
		else return true;
	}

	void show() {
		for (int i = 0; i < max_size; i++) {
			if (arr[i] == NULL || !arr[i]->state) {
				std::cout << "Null" << std::endl;
			}
			else{
				Node* tmp = arr[i];
				while (tmp) {
					std::cout << tmp->key << "(" << tmp->value << ") ";
					tmp=tmp->next;
				}
				std::cout << "Null" << std::endl;
			}
		}
		std::cout << std::endl;
	}

};