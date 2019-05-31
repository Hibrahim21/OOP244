/*
Name: Hamza Ibrahim
Seneca ID: 107467185
Seneca Email: hibrahim21@myseneca.ca
*/
#ifndef SICT_IACCOUNT_H
#define SICT_IACCOUNT_H
#include <iostream>

namespace sict {

	class iAccount {
		
	public:
		virtual ~iAccount() {};
		virtual bool credit(double amount) = 0;
		virtual bool debit(double amount) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream& out) const = 0;
	};
	iAccount* CreateAccount(const char* type, double balance);
}

#endif // !SICT_IACCOUNT_H
