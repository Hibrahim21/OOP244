/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/

#ifndef AMA_UTILIITES_H
#define AMA_UTILIITES_H
#include "Product.h"
#include <iostream>

using namespace std;

namespace ama {

	iProduct* createInstance(char tag);
	double& operator+=(double &total, const iProduct& prod);
	ostream& operator<<(ostream& out, const iProduct& prod);
	istream& operator>>(istream& in, iProduct& prod);
}

#endif // !AMA_UTILIITES_H
