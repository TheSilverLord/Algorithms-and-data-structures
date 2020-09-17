#pragma once
template <class T>
class Array
{
private:
	int size;
	int capacity0;
	int capacity;
	T* array;
	int seenValCount;

public:
	Array();
	Array(int capacity0);
	~Array();
	Array(const Array& array);

	int getSize();
	void clear();
	bool isEmpty();
	bool contains(T value);
	T get(int index);
	void set(int index, T value);
	int getIndex(T value);
	void add(T value);
	bool add(int index, T value);
	bool deleteValue(T value);
	bool deleteIndexVal(int index);
	friend class Iterator;
	Iterator begin();
	Iterator rbegin();
	Iterator end();
	Iterator rend();
	int getSeenValCount();
	void show();

	class Iterator
	{
	private:
		Array* p;
		int index;

	public:
		Iterator();
	};

	//дописать реверс-итератор
};