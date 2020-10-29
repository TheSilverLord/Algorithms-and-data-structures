#include <iostream>
//Алгоритмы операций поиска, вставки и удаления реализуются в итерационной форме.
//Вывод на экран последовательности ключей при обходе  узлов дерева  по схеме t -> Lt -> Rt.
//Дополнительная операция : определение в дереве количества узлов с ключами, большими заданного значения.Трудоёмкость операции– O(log n).
//4 вариант

template<class Key, class Data>
class Binary_tree {
private:
	class Node {
	public:
		Data data;
		Key key;
		Node* left;
		Node* right;
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
		while (copy != NULL) {
			pred = copy;
			if (k == copy->key)
				return false;

			if (k < copy->key)
				copy = copy->left;
			else
				copy = copy->right;
		}

		if (k < pred->key)
			pred->left = new Node(k, data);
		else
			pred->right = new Node(k, data);

		size++;
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
			//Эксепшон
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


	bool Iterative_Delete(Node* rt, Key key) {
		Node* tmp = rt;
		Node* pred = NULL;
	
		while (tmp != NULL ) {
			if (tmp->key == key) break;
			pred = tmp;
	
			if (key < tmp->key) tmp = tmp->left;
			else tmp = tmp->right;
		}
		if (tmp == NULL) return false;
	
	
		//Далее непонятно
		Node* x;
		if (tmp->left == NULL && tmp->right == NULL)
			x = NULL;
		else
			if (tmp->left == NULL)
				x = tmp->right;
			else
				if (tmp->right == NULL)
					x = tmp->left;
				else {
					pred = tmp;
					Node* y = tmp->right;
	
					while (y->left != NULL) {
						pred = y;
						y = y->left;
					}
	
					tmp->key = y->key;
					tmp->data = y->data;
					x = tmp->right;
					tmp = y;
				} 
		//Непонятно закончилось
			
		if (pred == NULL) root = x;
		else {
			if (tmp->key < pred->key)
				pred->left = x;
			else 
				pred->right = x;
		}
	//Не работает удаление корня если есть 2 предка) остальное вроде все работает
		size--;
		delete tmp;
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

public:

	friend Node;

	Binary_tree() {
		root = NULL;
		size = 0;
	}

	Binary_tree(const Binary_tree& bt);

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

	int count(Data key) {
		Node* tmp = root;
		while (tmp!=NULL && tmp->key < key) 
			tmp = tmp->right;
		//Не доделано, или доделано. Не тестил
		int N = 0;
		size_tree(tmp, N, key);
		return N;
	}

	bool is_empty() {
		if (root == NULL) return true;
		else return false;
	}

	bool insert(Key k, Data data) {
		return doInsert(root, k, data);
	}

	Data get(Key key) {
		return Iterative_search(root, key);
	}
	bool change(Key key, Data val) {
		return Iterative_change(root, key, val);
	}

	bool remove(Key key) {
		return Iterative_Delete(root, key);
	}

	void show() {
		Node* copy = root;
		do_Show(copy, 0);
	}


	class Iterator {
	private:
		Node* tmp;
	
	public:

		Iterator() {
			tmp = root;
		}
		
		
		Data operator *() {

			return tmp->data;
		}

		Iterator* operator ++() {// Дописать переход на правую ветку
			return tmp->left;
		}

		Iterator& operator --() {


		}

		bool operator ==(const Iterator* it) {
			if (&tmp == &(it->tmp))return true;
			else return false;
		}

		bool operator !=(const Iterator* it) {
			if (&tmp == &(it->tmp))return false;
			else return true;
		}


	};

	class r_Iterator {
	private:
		Node* tmp;
	
	public:



	};

	friend Iterator;
	friend r_Iterator;


	Iterator* begin() {
		Iterator* beg = new Iterator();
		return beg;

	}
	Iterator end();
	r_Iterator rbegin();
	r_Iterator rend();

};

