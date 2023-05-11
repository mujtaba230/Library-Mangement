#pragma once
#include"Helper.h"
#include"Books.h"
using namespace std;


template <class T>
class AVL
{
	class ANode
	{
	public:
		T data;
		ANode* left;
		ANode* right;
		int height;
		ANode()
		{
			left = right = 0;
		}
		ANode(T d, ANode* l, ANode* r, int h)
		{
			data = d;
			left = l;
			right = r;
			height = h;
		}
	};

	ANode* root;

public:


	AVL()
	{
		root = 0;
	}
	
	int getHeight(ANode* r)
	{
		if (!r)
		{
			return -1;
		}
		return r->height;
	}
	
	int max(int a, int b)
	{
		if (a > b)
			return a;
		return b;
	}
	
	int balanceFactor(ANode* r)
	{
		return getHeight(r->left) - getHeight(r->right);
	}
	
	void rotateLeft(ANode*& x)
	{
		ANode* y = x->right;
		x->right = y->left;
		y->left = x;
		x->height = 1 + max(getHeight(x->left), getHeight(x->right));
		y->height = 1 + max(x->height, getHeight(y->right));
		x = y;
	}
	
	void doubleRotateLeft(ANode*& x)
	{
		rotateRight(x->right);
		rotateLeft(x);
	}
	
	void rotateRight(ANode*& x)
	{
		ANode* y = x->left;
		x->left = y->right;
		y->right = x;
		x->height = 1 + max(getHeight(x->left), getHeight(x->right));
		y->height = 1 + max(x->height, getHeight(y->right));
		x = y;
	}
	
	void doubleRotateRight(ANode*& x)
	{
		rotateLeft(x->left);
		rotateRight(x);
	}
	
	bool Search(T val)
	{
		return Search(val, root);
	}
	
	auto Search(T val, ANode* r)
	{
		if (r)
		{
			if (r->data == val)
				return r;
			else if (r->data > val)
				return Search(val, r->left);
			else if (r->data < val)
				return Search(val, r->right);
		}
		return false;
	}
	
	void Insert(T d)
	{
		Insert(root, d);
	}
	
	void Insert(ANode*& r, T d)
	{
		if (!r)
		{
			r = new ANode(d, 0, 0, 0);
		}
		else {
			if (d < r->data)
			{
				Insert(r->left, d);
				if (balanceFactor(r) == 2 || balanceFactor(r) == -2)
				{
					if (d < r->left->data)
					{
						rotateRight(r);
					}
					else {
						doubleRotateRight(r);
					}
				}
			}
			else if (d > r->data)
			{
				Insert(r->right, d);
				if (balanceFactor(r) == 2 || balanceFactor(r) == -2)
				{
					if (d > r->right->data)
					{
						rotateLeft(r);
					}
					else
					{
						doubleRotateLeft(r);
					}
				}
			}
			r->height = 1 + max(getHeight(r->left), getHeight(r->right));
		}
	}
	
	T findMin()
	{
		return findMin(root);
	}
	
	T findMin(ANode* r)
	{
		static int min = r->data;
		if (r->left)
		{
			min = findMin(r->left);
		}
		return min;
	}
	
	void InOrder_Print()
	{
		InOrder_Print(root);
	}
	
	void InOrder_Print(ANode* r)
	{
		if (r)
		{
			InOrder_Print(r->left);
			cout << r->data << ' ';
			InOrder_Print(r->right);
		}
	}
	
	auto Search(int val, ANode* r)
	{
		if (r)
		{
			if (r->data.Get_ISSN() == val)
				return r->data.Get_Node_In_List();
			else if (r->data.Get_ISSN() > val)
				return Search(val, r->left);
			else if (r->data.Get_ISSN() < val)
				return Search(val, r->right);
		}
	}
	
	auto Search(int val)
	{
		return Search(val, root);
	}
	
	Books& searchBook(int val, ANode* r)
	{
		if (r)
		{
			if (r->data.Get_ISSN() == val)
			{
				return *(r->data.Get_Node_In_List());
			}

			else if (r->data.Get_ISSN() > val)
			{
				return searchBook(val, r->left);
			}

			else if (r->data.Get_ISSN() < val)
			{
				return searchBook(val, r->right);
			}

		}
	}
	
	Books& searchBook(int issn)
	{
		return searchBook(issn, root);
	}
};
