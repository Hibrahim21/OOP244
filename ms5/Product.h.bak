/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/

#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H
#include "iProduct.h"
#include "ErrorState.h"
#include <iostream>

namespace ama {

	class Product : public iProduct {

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
		int operator+=(int qty);
		bool operator==(const char* sku) const;
		bool operator> (const char* sku) const;
		bool operator> (const iProduct& other) const;
		const  char* name() const;
		int qtyAvailable() const;
		int qtyNeeded() const;
		double total_cost() const;
		bool isEmpty() const;
		std::istream& read(std::istream& in, bool interractive);
		std::ostream& write(std::ostream& out, int writeMode) const;
	};

}

#endif // !AMA_PRODUCT_H
