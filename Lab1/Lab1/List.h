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



	int getSize() { return size ;}
	int getCapacity() { return capacity; }

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
			capacity = capacity/2 + capacity0;
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
				capacity = capacity / 2 + capacity0;
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