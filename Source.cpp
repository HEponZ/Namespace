#include "Namesapces.h"

PhoneBook* add(PhoneBook* obj_mas, int& size);
PhoneBook* delete_abonent(PhoneBook* obj_mas, int& size);
PhoneBook* find(PhoneBook* obj_mas, int& size);
PhoneBook* download(PhoneBook* obj_mas, int& size);
int load(PhoneBook* obj_mas, int& size);

int main()
{
	setlocale(LC_ALL, "rus");
	int choise;
	enum MENU {
		FRACTION = 1,
		PHONEBOOK,
		STRING
	};
	// Для Fraction
	int numer, denom;
	Fraction fraction, fraction2;
	// Для PhoneBook
	int size = 0;
	PhoneBook* obj_mas{ nullptr };
	// Для String
	int size_str = 0;
	String* str_mas{ nullptr };

	cout << "1 - Fraction\n2 - PhoneBook\n3 - String\n";

	do
	{
		cin >> choise;

		switch (choise)
		{
		case FRACTION:
			cout << "Введите первый числитель: ";
			cin >> numer;
			cout << "Введите первый знаменатель: ";
			cin >> denom;
			fraction.set_num(numer);
			fraction.set_den(denom);

			cout << "Введите второй числитель: ";
			cin >> numer;
			cout << "Введите второй знаменатель: ";
			cin >> denom;
			fraction2.set_num(numer);
			fraction2.set_den(denom);

			fraction.sum(fraction2.get_num(), fraction2.get_den());
			break;

		case PHONEBOOK:
			obj_mas = add(obj_mas, size);

			for (int i = 0; i < size; i++)
			{
				printf("    %d\n%s\n%s\n%s\n%s\n%s\n", i + 1, obj_mas[i].get_home_phone(), obj_mas[i].get_work_phone(), obj_mas[i].get_mob_phone(), obj_mas[i].get_SNP(), obj_mas[i].get_add_info());
			}
			break;

		case STRING:
			str_mas = str_mas->sin_str(str_mas, size_str);
			str_mas->print(str_mas, size_str);
			printf("Кол-во строк: %d\n", str_mas->get_count());
			break;
		case 0:
			break;
		}
	} while (choise != 0);

	return 0;
}