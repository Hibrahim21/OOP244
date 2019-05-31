// OOP244 Workshop 9: Function Templates
// File: Data.h
// Version: 2.0
// Date: 2017/12/15
// Author: Chris Szalwinski, based on previous work by Hasan Murtaza
// Description:
// This file defines the templated functions and the answers prototype
///////////////////////////////////////////////////
//Name: Hamza Ibrahim
//Seneca email: hibrahim21@myseneca.ca
//Seneca ID: 107467185
#ifndef SICT_DATA_H
#define SICT_DATA_H
#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
using namespace std;

namespace sict {
	// These number defines the output column width for a single data field

	const int COLUMN_WIDTH = 15;
	template <typename T>
	// max returns the largest item in data
	//
	T max(const T* data, int n) {
		T maximum = data[0];

		for (int i = 1; i < n; i++) {
			if (maximum > data[i]) {
				maximum = data[i];
			}
		}
		return maximum;
	}

	// min returns the smallest item in data
	//
	template <typename T>
	T min(const T *data, int n) {
		T minimum = data[0];

		for (int i = 1; i < n; i++) {
			if (minimum < data[i]) {
				minimum = data[i];
			}
		}
		return minimum;
	}

	// sum returns the sum of n items in data
	//  
	template <typename T>
	T sum(const T *data, int n) {
		T sum = 0;
		for (int i = 0; i < n; i++) {
			sum += data[i];
		}
		return sum;
	}

	// average returns the average of n items in data
	//
	template <typename T>
	double average(const T *data, int n) {
		T average = sum(data, n) / n;
		return average;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//
	template <typename T>
	bool read(istream& input, T *data, int n) {
		for (int i = 0; i < n; i++) {
			input.ignore();
			input >> data[i];
			if (input.fail()) {
				return false;
			}
		}
		return true;

	}

	// display inserts n items of data into std::cout
	//
	template <typename T>
	void display(const char *name, const T *data, int n) {
		cout.width(20);
		cout << right << name;
		for (int i = 0; i < n; i++) {
			cout.width(15);
			cout << data[i];
		}
		cout << "\n";
	}

	template <typename T>
	T readRow(istream& input, const char* name, T *data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (strcmp(rowname, name) != 0) {
				// wrong row
				cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}


#endif // !SICT_DATA_H


