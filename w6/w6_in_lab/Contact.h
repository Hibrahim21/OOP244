/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/

#ifndef CONTACT_H
#define CONTACT_H

namespace sict {
	const int max_name_size = 16;
	class Contact
	{
		char c_name[max_name_size];
		long long* c_phone;
		int c_num;
	public:
		Contact();
		Contact(const char*, const long long*, int);
		~Contact();
		bool isEmpty() const;
		void display() const;
	};
}

#endif // !CONTACT_H