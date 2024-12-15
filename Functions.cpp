#include "Namesapces.h"

PhoneBook* add(PhoneBook* obj_mas, int& size)
{
	PhoneBook* new_people = new PhoneBook[++size];
	char buffer[100]{ "\0" };

	cin.ignore();
	cout << "Введите номер домашнего телефона: ";
	gets_s(buffer);
	new_people[size - 1].set_home_phone(buffer);

	cout << "Введите номер рабочего телефона: ";
	gets_s(buffer);
	new_people[size - 1].set_work_phone(buffer);

	cout << "Введите номер мобильного телефона: ";
	gets_s(buffer);
	new_people[size - 1].set_mob_phone(buffer);

	cout << "Введите ФИО нового человека: ";
	gets_s(buffer);
	new_people[size - 1].set_SNP(buffer);

	cout << "Введите доп информацию о новом человеке: ";
	gets_s(buffer);
	new_people[size - 1].set_add_info(buffer);

	for (int i = 0; i < size - 1; i++)
	{
		new_people[i].set_home_phone(obj_mas[i].get_home_phone());
		new_people[i].set_work_phone(obj_mas[i].get_work_phone());
		new_people[i].set_mob_phone(obj_mas[i].get_mob_phone());
		new_people[i].set_SNP(obj_mas[i].get_SNP());
		new_people[i].set_add_info(obj_mas[i].get_add_info());
	}

	delete[] obj_mas;

	return new_people;
}

PhoneBook* delete_abonent(PhoneBook* obj_mas, int& size)
{
	PhoneBook* new_people = new PhoneBook[--size];

	int index = 0, j = 0;

	cout << "Введите номер удаляемого человека: ";
	cin >> index;
	--index;

	for (int i = 0; i < size + 1; i++)
	{
		if (i != index)
		{
			new_people[j].set_home_phone(obj_mas[i].get_home_phone());
			new_people[j].set_work_phone(obj_mas[i].get_work_phone());
			new_people[j].set_mob_phone(obj_mas[i].get_mob_phone());
			new_people[j].set_SNP(obj_mas[i].get_SNP());
			new_people[j].set_add_info(obj_mas[i].get_add_info());
			j++;
		}
	}
	delete[] obj_mas;

	return new_people;
}

PhoneBook* find(PhoneBook* obj_mas, int& size)
{
	char new_name[SIZE];

	cout << "Введите ФИО для поиска: ";
	cin.ignore();
	gets_s(new_name, SIZE);

	for (int i = 0; i < size; i++)
	{
		if (strcmp(obj_mas[i].get_SNP(), new_name) == 0)
		{
			return &obj_mas[i];
		}
	}

	return nullptr;
}

PhoneBook* download(PhoneBook* obj_mas, int& size)
{
	FILE* file;
	int count = 0;
	char buffer[SIZE]{ '\0' };

	if (fopen_s(&file, "PhoneBook.txt", "r") != NULL)
	{
		cout << "Не удалось открыть файл\n";
		return nullptr;
	}

	fscanf_s(file, "%d\n", &size);

	PhoneBook* new_mas = new PhoneBook[size];

	if (size)
	{
		for (int i = 0; i < size; i++)
		{
			fgets(buffer, PHONESIZE, file);
			*strchr(buffer, '\n') = '\0';
			new_mas[i].set_home_phone(buffer);
			fgets(buffer, PHONESIZE, file);
			*strchr(buffer, '\n') = '\0';
			new_mas[i].set_work_phone(buffer);
			fgets(buffer, PHONESIZE, file);
			*strchr(buffer, '\n') = '\0';
			new_mas[i].set_mob_phone(buffer);
			fgets(buffer, SIZE, file);
			*strchr(buffer, '\n') = '\0';
			new_mas[i].set_SNP(buffer);
			fgets(buffer, SIZE, file);
			*strchr(buffer, '\n') = '\0';
			new_mas[i].set_add_info(buffer);
		}
	}

	if (fclose(file) != NULL)
	{
		cout << "Не удалось закрыть файл\n";
		return nullptr;
	}
	delete[] obj_mas;

	return new_mas;
}

int load(PhoneBook* obj_mas, int& size)
{
	FILE* file;
	int count = 0;

	if (fopen_s(&file, "PhoneBook.txt", "w") != NULL)
	{
		cout << "Не удалось открыть файл\n";
		return 404;
	}

	fprintf_s(file, "%d", size);
	fputc('\n', file);

	for (int i = 0; i < size; i++)
	{
		fprintf_s(file, "%s\n%s\n%s\n%s\n%s\n", obj_mas[i].get_home_phone(), obj_mas[i].get_work_phone(), obj_mas[i].get_mob_phone(), obj_mas[i].get_SNP(), obj_mas[i].get_add_info());
	}

	if (fclose(file) != NULL)
	{
		cout << "Не удалось закрыть файл\n";
		return 404;
	}
}