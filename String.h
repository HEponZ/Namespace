#pragma once
#include "Namesapces.h"

namespace String_space
{
	class String {
	private:
		char* string;
		int size;
		static int count;
	public:
		String() : String(80) {};
		String(int size) : String(nullptr, size) {};
		String(char* string_S, int size_S);

		const char* get_string() { return string; }
		const int get_size() { return size; }
		void set_string(const char* string_S);
		void set_size(const int size_S) { size = size_S; }


		String* sin_str(String* str_mas, int& size);
		void print(String* str_mas, int& size);
		static int get_count() { return count; }

		~String();
	};

}