/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/

#ifndef AMA_UTILIITES_H
#define AMA_UTILIITES_H
#include "Product.h"
#include <iostream>

namespace ama {

	double& operator+=(double& total, const Product& prod);
	std::ostream& operator<<(std::ostream& out, const Product& prod);
	std::istream& operator>>(std::istream& in, Product& prod);

}

#endif // !AMA_UTILIITES_H
