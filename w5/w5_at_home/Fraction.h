/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/

// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

// TODO: create namespace
namespace sict {

	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		int f_denominator;
		int f_numerator;
		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int, int);
		bool isEmpty() const;
		void display() const;
		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& rhs) const;
		Fraction operator* (const Fraction & rhs) const;
		bool operator== (const Fraction & rhs) const;
		bool operator!= (const Fraction & rhs) const;
		Fraction& operator+= (const Fraction & rhs);
	};
}
#endif 
