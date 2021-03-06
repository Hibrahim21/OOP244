/*
Name: Hamza Ibrahim
Seneca ID: 107467185
Seneca Email: hibrahim21@myseneca.ca
*/
#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"

using namespace std;

namespace sict {
	SavingsAccount::SavingsAccount(){
		sa_intrest = 0.0;
	}

	SavingsAccount::SavingsAccount(double balance, double interestRate){
		if (interestRate > 0) {
			sa_intrest = interestRate;
			Account::a_balance = balance;
		}
		else {
			sa_intrest = 0.0;
		}
	}

	void SavingsAccount::monthEnd(){
		Account::credit(Account::balance() * sa_intrest);
	}

	void SavingsAccount::display(std::ostream & out) const{
		out << "Account type: Savings" << endl;

		out.setf(out.fixed, out.floatfield);
		out.precision(2);

		out << "Balance: $" << Account::balance() << endl;
		out << "Interest Rate (%): " << sa_intrest * 100 << endl;
	}
}
