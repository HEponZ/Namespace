#include "Namesapces.h"

int Fraction::reduction(int& num, int& den)
{
	int buf_num = num, buf_den = den;

	while (buf_num != buf_den)
	{
		if (buf_num > buf_den)
		{
			buf_num = buf_num - buf_den;
		}
		else
		{
			buf_den = buf_den - buf_num;
		}
	}

	return buf_den;
}

void Fraction::set_num(int numerator_S)
{
	numerator = numerator_S;
}

void Fraction::set_den(int denominator_S)
{
	if (denominator_S != 0)
	{
		denominator = denominator_S;
	}
	else
	{
		cout << "Ошибка, знаменатель не должен быть равен нулю!!!\n";
	}
}

Fraction::Fraction(int numerator_S, int denominator_S)
{
	numerator = numerator_S;
	denominator = denominator_S;
}

void Fraction::sum(int num2, int den2)
{
	int num, den, NoD;

	den = denominator * den2;
	num = numerator * den2 + num2 * denominator;

	NoD = reduction(num, den);

	printf("Сумма дробей: %d/%d\n", num / NoD, den / NoD);
}

void Fraction::diff(int num2, int den2)
{
	int num, den, NoD;

	den = denominator * den2;
	num = numerator * den2 - num2 * denominator;

	NoD = reduction(num, den);

	printf("Разность дробей: %d/%d\n", num / NoD, den / NoD);
}

void Fraction::compos(int num2, int den2)
{
	int num, den, NoD;

	den = denominator * den2;
	num = numerator * num2;

	NoD = reduction(num, den);

	printf("Произведение дробей: %d/%d\n", num / NoD, den / NoD);
}

void Fraction::division(int num2, int den2)
{
	int num, den, NoD;

	den = denominator * num2;
	num = numerator * den2;

	NoD = reduction(num, den);

	printf("Частное дробей: %d/%d\n", num / NoD, den / NoD);
}