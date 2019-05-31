/*
Name: Hamza Ibrahim
Seneca ID: 107467185
Seneca Email: hibrahim21@myseneca.ca
*/
#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H
#include "iAccount.h"

namespace sict {

	class  Account : public iAccount {

	protected:
		double a_balance;
		double balance() const;

	public:
		Account();
		Account(double balance);
		bool credit(double amount);
		bool debit(double amount);
	};
	iAccount* CreateAccount(const char* type, double balance);
}

#endif // !SICT_ACCOUNT_H