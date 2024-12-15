#include "Namesapces.h"

void String::print(String* str_mas, int& size)
{
	for (int i{ 0 }; i < size; i++)
	{
		printf("%s\n", str_mas[i].get_string());
	}
}

String* String::sin_str(String* str_mas, int& size)
{
	String* new_str_mas = new String[++size];
	char buffer[100]{ "\0" };

	cin.ignore();
	cout << "¬ведите новую строку: ";
	gets_s(buffer);
	new_str_mas[size - 1].set_string(buffer);

	for (int i = 0; i < size - 1; i++)
	{
		new_str_mas[i].set_string(str_mas[i].get_string());
	}

	delete[] str_mas;

	return new_str_mas;
}

int String::count{ 0 };

void String::set_string(const char* string_S)
{
	if (string)
	{
		delete[] string;
	}
	string = new char[strlen(string_S) + 1];
	strcpy_s(string, strlen(string_S) + 1, string_S);
}

String::~String()
{
	count--;
	delete[] string;
}

String::String(char* string_S, int size_S) : string{ new char[size_S] }, size{ size_S }
{
	count++;
	if (string_S)
	{
		strcpy_s(string, size_S, string_S);
	}
}