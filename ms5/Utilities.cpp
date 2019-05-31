/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/
#include "Utilities.h"
#include "iProduct.h"
#include "Perishable.h"
#include <iostream>

using namespace std;

namespace ama {

	iProduct * createInstance(char tag) {
		if (tag == 'n' || tag == 'N') {
			return new Product();
		}

		else if (tag == 'p' || tag == 'P') {
			return new Perishable();
		}
		else return nullptr;
	}

	double& operator+=(double &total, const iProduct& prod) {

		double b = static_cast<double>(prod.qtyAvailable());
		total += (b * prod.total_cost());
		return total;
	}

	ostream& operator<<(ostream& out, const iProduct& prod) {
		return prod.write(out, write_human);
	}

	istream& operator>>(istream& in, iProduct& prod) {
		return prod.read(in, true);
	}

}
