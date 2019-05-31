// TODO: add file header comments here
/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/

// TODO: add header file guard here
#ifndef SICT_TRAVELER_H
#define SICT_TRAVELER_H

// TODO: declare your namespace here
namespace sict {

	// TODO: define the constants here
	const int max_destination_size = 32;
	const int max_name_size = 16;

	// TODO: define the Traveler class here
	class Traveler {
		char t_firstName[max_name_size];
		char t_lastName[max_name_size];
		char t_destination[max_destination_size];
		int t_year;
		int t_month;
		int t_day;

	public:
		Traveler();
		Traveler(const char *, const char *, const char *);
		Traveler(const char *, const char *, const char *, int, int, int);

		const char* name() const;
		bool canTravelWith(const Traveler&) const;
		bool isEmpty() const;
		void display() const;
	};

}
#endif // !SICT_TRAVELER_H
