#pragma once
#include"Helper.h"
using namespace std;

template <class T>
class DoublyLinkedList
{
	class Node
	{
	public:
		Node* next;
		Node* prev;
		T data;

		Node()
		{
			prev = next = NULL;
		}
	};

private:

	class Node;
	Node* head;
	Node* tail;

public:

	class Iterator
	{
		friend class DoublyLinkedList<T>;
	private:
		Node* curr;
	public:
		Iterator(Node* c = 0)
		{
			curr = c;
		}
		bool operator!=(const Iterator& itr)
		{
			if (this->curr != itr.curr)
			{
				return true;
			}
			return false;
		}
		T& operator*()
		{
			return curr->data;
		}
		Iterator operator++(int)
		{
			Iterator old = *this;
			curr = curr->next;
			return old;
		}
		Iterator operator--(int)
		{
			Iterator old = *this;
			curr = curr->prev;
			return old;
		}
	};

public:

	DoublyLinkedList()
	{
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
		head->prev = tail->next = 0;
	}
	
	void InsertAtStart(T const value)
	{
		Node* temp = new Node;
		temp->data = value;
		temp->next = head->next;
		temp->prev = head;
		head->next->prev = temp;
		head->next = temp;
	}
	
	void InsertAtEnd(T const value)
	{
		Node* temp = new Node;
		temp->data = value;
		temp->next = tail;
		temp->prev = tail->prev;
		tail->prev->next = temp;
		tail->prev = temp;
	}
	
	void Print()
	{
		if (head->next != nullptr)
		{
			Node* ptr = head->next;
			while (ptr != tail)
			{
				cout << ptr->data << ' ';
				ptr = ptr->next;
			}
			cout << '\n';
		}
		else
		{
			cout << "Empty List\n";
		}
	}
	
	void DeleteAtStart()
	{
		Node* temp = head->next;
		head->next = temp->next;
		temp->next->prev = head;
		delete temp;
	}
	
	void DeleteAtEnd()
	{
		if (head->next != tail)
		{
			Node* temp = tail->prev;
			temp->prev->next = tail;
			tail->prev = temp->prev;
			delete temp;
		}
	}
	
	Iterator InsertBefore(Iterator position, const T& value)
	{
		Node* temp = new Node;
		temp->data = value;
		Node* t = position.curr;
		temp->next = t;
		temp->prev = t->prev;
		temp->prev->next = temp;
		t->prev = temp;
		return position;
	}
	
	Iterator InsertAfter(Iterator position, const T& value)
	{
		Node* temp = new Node;
		temp->data = value;
		Node* t = position.curr;
		temp->prev = t;
		temp->next = t->next;
		t->next->prev = temp;
		t->next = temp;
		return position;
	}
	
	Iterator erase(Iterator position)
	{
		Node* temp = position.curr;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		Iterator it(temp->next);
		delete temp;
		return it;
	}
	
	Iterator Search(T d)
	{
		for (Iterator it = Begin(); it != End(); it++)
		{
			if (*it == d)
			{
				return it;
			}
		}
		return 0;
	}
	
	Iterator Begin()
	{
		Iterator it;
		it.curr = head->next;
		return it;
	}
	
	Iterator End()
	{
		Iterator it(tail);
		return tail;
	}
	
	void Insert_Sorted(const T d)
	{
		auto it = End();
		it--;
		if (d > *(it))
		{
			InsertAtEnd(d);
		}
		else if (d < *(Begin()))
		{
			InsertAtStart(d);
		}
		else
		{
			Node* curr = head->next;
			for (auto iter = Begin(); iter != End(); iter++)
			{
				if ((curr->data < d) && (curr->next->data > d))
				{
					InsertAfter(iter, d);
					break;
				}
				else
					curr = curr->next;
			}
		}

	}
};
