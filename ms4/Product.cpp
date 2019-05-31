/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include<string>
#include<string.h>
#include "Product.h"


using namespace std;

namespace ama {

	void Product::message(const char * pText) {
		p_errorState = pText;
	}

	bool Product::isClear() const {
		if (p_errorState.operator bool() == false) {
			return true;
		}
		else return false;
	}

	Product::Product(char type) : p_type(type) {

		p_sku[0] = '\0';
		p_unit[0] = '\0';
		p_name = nullptr;
		p_available = 0;
		p_needed = 0;
		p_bTax = 0.0;
		taxable = false;
	}

	Product::Product(const char *sku, const char *name, const char *unit, double b4Tax, int needed, int onHand, bool taxtStatus)
		: p_type('N') {

		if (name == nullptr || name[0] == '\0') {
			p_sku[0] = '\0';
			p_unit[0] = '\0';
			p_name = nullptr;
			p_available = 0;
			p_needed = 0;
			p_bTax = 0.0;
			taxable = false;
		}
		else {
			strcpy(p_sku, sku);
			p_name = new char[strlen(name) + 1];
			strcpy(p_name, name);
			strcpy(p_unit, unit);
			p_bTax = b4Tax;
			p_needed = needed;
			p_available = onHand;
			taxable = taxtStatus;
		}
	}

	Product::Product(const Product &idk)
		: p_type(idk.p_type) {

		strcpy(p_sku, idk.p_sku);

		if (idk.p_name != nullptr) {
			p_name = new char[max_length_name + 1];
			for (int cnt = 0; cnt < max_length_name; cnt++) {
				p_name[cnt] = idk.p_name[cnt];
			}
		}
		else p_name = nullptr;

		strcpy(p_unit, idk.p_unit);
		p_available = idk.p_available;
		p_needed = idk.p_needed;
		p_bTax = idk.p_bTax;
		taxable = idk.taxable;
	}

	Product::~Product() {

		delete[] p_name;
		p_name = nullptr;
	}

	Product & Product::operator=(const Product &idk) {

		if (this != &idk) {
			p_available = idk.p_available;
			p_needed = idk.p_needed;
			p_bTax = idk.p_bTax;
			taxable = idk.taxable;
			strcpy(p_sku, idk.p_sku);
			strcpy(p_unit, idk.p_unit);

			delete[] p_name;

			if (idk.p_name != nullptr) {
				p_name = new char[max_length_name + 1];
				for (int cnt = 0; cnt < max_length_name; cnt++) {
					p_name[cnt] = idk.p_name[cnt];
				}
			}
			else p_name = nullptr;
		}
		return *this;
	}

	int Product::operator+=(int qty) {
		if (qty > 0) {
			p_available += qty;
		}

		return p_available;
	}

	bool Product::operator==(const char * sku) const {
		if (strcmp(this->p_sku, sku) == 0) {
			return true;
		}
		else return false;
	}

	bool Product::operator>(const char * sku) const {
		if (strcmp(this->p_sku, sku) > 0) {
			return true;
		}
		else return false;
	}

	bool Product::operator>(const iProduct& others) const {
		if (strcmp(p_name, others.name()) > 0) {
			return true;
		}
		else return false;
	}

	const char * Product::name() const{
		return p_name;
	}

	int Product::qtyAvailable() const {
		return p_available;
	}

	int Product::qtyNeeded() const {
		return p_needed;
	}

	double Product::total_cost() const {
		double total = 0.0;
		if (taxable) {
			total = p_bTax * (1.0 + tax_rate);
		}
		else {
			total = p_bTax;
		}
		return total;
	}

	bool Product::isEmpty() const {
		if (p_name == nullptr) {
			return true;
		}
		else return false;
	}

	std::istream & Product::read(std::istream & in, bool interractive) {
		char taxed;
		char *name = new char[max_length_name + 1];
		char sku[max_length_sku + 1];
		char unit[max_length_unit + 1];
		int  avaliable = 0, needed = 0;
		double price = 0.0;
		bool tax = true;
		ErrorState err;
		char sep = ',';

		if (interractive == false) {
			in.getline(sku, max_length_sku + 1, ',');
			in.getline(name, max_length_name + 1, ',');
			in.getline(unit, max_length_name + 1, ',');

			in >> price;
			in >> sep;
			in >> tax;
			in >> sep;
			in >> avaliable;
			in >> sep;
			in >> needed;
		}

		else if(interractive == true){
			cout << setw(max_length_label) << right << "Sku: ";
			in >> sku;
			cout << setw(max_length_label) << right << "Name (no spaces): ";
			in >> name;

			cout << setw(max_length_label) << right << "Unit: ";
			in >> unit;
			
			cout << setw(max_length_label) << right << "Taxed? (y/n): ";
			in >> taxed;
			
			if (taxed == 'N' || taxed == 'n') {
				tax = false;
			}
			else if (taxed == 'Y' || taxed == 'y') {
				tax = true;
			}
			else if((taxed != 'N' || taxed != 'n') || (taxed != 'Y' || taxed != 'y')){
				in.setstate(ios::failbit);
				message("Only (Y)es or (N)o are acceptable!");
			}


			if (!in.fail()) {
				cout << setw(max_length_label) << right << "Price: ";
				in >> price;
				if (in.fail()) {
					message("Invalid Price Entry!");
				}
			}

			if (!in.fail()) {
				cout << setw(max_length_label) << right << "Quantity on hand: ";
				in >> avaliable;
				if (in.fail()) {
					message("Invalid Quantity Available Entry!");
				}
			}

			if (!in.fail()) {
				cout << setw(max_length_label) << right << "Quantity needed: ";
				in >> needed;
				if (in.fail()) {
					message("Invalid Quantity Needed Entry!");
				}
			}
		}
			if (!in.fail()) {
				Product temp(sku, name, unit, price, needed, avaliable, tax);
				*this = temp;
			}

			delete[]name;
			name = nullptr;
		
		return in;
	}

	std::ostream & Product::write(std::ostream & out, int writeMode) const {
		if(!isClear()){
			out << p_errorState.message();
		}
		else if (isEmpty()) {
		}
		else{
		
			if (writeMode == write_condensed) {
				out << p_type << "," << p_sku << "," << p_name << ","
					<< p_unit << "," << p_bTax << "," 
					<< taxable << "," << p_available << "," << p_needed;
			}

					 
			if (writeMode == write_table) {
				char newName[13 + 1];
				newName[0] = '\0';
				strncpy(newName, p_name, 13);
				newName[13] = '\0';

					out << " " << setw(max_length_sku) << right << p_sku << " | "
						<< setw(1) << left << newName << "... | "
						<< setw(10) << left << p_unit << " | "
						<< setw(7) << right << setprecision(2) << p_bTax << " | "
						<< setw(3) << right << (taxable == true ? "yes" : "no") << " | "
						<< setw(6) << right << p_available << " | "
						<< setw(6) << right << p_needed << " |";
				
			}

			if (writeMode == write_human) {
				out << setw(max_length_label) << right << "Sku: " << p_sku << endl;
				out << setw(max_length_label) << right << "Name: " << p_name << endl;
				out.precision(2);
				out << setw(max_length_label) << right << "Price: " << fixed << p_bTax << endl;
				out << setw(max_length_label) << right << "Price after Tax: " << fixed << total_cost() << endl;

				out << setw(max_length_label) << right << "Quantity Available: " << p_available << " " << p_unit << endl;
				out << setw(max_length_label) << right << "Quantity Needed: " << p_needed << " " << p_unit << endl;
			}
		}
		
		return out;
	}

}
