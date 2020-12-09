#pragma once
#include <iostream>
#include <random>
//Алгоритмы операций поиска, вставки и удаления реализуются в итерационной форме.
//Вывод на экран последовательности ключей при обходе  узлов дерева  по схеме t -> Lt -> Rt.
//Дополнительная операция : определение в дереве количества узлов с ключами, большими заданного значения.Трудоёмкость операции– O(log n).
//4 вариант

template<class Key, class Data>
class Random_tree {
private:
	class Node {
	public:
		Data data;
		Key key;
		Node* left;
		Node* right;
		int n = 0;
		Node(Key key, Data data) {
			this->data = data;
			this->key = key;
			this->left = NULL;
			this->right = NULL;
		}
	};

	Node* root;
	int size;

	bool doInsert(Node* rt, Key k, Data data) {
		if (rt == NULL) {
			rt = new Node(k, data);
			root = rt;
			size++;
			return true;
		}

		Node* copy = root;
		Node* pred = NULL;

		Key* keys = new Key[size];
		int id = 0;
		do_keys(root,keys,id);
		for (int i = 0; i < size; i++) {
			if (keys[i] == k) return false;
		}

		if (RAND_MAX / (copy->n + 1) > rand()) {
			Node* new_root = new Node(k, data);
			if (copy->key > new_root->key) {
				new_root->right = copy;
			}
			else {
				new_root->left = copy;
			}
			root = new_root;
			size++;
			calcN(root);
			return true;
		}

		while (copy != NULL) {

			if(copy!=root)
			if (RAND_MAX / (copy->n + 1) > rand()) {
				std::cout << "rand" << std::endl;
				Node* new_root = new Node(k, data);

				new_root->n = copy->n+1;
				if (copy->key > new_root->key) {
					new_root->right = copy;
				}
				else {
					new_root->left = copy;
				}

				if (pred->key > new_root->key) {
					pred->left = new_root;

				}
				else {
					pred->right = new_root;
				}
				size++;
				calcN(root);
				return true;
			}

			pred = copy;

			if (k < copy->key)
				copy = copy->left;
			else {
				copy = copy->right;
			}

		}

		if (k < pred->key)
			pred->left = new Node(k, data);
		else
			pred->right = new Node(k, data);
		size++;
		calcN(root);
		return true;
	}

	Data Iterative_search(Node* rt, Key k) {
		Node* copy = rt;
		while (copy != NULL && k != copy->key) {
			if (k < copy->key)
				copy = copy->left;
			else
				copy = copy->right;
		}
		if (copy == NULL) {
			throw "Exception";
		}
		return copy->data;

	}

	bool search (Node* rt, Key k, Data val) {
		Node* copy = rt;
		while (copy != NULL && k != copy->key) {
			if (k < copy->key)
				copy = copy->left;
			else
				copy = copy->right;
		}
		if (copy == NULL) {
			return false;
		}

		copy->data = val;
		return true;

	}

	bool Iterative_Delete(Node* rt, Key key)
	{
		Node* curr = root;
		Node* pred = root;
		while (curr != NULL) {
			if (curr->key > key) {
				pred = curr;
				curr = curr->left;
				continue;
			}
			else {
				if (curr->key < key) {
					pred = curr;
					curr = curr->right;
					continue;
				}
			}

			if (curr == root) {
				curr = Join(curr->left, curr->right);
				root = curr;

			}
			else {
				if (pred->key > key) {
					curr = Join(curr->left, curr->right);
					pred->left = curr;
				}
				else {
					curr = Join(curr->left, curr->right);
					pred->right = curr;
				}

			}
				calcN(root);
				size--;
				return true;

		}
		return false;

	}

	int NodeCount(Node* node)
	{
		if (node->left == NULL && node->right == NULL)
			return 1;
		int left_count, right_count;
		if (node->left != NULL)
			left_count = NodeCount(node->left);
		else
			left_count = 0;
		if (node->right != NULL)
			right_count = NodeCount(node->right);
		else
			right_count = 0;

		return left_count + right_count+1;
	}

	void calcN(Node* rt) {
		if (rt == NULL) return;
		rt->n= NodeCount(rt) -1;
		calcN(rt->left);
		calcN(rt->right);
	}




	Node* Join(Node* a, Node* b) {
		if (a == NULL) return b;
		if (b == NULL) return a;
		std::cout << "delRand" << std::endl;
		if (rand() / (RAND_MAX / a->n + b->n + 1) < a->n) {
			a->right = Join(a->right, b);
			return a;
		}
		else {
			b->left = Join(a, b->left);
			return b;
		}

	}


	void do_Show(Node* rt, int l) {
		if (rt != NULL) {
			do_Show(rt->right, l + 1);
			for (int i = 1; i <= 3 * l; i++)
				std::cout << " ";

			std::cout << rt->key << "(" << rt->data << ")" << rt->n << std::endl;
			do_Show(rt->left, l + 1);
		}
	}

	void do_keys(Node* rt, Key* keys, int& id) {
		if (rt == NULL) return;
		keys[id++] = rt->key;
		do_keys(rt->left, keys, id);
		do_keys(rt->right, keys, id);
	}

	void do_clear(Node* rt) {
		if (rt != NULL) {
			do_clear(rt->left);
			do_clear(rt->right);
			delete rt;
		}
		size = 0;
		root = NULL;
	}

	void size_tree(Node* rt, int& N, Key& val) {
		if (rt == NULL) return;
		if (rt->key > val) N++;
		size_tree(rt->left, N, val);
		size_tree(rt->right, N, val);
	}

