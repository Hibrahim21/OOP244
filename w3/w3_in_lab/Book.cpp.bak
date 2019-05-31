/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/
#include <iostream>
#include <cstring>
#include "Book.h"

using namespace std;

namespace sict {

	Book::Book() {

		family_name[0] = '\0';
		title[0] = '\0';
		given_name[0] = '\0';
		isbn = 0;
	}

	void Book::set(const char * g, const char *f, const char * t, long long Isbn) {
		bool valid = false;

		if (Isbn >= min_isbn_value && Isbn <= max_isbn_value)
			valid = true;

		

			if (valid) {
				isbn = Isbn;
				strncpy(given_name, g, max_name_size);
				strncpy(family_name, f, max_name_size);
				strncpy(title, t, max_title_size);
			}
			
			else {
				isbn = 0;
				given_name[0] = '\0';
				family_name[0] = '\0';
				title[0] = '\0';

			}
		
	}

	bool Book::isEmpty() const {

		if (isbn == 0)
			return true;

		else return false;
	}

	void Book::display() const {

		if (isbn != 0) {
			cout << "Author: " << family_name << ", " << given_name << endl;
			cout << "Title: " << title << endl;
			cout << "ISBN-13: " << isbn << endl;
		}
		else
		{
			cout << "The book object is empty!" << endl;

		}
		
	}
}
