/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/

#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H
#include "ErrorState.h"
#include <iostream>

namespace ama {
	const int max_length_label = 30;
	const int max_length_sku = 7;
	const int max_length_name = 75;
	const int max_length_unit = 10;
	const int write_condensed = 0;
	const int write_table = 1;
	const int write_human = 2;
	const float tax_rate = 0.13;

	class Product {

	private:

		const char p_type;
		char p_sku[max_length_sku + 1];
		char p_unit[max_length_unit + 1];
		char *p_name;
		int p_available;
		int p_needed;
		double p_bTax;
		bool taxable;
		ErrorState p_errorState;

	protected:

		void message(const char* pText);
		bool isClear() const;

	public:

		Product(char type = 'N');
		Product(const char *sku, const char *name, const char *unit, double b4Tax = 0.0, int needed = 0, int onHand = 0, bool taxtStatus = true);
		Product(const Product&);
		~Product();
		Product& operator=(const Product&);
		int operator+=(int cnt);
		bool operator==(const char* sku) const;
		bool operator> (const char* sku) const;
		bool operator> (const Product&) const;
		int qtyAvailable() const;
		int qtyNeeded() const;
		double total_cost() const;
		bool isEmpty() const;
		std::istream& read(std::istream& in, bool interractive);
		std::ostream& write(std::ostream& out, int writeMode) const;
	};

}

#endif // !AMA_PRODUCT_H
