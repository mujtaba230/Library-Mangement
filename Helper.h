#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <iostream>
using namespace std;


class Helper
{
public:

	static int Str_Length(const char* str);
	
	static void Str_Copy(char*& dest, const char*& source);
	
	static void Str_Copy(char*& dest, char* const source);
	
	static int Compare_String(char* s1, char* s2);
	
	static int Compare_String(char* s1, const char* s2);
	
	static void ClearScreen();
	
	static void Change_Theme(char x);

};

//	FUNCTION DEFINITIONS


int Helper::Str_Length(const char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return i;
}

void Helper::Str_Copy(char*& dest, const char*& source)
{
	int length = Str_Length(source);
	dest = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		dest[i] = source[i];
	}
	dest[length] = '\0';
}

void Helper::Str_Copy(char*& dest, char* const source)
{
	int length = Str_Length(source);
	dest = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		dest[i] = source[i];
	}
	dest[length] = '\0';
}

int Helper::Compare_String(char* s1, char* s2)
{
	int length = Helper::Str_Length(s1);
	for (int i = 0; i < length; i++)
	{
		if (s1[i] != s2[i])
		{
			return 0;
		}
	}
	return 1;
}

int Helper::Compare_String(char* s1, const char* s2)
{
	int length = Helper::Str_Length(s1);
	for (int i = 0; i < length; i++)
	{
		if (s1[i] != s2[i])
		{
			return 0;
		}
	}
	return 1;
}

void Helper::ClearScreen()
{
	system("cls");
}

void Helper::Change_Theme(char x)
{
	if (x == 1)
	{
		system("color F0");		//white
	}
	else if (x == 2)
	{
		system("color 1F");		//blue
	}
	else if (x == 3)
	{
		system("color 2F");		//green
	}
	else if (x == 4)
	{
		system("color 5F");		//purple
	}
	else
	{
		system("color 31");
	}
}