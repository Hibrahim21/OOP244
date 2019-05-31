/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/

#include <iostream>
#include <iomanip>
#include "Perishable.h"

using namespace std;

namespace ama {
	Perishable::Perishable(char type) : Product(type) {
		m_Expdate.clearError(); //
	}
	ostream & Perishable::write(ostream & out, int writeMode) const {

		Product::write(out, writeMode);
		//m_Expdate.status() == 0 && isEmpty() == false
		if (isClear() && !isEmpty()) { //

			if (writeMode == write_human) {
				out << setw(max_length_label) << right << "Expiry Date: ";
				m_Expdate.write(cout);
				out << endl;
			}
			if (writeMode == write_table) {
				out << " ";
				m_Expdate.write(cout); //
				out << " |";
			}
			if (writeMode == write_condensed) {
				out << "," << m_Expdate;
			}
		}
		return out;
	}

	istream & Perishable::read(istream & in, bool interractive) {

		Product::read(in, interractive);
		if (interractive == true) {
			if (m_Expdate.status() == no_error) {

				cout << setw(max_length_label) << right << "Expiry date (YYYY/MM/DD): ";
				m_Expdate.read(in);

				if (m_Expdate.status() == error_year) {
					Product::message("Invalid Year in Date Entry");
					in.setstate(ios::failbit);
				}
				else if (m_Expdate.status() == error_mon) {
					Product::message("Invalid Month in Date Entry");
					in.setstate(ios::failbit);
				}
				else if (m_Expdate.status() == error_day) {
					Product::message("Invalid Day in Date Entry");
					in.setstate(ios::failbit);
				}
				else if (m_Expdate.status() == error_input) {
					Product::message("Invalid Date Entry");
					in.setstate(ios::failbit);
				}
			}

			//if (interractive == false) {
				//in.ignore();
				//m_Expdate.read(in); //
				//in.ignore(2000, '\n');
			//}
		}
		if (interractive == false) {
			in.ignore();
			m_Expdate.read(in); //
			//in.ignore(2000, '\n');
		}
		return in;
	}
}

