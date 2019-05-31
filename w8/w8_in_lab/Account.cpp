/*
Name: Hamza Ibrahim
Seneca ID: 107467185
Seneca Email: hibrahim21@myseneca.ca
*/
#include <iostream>
#include "Account.h"

using namespace std;

namespace sict {

	double Account::balance() const{
		return a_balance;
	}

	Account::Account(){
		a_balance = 0.0;
	}

	Account::Account(double balance){
		if (balance > 0) 
			a_balance = balance;
		else 
			a_balance = 0.0;
	}

	bool Account::credit(double amount){
		if (amount < 0)
			return false;
		else {
			a_balance += amount;
			return true;
		}
	}

	bool Account::debit(double amount){
		if (amount < 0 || amount > a_balance)
			return false;
		else {
			a_balance -= amount;
			return true;
		}
	}
}