/*
Name: Hamza Ibrahim
Seneca ID: 107467185
Seneca Email: hibrahim21@myseneca.ca
*/
#include <iostream>
#include "SavingsAccount.h"
#include "ChequingAccount.h"

using namespace std;

namespace sict {

	const double intrestRate = 0.05, transactionFee = 0.50, monthlyFee = 2.00;

	iAccount* CreateAccount(const char* type, double balance) {
		iAccount *NewAcc = nullptr;

		if (type[0] == 'S') {
			NewAcc = new SavingsAccount(balance, intrestRate);
			return NewAcc;
		}
		else if (type[0] == 'C') {
			NewAcc = new ChequingAccount(balance, transactionFee, monthlyFee);
			return NewAcc;
		}
		else return NULL;
	}

	/*
	iAccount::~iAccount(){

	}
	*/
}