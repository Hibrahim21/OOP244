/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/

// TODO: insert header files
#include <iostream>
#include "Fraction.h"
using namespace std;

// TODO: continue the namespace
namespace sict {

	// TODO: implement the default constructor
	Fraction::Fraction() {
		f_numerator = 0;
		f_denominator = 0;
	}

	// TODO: implement the two-argument constructor
	Fraction::Fraction(int x, int y) {
		if (x >= 0)
			f_numerator = x;
		else 
		{
			y = 0;
			f_numerator = 0;
		}

		if (y >= 0)
			f_denominator = y;
		else
		{
			f_numerator = 0;
			f_denominator = 0;
		}
		reduce();

	}

	// TODO: implement the max query
	int Fraction::max() const {
		if (f_numerator > f_denominator)
			return f_numerator;
		else
			return f_denominator;
	}

	// TODO: implement the min query
	int Fraction::min() const {
		if (f_numerator < f_denominator)
			return f_numerator;
		else
			return f_denominator;
	}

	// gcd returns the greatest common divisor of num and denom
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce() {
		int common = gcd();
		f_numerator = (f_numerator / common);
		f_denominator = (f_denominator / common);
	}

	// TODO: implement the display query
	void Fraction::display() const {
		if (isEmpty() == false && f_denominator != 1)
		{
			cout << f_numerator << "/" << f_denominator;
		}
		else if (f_denominator == 1)
		{
			cout << f_numerator;
		}
		else
		{
			cout << "no fraction stored";
		}
	}

	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		if (f_numerator == 0 && f_denominator == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const {
		if (this->isEmpty() != true && rhs.isEmpty() != true)
		{
		
			int num = this->f_numerator;
			int den = this->f_denominator;
			int rnum = rhs.f_numerator;
			int rden = rhs.f_denominator;
			int a = (num * rden);
			int b = (den * rnum);
			int c = (den * rden);
			int d = (a + b);
			return Fraction(d, c);
		}
		else
		{
			return Fraction();
		}
	}
}
