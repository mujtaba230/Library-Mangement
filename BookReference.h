#pragma once
#include"Helper.h"
#include"DoublyLinkedList.h"
#include"Books.h"
using namespace std;


class BookRef
{
private:

	int ISSN_No;
	DoublyLinkedList<Books>::Iterator Node_In_List;

public:

	BookRef(int issn, DoublyLinkedList<Books>::Iterator it)
	{
		ISSN_No = issn;
		Node_In_List = it;
	}
	
	BookRef()
	{
		ISSN_No = 0;
		Node_In_List = NULL;
	}
	
	int Get_ISSN()
	{
		return ISSN_No;
	}
	
	auto Get_Node_In_List()
	{
		return Node_In_List;
	}
	
	friend bool operator== (const BookRef& b1, const BookRef& b2)
	{
		return (b1.ISSN_No == b2.ISSN_No);
	}
	
	friend bool operator< (const BookRef& b1, const BookRef& b2)
	{
		return (b1.ISSN_No < b2.ISSN_No);
	}
	
	friend bool operator> (const BookRef& b1, const BookRef& b2)
	{
		return (b1.ISSN_No > b2.ISSN_No);
	}
};
