#pragma once
template <class T>
class List
{
private:
	int size;
	int capacity0;
	int capacity;
	T* array;
	int seenValCount;

public:
	List();
	List(int capacity0);
	~List();
	List(const List<T>& list);

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
	int getSeenValCount();
	void show();

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
};