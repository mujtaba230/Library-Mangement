#pragma once
#include"Helper.h"
using namespace std;

class Books
{
private:
	int ISSN;
	int Issue_Count;
	int Reference_Book_Count;
	char* Title;
	char** Authors;

public:

	Books()
	{
		ISSN = 0;
		Issue_Count = 0;
		Reference_Book_Count = 0;
	}

	Books(int Issn, char* Title, char** Authors_, int Issueed_Books_Count, int RefBookCount)
	{
		ISSN = Issn;
		Issue_Count = Issueed_Books_Count;
		Reference_Book_Count = RefBookCount;

		Helper::Str_Copy(Title, Title);

		int i;
		for (i = 0; Authors_[i] != NULL; i++);

		Authors = new char* [i + 1];

		for (int j = 0; j < i; j++)
		{
			Helper::Str_Copy(Authors[j], Authors_[j]);
		}
		Authors[i] = NULL;
	}

	friend ostream& operator<< (std::ostream& out, const Books& b)
	{
		cout << "Name of the book : " << b.Title << endl << endl;
		cout << "ISSN of the book : " << b.ISSN << endl << endl;
		int i = 0;
		cout << "Authors of the book are:\n";
		while (b.Authors[i] != NULL)
		{
			cout << "       " << i + 1 << ". " << b.Authors[i] << endl;
			i++;
		}
		cout << "\nNumber of copies available as reference books : " << b.Reference_Book_Count << endl << endl;
		cout << "Number of copies available as issuable books : " << b.Issue_Count << endl << endl;
		cout << "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
		return out;
	}
	
	friend bool operator== (const Books& b1, const Books& b2)
	{
		return (b2.ISSN == b1.ISSN);
	}
	
	friend bool operator< (const Books& b1, const Books& b2)
	{
		return (b1.ISSN < b2.ISSN);
	}
	
	friend bool operator> (const Books& b1, const Books& b2)
	{
		return (b1.ISSN > b2.ISSN);
	}
	
	Books& operator= (const Books& b)
	{
		this->Issue_Count = b.Issue_Count;
		this->Reference_Book_Count = b.Reference_Book_Count;
		Helper::Str_Copy(this->Title, b.Title);
		int c = 0;
		while (b.Authors[c] != NULL)
			++c;
		this->Authors = new char* [c + 1];
		for (int i = 0; i < c; i++)
		{
			Helper::Str_Copy(this->Authors[i], b.Authors[i]);
		}
		Authors[c] = NULL;

		return *this;

	}

	void Update_()
	{
		int New_Title;

		cout << "Press 1 to Change the Title of the Books \n";
		cout << "Press 2 to Change the Authors of the Books \n";
		cout << "Press 3 to Change the No of Copies of the Books \n";
		cout << "Press 4 to Change the No of Copies Available as Issueable Books \n";
		cin >> New_Title;

		if (New_Title == 1)
		{
			cout << "Enter new Title of the book : ";
			char* Name = new char[100];
			cin.ignore();
			cin.getline(Name, 100);
			Helper::Str_Copy(Title, Name);
		}

		if (New_Title == 2)
		{
			cout << "\nEnter number of new Authors_ of the book : ";
			int Author_Count;
			cin >> Author_Count;

			Authors = new char* [Author_Count + 1];
			for (int i = 0; i < Author_Count; i++)
			{
				cout << "\n Enter name of New Author : ";
				char* temp = new char[100];
				cin.ignore();
				cin.getline(temp, 100);
				Helper::Str_Copy(Authors[i], temp);
			}
			Authors[Author_Count] = NULL;
		}

		if (New_Title == 3)
		{
			cout << "\nEnter number of copies available as reference book : ";
			cin >> Reference_Book_Count;
		}

		if (New_Title == 4)
		{
			cout << "\nEnter number of copies available as issuable book : ";
			cin >> Issue_Count;
		}

	}

};
