#pragma once
#include <math.h>
#include "ChainHashTable.h"
double A = 0.6180339887;

template <class Key, class Data>
class OpenHashTable {
public:
	int first_size = 8;

	int max_size;
	class Node {
	public:
		Key key;
		Data value;
		bool state = false;
		Node(Key k, Data val){
			value = val;
			key = k;
			state = true;
		};
	};
	int size;
	int size_with_del;
	Node* it_node = NULL;

	Node** arr;

	void resize()
	{
		int past_buffer_size = max_size;
		max_size *= 2;
		size_with_del = 0;
		size = 0;
		Node** arr2 = new Node * [max_size];
		for (int i = 0; i < max_size; ++i)
			arr2[i] = nullptr;
		std::swap(arr, arr2);
		for (int i = 0; i < past_buffer_size; ++i)
		{
			if (arr2[i] && arr2[i]->state)
				add(arr2[i]->key, arr2[i]->value); // добавляем элементы в новый массив
		}
		// удаление предыдущего массива
		for (int i = 0; i < past_buffer_size; ++i)
			if (arr2[i])
				delete arr2[i];
		delete[] arr2;
	}

	void rehash() {
		size_with_del = 0;
		size = 0;
		Node** arr2 = new Node * [max_size];
		for (int i = 0; i < max_size; i++)
			arr[i] = NULL;

		std::swap(arr, arr2);

		for (int i = 0; i < max_size; i++)
			if (arr2[i] && arr2[i]->state)
				add(arr2[i]->key, arr2[i]->value);

		for (int i = 0; i < max_size; i++)
			if (arr2[i])
				delete[] arr2[i];
		delete[] arr2;
	}

	OpenHashTable() {
		max_size = first_size;
		size = size_with_del = 0;
		arr = new Node * [max_size];
		for (int i = 0; i < max_size; i++) {
			arr[i] = NULL;
		}
	}

	~OpenHashTable() {
		for (int i = 0; i < max_size; i++) {
			if (arr[i]) {
				delete[] arr[i];
			}
		}
		delete[] arr;
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


	bool add(Key k, Data d) {
		if (!arr) {
			arr = new  Node * [max_size];
			for (int i = 0; i < max_size; i++)
				arr[i] = NULL;
		}
		if (size + 1 >= max_size) resize();
		else if (size_with_del > size * 2) rehash();
		int i = hashfunc(k);
		int i1 = i;
		int first_del = -1;
		while (i != i - 1 && arr[i] != NULL) {
			if (arr[i]->key == k && arr[i]->state) return false;
			if (!arr[i]->state && first_del == -1)
				first_del = i;


			i = (i + 1) % max_size;
		}

		if (first_del == -1) {
			arr[i] = new Node(k, d);
			size_with_del++;
		}
		else {
			arr[i]->value = d;
			size++;
		}
		size++;
		return true;
	}

	bool remove(Key k) {
		int i = hashfunc(k);

		while (i != i - 1 && arr[i] != NULL) {
			if (arr[i]->key == k) {
				arr[i]->state = false;
				size--;
				return true;
			}

			i = (i + 1) % max_size;
		}

		return false;
	}

	Data find(Key k) {
		int i = hashfunc(k);

		while (i != i - 1 && arr[i] != NULL) {
			if (arr[i]->key == k) {
				return arr[i]->value;
			}

			i = (i + 1) % max_size;
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
		size_with_del = 0;
		size = 0;

		/*for (int i = 0; i < max_size; i++)
			if (arr[i])
				delete arr[i];
		delete[] arr;
		arr = NULL;*/
		Node** arr2 = new Node * [max_size];
		for (int i = 0; i < max_size; ++i)
			arr2[i] = nullptr;
		std::swap(arr, arr2);
		
		// удаление предыдущего массива
		for (int i = 0; i < max_size; ++i)
			if (arr2[i])
				delete arr2[i];
		delete[] arr2;
	}

	bool is_empty() {
		if (size) return false;
		else return true;
	}

	void show() {
		if (!arr) {
			arr = new  Node * [max_size];
			for (int i = 0; i < max_size; i++)
				arr[i] = NULL;
		}

		for (int i = 0; i < max_size;i++) {
			if (arr[i] == NULL) {
				std::cout << "Null" << " ";
			}
			else {
				if (!arr[i]->state) {
					std::cout << "Null" << " ";
					continue;
				}
				std::cout << arr[i]->key << "(" << arr[i]->value << ") ";
			}
		}
		std::cout << std::endl;
	}


	

};