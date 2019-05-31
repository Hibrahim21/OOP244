/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/

#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "Contact.h"

using namespace std;

namespace sict {

	Contact::Contact() {
		c_name[0] = '\0';
		c_phone = nullptr;
		c_num = 0;
	}

	Contact::~Contact() {
		if (c_phone != nullptr)
			delete[] c_phone;
		c_phone = nullptr;
	}

	Contact::Contact(const char* name, const long long* phone, int num) {
		c_phone = nullptr;
		c_num = 0;
		if (name != nullptr && name[0] != '\0' && num >= 0) {
			int count = 0;
			long long *t_Phones = new long long[num];
			long long temp;

			for (int cnt = 0; cnt < num; cnt++) {
				if (validation(phone[cnt])) {
					count++;
				}
			}
			strncpy(c_name, name, max_name_size);
			c_name[15] = '\0';

			if (c_name[max_name_size] != '\0') {
				c_name[max_name_size] = '\0';
			}
			c_num = count;
			c_phone = new long long[count];
			for (int i = 0; i < count; i++) {
				c_phone[i] = phone[i];
			}
			delete[] t_Phones;
		}
		else {
			*this = Contact();
		}
	}

	Contact::Contact(const Contact &idk) {
		c_phone = nullptr;
		*this = idk;
	}

	Contact & Contact::operator=(const Contact& idk) {
		if (this != &idk) {
			strcpy(c_name, idk.c_name);
			c_num = idk.c_num;
			delete[] c_phone;


			if (idk.c_phone != nullptr) {
				c_phone = new long long[c_num];
				for (int i = 0; i < c_num; i++)
					c_phone[i] = idk.c_phone[i];
			}
			else {
				c_phone = nullptr;
			}
		}
		return *this;
	}

	Contact & Contact::operator+=(long long phone) {

		if (validation(phone) == true) {
			c_num++;
			long long* t_PhoneNumbers = new long long[c_num];

			for (int i = 0; i < c_num - 1; ++i) {
				t_PhoneNumbers[i] = c_phone[i];
			}

			t_PhoneNumbers[c_num - 1] = phone;
			delete[] c_phone;
			c_phone = t_PhoneNumbers;
		}

		return *this;
	}

	bool Contact::isEmpty() const {
		if (c_name[0] == '\0')
			return true;
		else
			return false;
	}

	void Contact::display() const {
		if (isEmpty() == true) {
			cout << "Empty contact!" << endl;
		}
		else {
			string Ac, Cc, num, num2, pstring;
			int pString;

			cout << c_name << endl;

			for (int phone = 0; phone < c_num; phone++) {
				pstring = to_string(c_phone[phone]);
				pString = pstring.length();
				Cc = pstring.substr(0, (pString - (3 + 7)));
				Ac = pstring.substr(pString - (3 + 7), 3);
				num = pstring.substr(pString - 7, 3);
				num2 = pstring.substr(pString - 4, 4);

				cout << "(+" + Cc + ")" + " " + Ac + " " + num + "-" + num2 << endl;
			}
		}
	}

	bool Contact::validation(long long phone) {
		if (phone / 1000000000000 == 0 && phone / 10000000000 != 0) {
			phone -= (phone / 10000000000) * 10000000000;
			if (phone / 1000000000 != 0) {
				phone -= (phone / 10000000) * 10000000;
				if (phone / 1000000 != 0) {
					return true;
				}
			}
		}
		return false;
	}
}

