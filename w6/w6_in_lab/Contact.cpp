/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/

#include <iostream>
#include <cstring>
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
		if (c_name != nullptr)
			delete[] c_phone;
		c_phone = nullptr;
	}

	Contact::Contact(const char* name, const long long* phone, int num) {
		if (name != nullptr && name[0] != '\0' && num >= 0) {
			int count = 0;
			long long *t_Phones = new long long[num];
			long long temp;

			for (int cnt = 0; cnt < num; cnt++) {

				if (phone[cnt] / 1000000000000 == 0 && phone[cnt] / 10000000000 != 0) {
					temp = phone[cnt];
					temp -= (temp / 10000000000) * 10000000000;
					if (temp / 1000000000 != 0) {
						temp -= (temp / 10000000) * 10000000;
						if (temp / 1000000 != 0) {
							t_Phones[count] = phone[cnt];
							count++;
						}
					}
				}
			}
			strncpy(c_name, name, max_name_size);
			c_name[15] = '\0';

			if (c_name[max_name_size] != '\0') {
				c_name[max_name_size] = '\0';
				c_num = count;
				c_phone = new long long[count];
				for (int i = 0; i < count; i++) {
					c_phone[i] = t_Phones[i];
				}
				delete[] t_Phones;
			}
		}
		else {
			*this = Contact();
		}
	}

	bool Contact::isEmpty() const {
		if (c_name[0] == '\0'&&c_phone == nullptr&&c_num == 0)
			return true;
		else
			return false;
	}

	void Contact::display() const {
		if (isEmpty() == true) {
			cout << "Empty contact!" << endl;
		}
		else {
			int countryCode, areaCode, num1, num2;
			cout << c_name << endl;

			for (int i = 0; i < c_num; i++) {

				countryCode = this->c_phone[i] / 10000000000;
				this->c_phone[i] -= countryCode * 10000000000;
				areaCode = this->c_phone[i] / 10000000;
				this->c_phone[i] -= areaCode * 1e7;
				num1 = this->c_phone[i] / 10000;
				this->c_phone[i] -= num1 * 10000;
				num2 = this->c_phone[i];
				cout << "(+" << countryCode << ") " << areaCode << " " << num1 << "-" << setfill('0') << setw(4) << num2 << endl;
			}
		}
	}
}
