/*
Name: Hamza Ibrahim
Seneca ID: 107467185
Seneca Email: hibrahim21@myseneca.ca
*/
#include <iostream>
#include "SavingsAccount.h"

using namespace std;

namespace sict {

	const double intrestRate = 0.05;

	iAccount* CreateAccount(const char* type, double balance) {
		iAccount *NewAcc = nullptr;

		if (type[0] == 'S') {
			NewAcc = new SavingsAccount(balance, intrestRate);
			return NewAcc;
		}
		else return NULL;
	}

	/*
	iAccount::~iAccount(){

	}
	*/
}