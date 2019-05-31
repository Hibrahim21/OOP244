/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/
#include "Utilities.h"
#include <iostream>

using namespace std;

namespace ama {

	double & operator+=(double& total, const Product & prod) {
		double b = static_cast<double>(prod.qtyAvailable());
		total += (b * prod.total_cost());
		return total;
	}

	ostream & operator<<(ostream & out, const Product & prod) {
		return prod.write(out, write_human);
	}
	
	istream & operator>>(istream & in, Product & prod) {
		return prod.read(in, true);
	}
	
}
