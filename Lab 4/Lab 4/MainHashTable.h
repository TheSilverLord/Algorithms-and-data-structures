#pragma once
#include "ChainHashTable.h"
#include "HashTable.h"

template <class Key, class Data>
class MainHashTable {
private:
	bool is_chain = true;
	ChainHashTable<Key,Data> chain;
	OpenHashTable<Key, Data> open;

public:
	bool insert(Key k, Data d) {

		if (is_chain) {
			return chain.add(k, d);
		}
		else {
			return open.add(k, d);
		}
	}

	int getMax_size() {
		if (is_chain){
			return chain.getMax_size();
		}
		else {
			return open.getMax_size();
		}
	}

	int getSize() {
		if (is_chain) {
			return chain.getSize();
		}
		else {
			return open.getSize();
		}
	}


	bool is_empty() {
		if (is_chain) {
			return chain.is_empty();
		}
		else {
			return open.is_empty();
		}
	}

	Data find(Key k){
		if (is_chain) {
			return chain.find(k);
		}
		else {
			return open.find(k);
		}
	}
	bool remove(Key k) {
		if (is_chain) {
			return chain.remove(k);
		}
		else {
			return open.remove(k);
		}
	}

	void show() {
		if (is_chain) {
			return chain.show();
		}
		else {
			return open.show();
		}
	}

	void changeTable(bool bl) {
		if (bl == is_chain) return;
		if (is_chain) {
			is_chain = false;

			open.clear();
			if (!chain.is_empty())
				for (int i = 0; i < chain.getMax_size(); i++) {
					if (chain.arr[i]) {
						while (chain.arr[i]) {
							open.add(chain.arr[i]->key, chain.arr[i]->value);
							chain.arr[i] = chain.arr[i]->next;
						}
					}
				}
		}
		else {
			is_chain = true;
			chain.clear();
			if (!open.is_empty())
				for (int i = 0, j = 0; i < open.getMax_size(); i++) {
					if (open.arr[i]) {
						chain.add(open.arr[i]->key, open.arr[i]->value);
					}
				}
		}
	}

	void clear() {
		if (is_chain) {
			chain.clear();
		}
		else {
			open.clear();
		}
	}

	bool isChain() {
		return is_chain;
		//if (is_chain) {
		//	std::cout << "Chain" << std::endl;
		//}
		//else {
		//	std::cout << "Open" << std::endl;
		//}
	}
	

	class Iterator {
		
		MainHashTable* mht;
		int id;
		int chain_id;
	public:
		Iterator(MainHashTable* _mht) {
			mht = _mht;
			id = 0;
			chain_id = 0;

			if (mht->is_chain) {
				mht->chain.it_node = mht->chain.arr[0];
			}
			else {
				mht->open.it_node = mht->open.arr[0];
			}

		}
		Iterator(MainHashTable* _mht, int i) {
			mht = _mht;
			id = i;
			chain_id = i;

		}

		Data& operator*() {
			if (mht->is_chain) {
				if (chain_id >= mht->chain.max_size || chain_id < 0) throw "Exeption";

				if (!mht->chain.it_node) throw 1;

				return mht->chain.it_node->value;
			}
			else {
				if (id >= mht->open.max_size || id < 0) throw "Exeption";
				if (!mht->open.it_node) throw 1;
				return mht->open.it_node->value;
			}
		}

		Iterator* operator ++() {
			if (mht->is_chain) {
				if (chain_id>mht->chain.max_size) throw "Exeption";
				if(mht->chain.it_node)
				if (mht->chain.it_node->next) {
					mht->chain.it_node = mht->chain.it_node->next;
					return this;
				}
				chain_id++;
				mht->chain.it_node = mht->chain.arr[chain_id];

				return this;
			}
			else {
				if (id > mht->open.max_size) throw "Exeption";
				id++;
				mht->open.it_node = mht->open.arr[id];
				return this;

			}

		}

		bool operator ==(const Iterator* it) {
			if (mht->is_chain) {
				if (chain_id == it->chain_id) return true;
				else return false;
			}
			else {
				if (id == it->id) return true;
				else return false;

			}
		}

		bool operator !=(const Iterator* it) {
			if (mht->is_chain) {
				if (chain_id == it->chain_id) return false;
				else return true;
			}
			else {
				if (id == it->id) return false;
				else return true;

			}
		}

	};
	//Добавить кейсы для р_итератора
	//Придумать как реализовать с чейн хэш табле


	Iterator* begin() {
		Iterator* beg = new Iterator(this);
		return beg;
	}
	Iterator* end() {
		if (is_chain) {
			Iterator* beg = new Iterator(this, chain.getMax_size());
			return beg;
		}
		else {
			Iterator* beg = new Iterator(this, open.getMax_size());
			return beg;
		}
	}

	int getN(int i) {
		if (is_chain) {
			return chain.getN(i);
		}
	}

};