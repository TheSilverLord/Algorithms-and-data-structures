#pragma once
template <class T>
class List
{
private:
	int capacity0=0;
	int size=0;
	int capacity=0;
	T* array;
	int seenValCount=0;

public:

	class Iterator
	{
	private:
		List* p;
		int index;
<<<<<<< Updated upstream
=======
		T data;
>>>>>>> Stashed changes

	public:
		Iterator(List* list) {
			p = list;
			index = 0;

		}
		Iterator(List* list, int index) {
			p = list;
			this->index = index;
		}

		T& operator *() {
<<<<<<< Updated upstream
			if (p != NULL && p->getSize() != 0 && index < p->getSize())
			{
				return *(p->array + index);
			}
			else throw "Exception";
		}

		Iterator& operator ++() {
			if (p != NULL && p->getSize() != 0)
			{
				this->index++;
				return *this;
			}
			else throw "Exception";
		}

		Iterator& operator --() {
			if (p != NULL && p->getSize() != 0)
			{
				this->index--;
				return *this;
			}
			else throw "Exception";
=======
			if (p != NULL) {
				data = *(p->array + index);
				return data;
			}
			else {
				//исключение
			}
		}

		Iterator& operator ++() {
			if (p != NULL) {
				this->index++;
			return *this;
			}
			else {
				//исключение
			}
		}

		Iterator& operator --() {
			if (p != NULL) {
				this->index--;
				return *this;

			}
			else {
				//исключение
			}
>>>>>>> Stashed changes
		}

		bool operator ==(const Iterator& it) {
			if (this->index == it.index)return true;
			else return false;
		}

		bool operator !=(const Iterator& it) {
			if (this->index == it.index)return false;
			else return true;
		}
	};

	class reverse_Iterator
	{
	private:
		List* p;
		int index;
<<<<<<< Updated upstream
=======
		T data;
>>>>>>> Stashed changes

	public:
		reverse_Iterator(List* list) {
			p = list;
			index = p->size - 1;

		}
		reverse_Iterator(List* list, int index) {
			p = list;
			this->index = index;
		}

		T& operator *() {
<<<<<<< Updated upstream
			if (p != NULL && p->getSize() != 0 && index >= 0)
			{
				return *(p->array + index);
			}
			else throw "Exception";
		}

		reverse_Iterator& operator ++() {
			if (p != NULL && p->getSize() != 0)
			{
				this->index--;
				return *this;
			}
			else throw "Exception";
=======
			if (p != NULL) {
				data = *(p->array + index);
				return data;
			}
			else {
				//исключение
			}
		}

		reverse_Iterator& operator ++() {
			if (p != NULL) {
				this->index--;
				return *this;
			}
			else {
				//исключение
			}
>>>>>>> Stashed changes
		}
	

		reverse_Iterator& operator --() {
<<<<<<< Updated upstream
			if (p != NULL && p->getSize() != 0)
			{
				this->index++;
				return *this;
			}
			else throw "Exception";
=======
			if (p != NULL) {
				this->index++;
				return *this;
>>>>>>> Stashed changes

			}
			else {
				//исключение
			}
		}

		bool operator ==(const reverse_Iterator& it) {
			if (this->index == it.index)return true;
			else return false;
		}

		bool operator !=(const reverse_Iterator& it) {
			if (this->index == it.index)return false;
			else return true;
		}
	};

	friend class Iterator;
	friend class reverse_Iterator;
	Iterator* begin() {
		Iterator* copy = new Iterator(this);
		return copy;
	}
	reverse_Iterator* rbegin() {
		reverse_Iterator* copy = new reverse_Iterator(this, size-1);
		return copy;

	}
	Iterator* end() {
		Iterator* copy = new Iterator(this,size);
		return copy;
	}
	reverse_Iterator* rend() {
		reverse_Iterator* copy = new reverse_Iterator(this, -1);
		return copy; //????????????????
	}

	List() {
		capacity0 = capacity = 2;
		size = 0;
		array = new T[capacity0];
	}

	List(int capacity0) {
		this->capacity0 = capacity = capacity0;
		size = 0;
		array = new T[capacity0];
	}
	~List() {
		delete[] array;
	}

	List(const List<T>& list) {
		this->array = new T[list.capacity];
		for (int i = 0; i < size; i++) {
			this->array[i] = list.array[i];
		}
		this->capacity0 = list.capacity0;
		this->capacity = list.capacity;
		this->size = list.size;
		this->seenValCount = list.seenValCount;
	}



	int getSize() { return size ;}
	int getCapacity() { return capacity; }

	void clear() {
		T* copyArr = new T[capacity0];

		delete[] array;
		array = copyArr;
		size = 0;
		capacity = capacity0;
	}

	bool isEmpty() {
		if (size == 0) return true;
		else return false;
	}

	bool contains(T value) {
		seenValCount = 0;
		for (int i = 0; i < size; i++) {
			seenValCount++;
			if (array[i] == value) {
				return true;
			}
		}
		return false;
	}

	T get(int index) {
		if (index >= size || index < 0) throw "Exception";
		else return array[index];
	}

	bool set(int index, T value) {
		if (index >= size || index < 0) return false;
		else
		{
			array[index] = value;
			return true;
		}
	}

	int getIndex(T value) {
		seenValCount = 0;
		for (int i = 0; i < size; i++) {
			seenValCount++;
			if (array[i] == value)return i;
		}
		return -1;
	}

	void add(T value) {
		array[size] = value;
		size++;
		if (size == capacity) {
			capacity *= 2;
			T* copyArr = new T[capacity];
			for (int i = 0; i < size; i++) {
				copyArr[i] = array[i];
			}
			delete[] array;
			array = copyArr;
		}
	}

	bool add(int index, T value) {
		seenValCount = 0;
		if (index > size || index < 0)return false;
		else {
			for (int i = size; i > index; i--) {
				seenValCount++;
				array[i] = array[i - 1];
			}
			array[index] = value;
			size++;
			if (size == capacity) {
				capacity *= 2;
				T* copyArr = new T[capacity];
				for (int i = 0; i < size; i++) {
					copyArr[i] = array[i];
				}
				delete[] array;
				array = copyArr;
			}

			return true;
		}
	}

	bool deleteValue(T value) {
		bool isFind = false;
		for (int i = 0; i < size; i++) {
			if (array[i] == value) {
				isFind = true;
			}
			if (isFind) {
				if (i == size-1) break;
				seenValCount = 0;
				array[i] = array[i + 1];
			
			}
		}

		size--;
		if (size <= capacity / 2) {
			capacity = size + capacity0;
			T* copyArr = new T[capacity];
			for (int i = 0; i < size; i++) {
				copyArr[i] = array[i];
			}
			delete[] array;
			array = copyArr;
		}

		return isFind;
	}

	bool deleteIndexVal(int index) {
		if (index >= size || index < 0) return false;
		else {
			for (int i = index; i < size - 1; i++) {
				array[i] = array[i + 1];
			}

			size--;
			if (size <= capacity / 2) {
				capacity = size + capacity0;
				T* copyArr = new T[capacity];
				for (int i = 0; i < size; i++) {
					copyArr[i] = array[i];
				}
				delete[] array;
				array = copyArr;
			}

			return true;
		}

	}

	int getSeenValCount() {
		return seenValCount;
	}

};