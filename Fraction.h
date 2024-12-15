#pragma once

namespace Fraction_space
{
	class Fraction {
	private:
		int numerator;
		int denominator;

		int reduction(int& num, int& den);
	public:
		Fraction() : Fraction(1, 1) {}
		Fraction(int numerator_S, int denominator_S);
		int get_num() { return numerator; }
		int get_den() { return denominator; }


		void set_num(int numerator_S);
		void set_den(int denominator_S);

		void sum(int num2, int den2);
		void diff(int num2, int den2);
		void compos(int num2, int den2);
		void division(int num2, int den2);

		void print() { printf("%d/%d\n", numerator, denominator); }
	};
}