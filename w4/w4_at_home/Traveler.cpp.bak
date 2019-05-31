// TODO: add file header comments here
/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/

// TODO: add your headers here
#include <iostream>
#include <string.h>
#include <iomanip>
#include "Traveler.h"

using namespace std;

// TODO: continue your namespace here
namespace sict {

	// TODO: implement the default constructor here
	Traveler::Traveler() {
		t_firstName[0] = '\0';
		t_lastName[0] = '\0';
		t_destination[0] = '\0';
		t_year = 0;
		t_month = 0;
		t_day = 0;
	}

	// TODO: implement the constructor with 3 parameters here
	Traveler::Traveler(const char * t_f, const char * t_l, const char * t_d) {

		if (t_f != nullptr && t_f[0] != '\0' && t_l != nullptr && t_l[0] != '\0' && t_d != nullptr && t_d[0] != '\0') {
			strncpy(t_firstName, t_f, max_name_size);
			strncpy(t_lastName, t_l, max_name_size);
			strncpy(t_destination, t_d, max_destination_size);
			t_year = 2019;
			t_month = 7;
			t_day = 1;
		}

		else {
			*this = Traveler();
		}

	}

	Traveler::Traveler(const char * t_f, const char * t_l, const char * t_d, int year,int month, int day) {

		if (t_f != nullptr && t_f[0] != '\0' && t_l != nullptr && t_l[0] != '\0' && t_d != nullptr && t_d[0] != '\0' && (year >= 2019 && year <= 2022) && (month >= 1 && month <= 12) && (day >= 1 && day <= 31)) {
			strncpy(t_firstName, t_f, max_name_size);
			strncpy(t_lastName, t_l, max_name_size);
			strncpy(t_destination, t_d, max_destination_size);
			t_year = year;
			t_month = month;
			t_day = day;
		}

		else {
			*this = Traveler();
		}

	}

	// TODO: implement name query here
	const char* Traveler::name() const {
		if (isEmpty())
			return "";
		else
			return t_firstName;
	}

	// TODO: implement canTravelWith query here
	bool Traveler::canTravelWith(const Traveler& traveler) const {
		if (strcmp(t_destination, traveler.t_destination) == 0 && t_year == traveler.t_year && t_month == traveler.t_month && t_day == traveler.t_day) 
			return true;
										
		return false;
	}

	// TODO: implement isEmpty query here
	bool Traveler::isEmpty() const {

		if (t_firstName[0] == '\0' && t_lastName[0] == '\0' && t_destination[0] == '\0' && t_year == 0 && t_month == 0 && t_day == 0)
			return true;

		else return false;
	}

	// TODO: implement display query here
	void Traveler::display() const {
		if (isEmpty())
			cout << "--> Not a valid traveler! <--" << endl;

		else
			cout << t_lastName << ", " << t_firstName << " goes to " << t_destination << " on " << t_year << "/" << setfill('0') << setw(2) << t_month << "/" << setw(2) << t_day << endl;
	}

}
