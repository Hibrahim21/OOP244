/*
Name: Hamza Ibrahim
Seneca ID: 107467185
Seneca Email: hibrahim21@myseneca.ca
*/
#ifndef SICT_SAVINGSACCOUNT_H
#define SICT_SAVINGSACCOUNT_H
#include <iostream>
#include "Account.h"

namespace sict {

	class  SavingsAccount : public Account {
		double sa_intrest;

	public:
		SavingsAccount();
		SavingsAccount(double balance, double interestRate);
		void monthEnd();
		void display(std::ostream& out) const;
	};
}

#endif // !SICT_ACCOUNT_H