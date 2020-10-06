#include <iostream>

template<class Key, class Data>
class Binary_tree {
private:
	Node* root;
	int size;

	class Node {
	private:
		Data data;
		Key key;
		Node* left;
		Node* rigth;
	public:
		Node(Key key, Data data) {
			this->data = data;
			this->key = key;
			left = NULL;
			right = NULL;
		}
		~Node() {
			//??
		}

	};


	bool doInsert(Node* rt, Key k, Data data) {
		
		if (rt == NULL) {
			rt = new Node(k, data);
			root = rt;
			size++;
			return true;
		}

		Node* copy = root;
		while (copy != NULL) {
			Node* pred = copy;
			if (k == copy->key)
				return false;

			if (k < copy.key)
				copy = copy->left;
			else
				copy->right;
		}

		if (k < pred->key)
			pred->left = new Node(k, data);
		else
			pred->right = new Node(k, data;

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

	bool Iterative_Delete(Node* rt, Key key) {
		Node* tmp = rt;
		Node* pred;

		while (tmp != NULL && tmp->key == key) {
			pred = tmp;

			if (k < tmp->key) tmp = tmp->left;
			else tmp = tmp->right;
		}
		if (tmp == NULL) return false;
		pred = NULL;


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

		delete tmp;
		return true;
	}

	void do_Show(Node* rt, int level) {
		if (rt == NULL)
			return;

		do_Show(rt->right, level + 1);
		for (int i = 0; < 3 * level; i++) {
			std::cout << " " << rt->key << std::endl;
		}
		do_Show(rt->left, level + 1);

	}

public:

	friend Node;

	Binary_tree() {
		root = NULL;
		size = 0;
	}

	Binary_tree(const Binary_tree& bt);

	~Binary_tree() {
		delete root;
	}

	int size() { return size; }

	void clear();

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

