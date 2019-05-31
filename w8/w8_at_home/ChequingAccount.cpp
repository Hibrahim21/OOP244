/*
Name: Hamza Ibrahim
Seneca ID: 107467185
Seneca Email: hibrahim21@myseneca.ca
*/
#include <iostream>
#include <iomanip>
#include "ChequingAccount.h"

using namespace std;

namespace sict {
	ChequingAccount::ChequingAccount(){
		ch_transaction = 0.0;
		ch_monthfee = 0.0;
	}

	ChequingAccount::ChequingAccount(double balance, double transfee, double monthlyFee) : Account(balance) {
		if (transfee > 0) {
			ch_transaction = transfee;
		}
		else {
			ch_transaction = 0.0;
		}
		if (monthlyFee > 0) {
			ch_monthfee = monthlyFee;
		}
		else {
			ch_monthfee = 0.0;
		}
	}
	
	bool ChequingAccount::credit(double amount){
		Account::debit(ch_transaction);
		return Account::credit(amount);
	}
	
	bool ChequingAccount::debit(double amount){
		return Account::debit(amount + ch_transaction);
	}
	
	void ChequingAccount::monthEnd(){
		Account::debit(ch_monthfee);
	}
	
	void ChequingAccount::display(std::ostream & out) const{
		out << "Account type: Chequing" << endl;

		out.precision(2);
		out.setf(out.fixed, out.floatfield);

		out << "Balance: $" << Account::balance() << endl;
		out << "Per Transaction Fee: " << ch_transaction << endl;
		out << "Monthly Fee: " << ch_monthfee << endl;
	}
}
