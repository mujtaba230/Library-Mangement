#pragma once
#include"Helper.h"
using namespace std;

template <class v>
class HashMap
{
private:
	
	vector<list<HashItem<v>>> My_Hash_Array;
	
	int currentElements;
	
	void DoubleCapacity_()
	{
		std::vector<list<HashItem<v>>> OLD_Arr;
		OLD_Arr.resize(capacity);
		for (int i = 0; i < capacity; i++) {
			OLD_Arr[i] = My_Hash_Array[i];
		}

		capacity = 2 * capacity;
		My_Hash_Array.clear();
		currentElements = 0;
		My_Hash_Array.resize(capacity);
		for (int i = 0; i < capacity / 2; i++) {
			list<HashItem<v>>::template iterator it = OLD_Arr[i].begin();
			for (it; it != OLD_Arr[i].end(); it++) {
				int key = (*it).key;
				v data = (*it).value;
				insert(key, data);
			}
		}
		OLD_Arr.clear();
	}
	
	void Hash_Function()
	{
		srand(time(0));
		arbitary_value_2 = (rand() % prime_Number) + 1;
		arbitary_value_1 = rand() % prime_Number;
	}
	
	int hashFunction(int key)
	{
		int idx = ((arbitary_value_2 * key + arbitary_value_1) % prime_Number) % capacity;
		return idx;
	}
	
	const int prime_Number = 7;
	
	int arbitary_value_2;
	
	int arbitary_value_1;

public:
	
	HashMap()
	{
		capacity = 10;
		My_Hash_Array.resize(capacity);
		currentElements = 0;
		Hash_Function();
	}
	
	HashMap(int const capacity)
	{
		if (capacity > 1) {
			this->capacity = capacity;
			My_Hash_Array.resize(capacity);
			currentElements = 0;
		}
	}
	
	void insert(int const key, v const value)
	{
		int index = hashFunction(key);

		HashItem<v> temp(key, value);
		My_Hash_Array[index].push_back(temp);

		currentElements++;
		if ((currentElements * 1.00) / capacity >= 0.75) {
			DoubleCapacity_();
		}
	}
	
	bool deleteKey(int const key)
	{
		int index = hashFunction(key);

		list<HashItem<v>>:: template iterator it = My_Hash_Array[index].begin();
		for (it; it != My_Hash_Array[index].end(); it++) {
			if ((*it).key == key) {
				(*it).status = 1;
				return true;
			}
		}
		return false;
	}
	
	v* get(int const key)
	{
		int index = hashFunction(key);

		list<HashItem<v>>:: template iterator itr = My_Hash_Array[index].begin();
		for (itr; itr != My_Hash_Array[index].end(); itr++)
		{
			if ((*itr).key == key && (*itr).status != 1)
			{
				return &(*itr).value;
			}
		}
		return 0;
	}
	
	void print()
	{
		for (int i = 0; i < capacity; i++)
		{
			list<HashItem<v>>:: template iterator it = My_Hash_Array[i].begin();
			for (it; it != My_Hash_Array[i].end(); it++)
			{
				cout << (*it).key << " : " << (*it).value << '\n';
			}
		}
	}
	
	~HashMap()
	{

	}

protected:

	int capacity;
};
