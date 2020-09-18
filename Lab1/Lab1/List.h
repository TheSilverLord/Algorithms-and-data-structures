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
	
	//List(const List<T>& list);



	class Iterator
	{
	private:
		List* p;
		int index;

	public:
		Iterator();
	};

	class reverse_Iterator
	{
	private:
		List* p;
		int index;

	public:
		reverse_Iterator();
	};

	friend class Iterator;
	friend class reverse_Iterator;


	Iterator begin();
	reverse_Iterator rbegin();
	Iterator end();
	reverse_Iterator rend();




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



	}



	int getSize() { return size ;};

	void clear() {
		T* copyArr = new T[capacity0];

		delete[] array;
		array = copyArr;
		delete copyArr;
		size = 0;
		capacity = capacity0;
	}


	bool isEmpty() {
		if (size == 0) return true;
		else return false;
	}


	bool contains(T value) {
		for (int i = 0; i < size; i++) {
			seenValCount++;
			if (array[i] == value) {
				return true;
			}
		}
		return false;
	}


	T get(int index) {
		if (index > size); //добавить исключение
		else return array[index];
	}


	void set(int index, T value) {
		if (index > size);  //добавить исключение
		else array[index] = value;
	}


	int getIndex(T value) {
		for (int i = 0; i < size; i++) 
			if (array[i] == value)return i;

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

	//void add(int index, T value) {
	//	if (index > size)return false;
	//	else {
	//
	//
	//	}
	//
	//} If your read this pls send me some letter in VK

	bool add(int index, T value) {
		if (index > size)return false;
		else {
			for (int i = size; i > index; i--) {
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
				array[i] = array[i + 1];
			}
		}

		size--;
		if (size == capacity / 2) {
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
		if (index > size) return false;
		else {
			for (int i = index; i < size - 1; i++) {
				array[i] = array[i + 1];
			}

			size--;
			if (size == capacity / 2) {
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