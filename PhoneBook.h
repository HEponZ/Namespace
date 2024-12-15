#pragma once

namespace PhoneBook_space
{
#define PHONESIZE 13
#define SIZE 100

	class PhoneBook {
	private:
		char home_phone[PHONESIZE];
		char work_phone[PHONESIZE];
		char mob_phone[PHONESIZE];
		char* SNP;
		char* add_info;

	public:
		PhoneBook() : SNP{ nullptr }, home_phone{ '\0' }, work_phone{ '\0' }, mob_phone{ '\0' }, add_info{ nullptr } {}
		PhoneBook(const char* home_phone_S, const char* work_phone_S, const char* mob_phone_S, const char* SNP_S, const char* add_info_S);

		const char* get_home_phone() { return home_phone; }
		const char* get_work_phone() { return work_phone; }
		const char* get_mob_phone() { return mob_phone; }

		const char* get_SNP() { return SNP; }
		const char* get_add_info() { return add_info; }

		void set_home_phone(const char* home_phone_S) { strcpy_s(home_phone, home_phone_S); }
		void set_work_phone(const char* work_phone_S) { strcpy_s(work_phone, work_phone_S); }
		void set_mob_phone(const char* mob_phone_S) { strcpy_s(mob_phone, mob_phone_S); }

		void set_SNP(const char* SNP_S);
		void set_add_info(const char* add_info_S);

		~PhoneBook();
	};
}