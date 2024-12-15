#include "Namesapces.h"

void PhoneBook::set_SNP(const char* SNP_S)
{
	if (SNP)
	{
		delete[] SNP;
	}

	SNP = new char[strlen(SNP_S) + 1];
	strcpy_s(SNP, strlen(SNP_S) + 1, SNP_S);
}

void PhoneBook::set_add_info(const char* add_info_S)
{
	if (add_info)
	{
		delete[] add_info;
	}
	add_info = new char[strlen(add_info_S) + 1];
	strcpy_s(add_info, strlen(add_info_S) + 1, add_info_S);
}

PhoneBook::PhoneBook(const char* home_phone_S, const char* work_phone_S, const char* mob_phone_S, const char* SNP_S, const char* add_info_S)
	: SNP{ new char[strlen(SNP_S) + 1] },
	add_info{ new char[strlen(add_info_S) + 1] }
{
	strcpy_s(home_phone, home_phone_S);
	strcpy_s(work_phone, work_phone_S);
	strcpy_s(mob_phone, mob_phone_S);
	strcpy_s(SNP, strlen(SNP_S) + 1, SNP_S);
	strcpy_s(add_info, strlen(add_info_S) + 1, add_info_S);
}

PhoneBook::~PhoneBook()
{
	delete[] SNP;
	delete[] add_info;
}