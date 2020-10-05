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
		}

	};


public:
	friend r_Iterator;
	friend Iterator;
	friend Node;

	Binary_tree() {
		root = NULL;
		size = 0;
	}

	Binary_tree(const Binary_tree& bt);

	~Binary_tree();

	int size() { return size; }

	void clear();

	bool is_empty() {
		if (root == NULL) return true;
		else return false;
	}

	bool insert(Node* rt, Key k, Data data) {
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

	Data get(Key key) {


	}

	bool remove(Key key);

	friend r_Iterator;
	friend Iterator;
	friend Node;
	class Iterator {

	};

	class r_Iterator {

	};

	

	Iterator begin();
	Iterator end();
	r_Iterator rbegin();
	r_Iterator rend();

};

