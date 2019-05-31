// OOP244 Workshop 9: Function Templates
// File: Data.cpp
// Version: 2.0.1
// Date: 2017/12/17
// Author: Chris Szalwinski, based on previous work by Hasan Murtaza
// Description:
// This file defines the answers and readRow functions
// Chris     2017.12.17 removed answers to Q1
///////////////////////////////////////////////////
//Name: Hamza Ibrahim
//Seneca email: hibrahim21@myseneca.ca
//Seneca ID: 107467185


#include <iostream>
#include <iomanip>
#include "Data.h"

using namespace std;

namespace sict {

	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		cout << "Population change from " << max(year, n) << " to " <<  min(year, n) << " is ";
		
		
		cout << setprecision(2) << fixed << static_cast<double>(population[n - 1] - population[0]) / 1000000 << " million" << endl;


		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		double startViolent = violentCrime[0];
		double nowViolent = violentCrime[n - 1];

		const char *upOrDown = startViolent > nowViolent ? "down" : "up";
		cout << "Violent Crime trend is " << upOrDown << endl;




		// Q3 print the GTA number accurate to 0 decimal places
		double gta = average(grandTheftAuto, n);
		cout.precision(2);
		cout << "There are " << fixed << (gta / 1000000) << " million Grand Theft Auto incidents on average a year" << endl;


		// Q4. Print the min and max violentCrime rates
		cout << "The Minimum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << endl;
		cout << "The Maximum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << endl;


	}
}
