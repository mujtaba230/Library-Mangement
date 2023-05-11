#pragma once
#include"Helper.h"
#include"AVLTree.h"
#include"BookReference.h"

using namespace std;


class Library
{
private:

	AVL<BookRef> Reference_Books;
	DoublyLinkedList<Books> allBooks;

public:

	Library() {}

	void Add_Book(int Issn, char* title_, char** authors_, int reference_Book, int issuableBookCount)
	{
		Books* New_Book = new Books{ Issn,title_,authors_,reference_Book,issuableBookCount };
		allBooks.Insert_Sorted(*New_Book);
		auto book = allBooks.Search(*New_Book);
		Reference_Books.Insert(BookRef{ Issn, book });

	}
	
	void Review_Book()
	{
		Helper::ClearScreen();
		int Issn;
		cout << "Enter the ISSN number of the book you wish to view the record of : ";
		cin >> Issn;
		Helper::ClearScreen();
		Review_(Issn);
	}
	
	void Update_()
	{
		Helper::ClearScreen();
		int c;
		cout << "Enter the ISSN of the book to modify records ";
		cin >> c;
		Helper::ClearScreen();
		Update_(c);
	}
	
	void Delete_Book()
	{
		Helper::ClearScreen();;
		int issn;
		cout << "Enter the ISSN number of the book you want to delete : ";
		cin >> issn;
		Helper::ClearScreen();
		Delete_(issn);
	}

	void Create_Book()
	{
		system("cls");
		cout << "Enter Title of the book : ";
		char* name = new char[100];
		cin.ignore();
		cin.getline(name, 100);

		cout << "\nEnter the ISSN number of the book : ";
		int issn;
		cin >> issn;

		cout << "\nEnter number of Authors_ of the book : ";
		int num;
		cin >> num;

		char** Authors_ = new char* [num + 1];
		for (int i = 0; i < num; i++)
		{
			cout << "\nEnter name of author : ";
			char* temp = new char[100];
			if (i == 0)
				cin.ignore();
			cin.getline(temp, 100);
			Helper::Str_Copy(Authors_[i], temp);
		}
		Authors_[num] = NULL;

		cout << "\nEnter number of copies available as reference book : ";
		int n1;
		cin >> n1;

		cout << "\nEnter number of copies available as issuable book : ";
		int n2;
		cin >> n2;

		Add_Book(issn, name, Authors_, n1, n2);
	}

	void Print_All_Books()
	{
		Helper::ClearScreen();
		allBooks.Print();
	}

	void Execute()
	{
		bool Flag = 1;
		while (Flag)
		{
			cout << "LIBRARY DATABASE SYSTEM\n" << endl;
			int val;
			cout << "1. Create a Books Record\n";
			cout << "2. Review a Books Record\n";
			cout << "3. Update_ a Books Record\n";
			cout << "4. Delete_ a Books Record\n";
			cout << "5. List all Books Records\n";
			cout << "\nChoose desired operation : ";
			cout << "\nOr Press Any other key to exit : ";
			cin >> val;

			if (val == 1) { Create_Book(); }
			else if (val == 2) { Review_Book(); break; }
			else if (val == 3) { Update_(); break; }
			else if (val == 4) { Delete_Book(); break; }
			else if (val == 5) { Print_All_Books(); break; }
			else { Flag = 0; }

		}
	}

	void Update_(int Issn)
	{
		Reference_Books.searchBook(Issn).Update_();
	}
	
	void Review_(int Issn)
	{
		DoublyLinkedList<Books>::Iterator book_ = Reference_Books.Search(Issn);		//Searches from the list of all the books 
		cout << (*book_);

	}
	
	void Delete_(int Issn)
	{
		DoublyLinkedList<Books>::Iterator book = Reference_Books.Search(Issn);
		allBooks.erase(book);
	}
};
