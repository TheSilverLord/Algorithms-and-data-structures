#include <iostream>
//��������� �������� ������, ������� � �������� ����������� � ������������ �����.
//����� �� ����� ������������������ ������ ��� ������  ����� ������  �� ����� t -> Lt -> Rt.
//�������������� �������� : ����������� � ������ ���������� ����� � �������, �������� ��������� ��������.����������� �������� O(log n).
//4 �������

template<class Key, class Data>
class Binary_tree {
private:
	class Node {
	public:
		Data data;
		Key key;
		Node* left;
		Node* right;
		Node() {
			this->data = 0;
			this->key = 0;
			this->left = NULL;
			this->right = NULL;
		}
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
		seenValCount = 0;
		
		if (rt == NULL) {
			rt = new Node(k, data);
			root = rt;
			size++;
			return true;
		}

		Node* copy = root;
		Node* pred = NULL;
		while (copy != NULL) {
			pred = copy;
			if (k == copy->key)
				return false;

			if (k < copy->key)
				copy = copy->left;
			else
				copy = copy->right;
			seenValCount++;
		}

		if (k < pred->key)
			pred->left = new Node(k, data);
		else
			pred->right = new Node(k, data);

		size++;
		return true;
	}


	Data Iterative_search(Node* rt, Key k) {
		seenValCount = 0;
		Node* copy = rt;
		while (copy != NULL && k != copy->key) {
			if (k < copy->key)
				copy = copy->left;
			else 
				copy = copy->right;
			seenValCount++;
		}
		if (copy == NULL) {
			throw "Exception";
		}
		return copy->data;

	}

	bool Iterative_change(Node* rt, Key k, Data val) {
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

	bool Iterative_Delete(Node* root, Key key)
	{
		Node* curr = root;
		Node* prev = NULL;

		while (curr != NULL && curr->key != key) {
			prev = curr;
			if (key < curr->key)
				curr = curr->left;
			else
				curr = curr->right;
		}

		if (curr == NULL) {
			return false;
		}

		if (curr->left == NULL || curr->right == NULL) {

			Node* newCurr;

			if (curr->left == NULL)
				newCurr = curr->right;
			else
				newCurr = curr->left;

			if (prev == NULL)
				return true;

			if (curr == prev->left)
				prev->left = newCurr;
			else
				prev->right = newCurr;

			delete curr;
		}
		else {
			Node* p = NULL;
			Node* temp;

			temp = curr->right;
			while (temp->left != NULL) {
				p = temp;
				temp = temp->left;
			}

			if (p != NULL)
				p->left = temp->right;
			else
				curr->right = temp->right;

			curr->data = temp->data;
			curr->key = temp->key;
			delete temp;
		}

		size--;
		return true;
	}

	void do_Show(Node* rt, int l)	{
		if (rt != NULL){
			do_Show(rt->right, l + 1);
			for (int i = 1; i <= 3*l; i++)
				std::cout << " ";

			std::cout << rt->key << "(" << rt->data << ")"  << std::endl;
			do_Show(rt->left, l + 1);
		}
	}

	void do_keys(Node* rt, Data* keys, int& id) {
		if (rt == NULL) return;
		keys[id++]=rt->key;
		do_keys(rt->left,keys,id);
		do_keys(rt->right,keys, id);
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

	void size_tree(Node* rt, int &N, Key &val) {
		if (rt == NULL) return;
		if(rt->key > val) N++;
		size_tree(rt->left, N, val);
		size_tree(rt->right, N, val);
	}

	void copy_tree(Node* rt, Binary_tree& bt) {
		if (rt == NULL) return;
		bt.insert(rt->key, rt->data);
		copy_tree(rt->left, bt);
		copy_tree(rt->right, bt);
	}

	int seenValCount;

public:
	bool is_update = false;

	friend Node;

	Binary_tree() {
		root = NULL;
		size = 0;
		seenValCount = 0;
	}

	Binary_tree(const Binary_tree& bt)
	{
		copy_tree(root, bt);
	}

	~Binary_tree() {
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

	int count(Key key) {
		Node* tmp = root;
		while (tmp!=NULL && tmp->key < key) 
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
	bool change(Key key, Data val) {
		return Iterative_change(root, key, val);
	}

	bool remove(Key key) {
		is_update = true;
		return Iterative_Delete(root, key);
	}

	void show() {
		Node* copy = root;
		do_Show(copy, 0);
	}

	int getSeenValCount()
	{
		return seenValCount;
	}


	class Iterator {
	private:
		Binary_tree* tmp;
		Node** arr;
		int id = 0;
		void refresh(Node* qwe, int& i) {
			if (qwe == NULL) return;
			arr[i++] = qwe;
			refresh(qwe->left, i);
			refresh(qwe->right, i);
		}
	public:
		Iterator(Binary_tree* qwe) {
			int new_i = 0;
			tmp = qwe;
			arr = new Node*[tmp->getSize()];
			refresh(tmp->root, new_i);
			tmp->is_update = false;

		}
		Iterator(Binary_tree* qwe, int i) {
			int new_i = 0;
			tmp = qwe;
			arr = new Node*[tmp->getSize()];
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
			if (id >=0 && id < tmp->getSize())
				return arr[id]->data;
			else throw "Exeption";
		}

		Iterator* operator ++() {
			if (id > tmp->getSize()) throw "Exeption";
			if (tmp->is_update) {
				int new_i = 0;
				delete[] arr;
				arr = new Node*[tmp->getSize()];
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
				arr = new Node*[tmp->getSize()];
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
		Binary_tree* tmp = NULL;
		Node** arr = NULL;
		int id;
		void refresh(Node* qwe, int &i) {
			if (qwe == NULL) return;
			arr[i++] = qwe;
			refresh(qwe->left, i);
			refresh(qwe->right, i);
		}
	public:
		r_Iterator(Binary_tree* qwe){
			int new_i = 0;
			tmp = qwe;
			arr = new Node*[tmp->getSize()];
			refresh(tmp->root, new_i);
			id = tmp->size - 1;
			tmp->is_update = false;
		}

		r_Iterator(Binary_tree* qwe, int i) {
			int new_i = 0;
			tmp = qwe;
			arr = new Node*[tmp->getSize()];
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
				arr = new Node*[tmp->getSize()];
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
				arr = new Node*[tmp->getSize()];
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