	void copy_tree(Node* rt, Random_tree& bt) {
		if (rt == NULL) return;
		bt.insert(rt->key, rt->data);
		copy_tree(rt->left, bt);
		copy_tree(rt->right, bt);
	}

public:
	bool is_update = false;

	friend Node;

	Random_tree() {
		root = NULL;
		size = 0;
	}

	Random_tree(const Random_tree& bt)
	{
		copy_tree(root, bt);
	}

	~Random_tree() {
		do_clear(root);
	}

	int getSize() {
		return size;
	}

	Data* keys() {
		Data* keys = new Data[size];
		int id = 0;
		do_keys(root, keys, id);
		return keys;
	}

	void clear() {
		do_clear(root);
	}

	int count(Data key) {
		Node* tmp = root;
		while (tmp != NULL && tmp->key < key)
			tmp = tmp->right;
		int N = 0;
		size_tree(tmp, N, key);
		return N;
	}

	bool is_empty() {
		if (root == NULL) return true;
		else return false;
	}

	bool insert(Key k, Data data) {
		is_update = true;
		return doInsert(root, k, data);
	}

	Data get(Key key) {
		return Iterative_search(root, key);
	}

	bool remove(Key key) {
		is_update = true;
		return Iterative_Delete(root, key);
	}

	void show() {
		Node* copy = root;
		do_Show(copy, 0);
	}


	class Iterator {
	private:
		Random_tree* tmp;
		Node** arr;
		int id = 0;
		void refresh(Node* qwe, int& i) {
			if (qwe == NULL) return;
			arr[i++] = qwe;
			refresh(qwe->left, i);
			refresh(qwe->right, i);
		}
	public:
		Iterator(Random_tree* qwe) {
			int new_i = 0;
			tmp = qwe;
			arr = new Node * [tmp->getSize()];
			refresh(tmp->root, new_i);
			tmp->is_update = false;

		}
		Iterator(Random_tree* qwe, int i) {
			int new_i = 0;
			tmp = qwe;
			arr = new Node * [tmp->getSize()];
			refresh(tmp->root, new_i);
			tmp->is_update = false;
			id = i;
		}


		Data& operator *() {
			if (tmp->is_update) {
				int new_i = 0;
				delete[] arr;
				arr = new Node * [tmp->getSize()];
				refresh(tmp->root, new_i);
				tmp->is_update = false;
			}
			if (id >= 0 && id < tmp->getSize())
				return arr[id]->data;
			else throw "Exeption";
		}

		Iterator* operator ++() {
			if (id > tmp->getSize()) throw "Exeption";
			if (tmp->is_update) {
				int new_i = 0;
				delete[] arr;
				arr = new Node * [tmp->getSize()];
				refresh(tmp->root, new_i);
				tmp->is_update = false;
			}
			id++;
			return this;
		}

		Iterator* operator --() {
			if (id < 0)throw "Exeption";
			if (tmp->is_update) {
				int new_i = 0;
				delete[] arr;
				arr = new Node * [tmp->getSize()];
				refresh(tmp->root, new_i);
				tmp->is_update = false;
			}
			id--;
			return this;
		}

		bool operator ==(const Iterator* it) {
			if (id == it->id) return true;
			else return false;
		}

		bool operator !=(const Iterator* it) {
			if (id == it->id)return false;
			else return true;
		}

	};

	class r_Iterator {
	private:
		Random_tree* tmp = NULL;
		Node** arr = NULL;
		int id;
		void refresh(Node* qwe, int& i) {
			if (qwe == NULL) return;
			arr[i++] = qwe;
			refresh(qwe->left, i);
			refresh(qwe->right, i);
		}
	public:
		r_Iterator(Random_tree* qwe) {
			int new_i = 0;
			tmp = qwe;
			arr = new Node * [tmp->getSize()];
			refresh(tmp->root, new_i);
			id = tmp->size - 1;
			tmp->is_update = false;
		}

		r_Iterator(Random_tree* qwe, int i) {
			int new_i = 0;
			tmp = qwe;
			arr = new Node * [tmp->getSize()];
			refresh(tmp->root, new_i);
			id = i;
			tmp->is_update = false;
		}

		Data& operator *() {
			if (tmp->is_update) {
				int new_i = 0;
				delete[] arr;
				arr = new Node * [tmp->getSize()];
				refresh(tmp->root, new_i);
				tmp->is_update = false;
			}
			if (id >= 0 && id < tmp->getSize())
				return arr[id]->data;
			else throw "Exeption";
		}

		r_Iterator* operator ++() {
			if (id < 0) throw "Exeption";
			if (tmp->is_update) {
				int new_i = 0;
				delete[] arr;
				arr = new Node * [tmp->getSize()];
				refresh(tmp->root, new_i);
			}
			id--;

			return this;
		}

		r_Iterator* operator --() {
			if (id >= tmp->getSize()) throw "Exeption";
			if (tmp->is_update) {
				int new_i = 0;
				delete[] arr;
				arr = new Node * [tmp->getSize()];
				refresh(tmp->root, new_i);
			}
			id++;
			return this;
		}

		bool operator ==(const r_Iterator* it) {
			if (id == it->id)return true;
			else return false;
		}

		bool operator !=(const r_Iterator* it) {
			if (id == it->id)return false;
			else return true;
		}

	};

	friend Iterator;
	friend r_Iterator;


	Iterator* begin() {
		Iterator* beg = new Iterator(this);
		return beg;
	}
	Iterator* end() {
		Iterator* beg = new Iterator(this, this->size);
		return beg;
	}
	r_Iterator* rbegin() {
		r_Iterator* beg = new r_Iterator(this);
		return beg;
	}
	r_Iterator* rend() {
		r_Iterator* beg = new r_Iterator(this, -1);
		return beg;

	}

};

