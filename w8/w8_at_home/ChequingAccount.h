/*
Name: Hamza Ibrahim
Seneca ID: 107467185
Seneca Email: hibrahim21@myseneca.ca
*/
#ifndef SICT_CHEQUINGSACCOUNT_H
#define SICT_CHEQUINGSACCOUNT_H
#include <iostream>
#include "Account.h"

namespace sict {

	class  ChequingAccount : public Account {
		double ch_transaction, ch_monthfee;

	public:
		ChequingAccount();
		ChequingAccount(double balance, double transfee, double monthlyFee);
		bool credit(double amount);
		bool debit(double amount);
		void monthEnd();
		void display(std::ostream& out) const;
	};
}

#endif // !SICT_CHEQUINGSACCOUNT_H