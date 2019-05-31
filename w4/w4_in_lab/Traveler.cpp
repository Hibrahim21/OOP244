// TODO: add file header comments here
/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/

// TODO: add your headers here
#include <iostream>
#include <string.h>
#include "Traveler.h"

using namespace std;

// TODO: continue your namespace here
namespace sict {

	// TODO: implement the default constructor here
	Traveler::Traveler() {
		t_firstName[0] = '\0';
		t_lastName[0] = '\0';
		t_destination[0] = '\0';
	}

	// TODO: implement the constructor with 3 parameters here
	Traveler::Traveler(const char * t_f, const char * t_l, const char * t_d) {
		
		if (t_f != nullptr && t_f[0] != '\0' && t_l != nullptr && t_l[0] != '\0' && t_d != nullptr && t_d[0] != '\0') {
			strncpy(t_firstName, t_f, max_name_size);
			strncpy(t_lastName, t_l, max_name_size);
			strncpy(t_destination, t_d, max_destination_size);
		}

		else {
			t_firstName[0] = '\0';
			t_lastName[0] = '\0';
			t_destination[0] = '\0';
		}

	}

	// TODO: implement isEmpty query here
	bool Traveler::isEmpty() const {

		if (t_firstName[0] == '\0')
			return true;

		else return false;
	}

	// TODO: implement display query here
	void Traveler::display() const {
		if (t_firstName[0] == '\0')
			cout << "--> Not a valid traveler! <--" << endl;

		else
			cout << t_firstName << " " << t_lastName << " goes to " << t_destination << endl;
	}

}