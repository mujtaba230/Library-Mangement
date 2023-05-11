#pragma once
#include"Helper.h"
using namespace std;

template <class v>
class HashItem
{
public:
	int key;
	v value;
	short status;

	HashItem()
	{
		status = empty;
	}
	
	HashItem(int key, v data)
	{
		this->key = key;
		value = data;
		this->status = occupied;
	}

	void operator=(const HashItem& rhs)
	{
		this->key = rhs.key;
		this->status = rhs.status;
		this->value = rhs.value;
	}
	
	void insert(int key, v data)
	{
		this->key = key;
		value = data;
		this->status = occupied;
	}
};