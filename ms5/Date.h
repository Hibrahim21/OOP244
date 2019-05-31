/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/
#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>

namespace ama {
	const int min_year = 2019;
	const int max_year = 2028;
	const int no_error = 0;
	const int error_year = 1;
	const int error_mon = 2;
	const int error_day = 3;
	const int error_invalid_operation = 4;
	const int error_input = 5;

	class Date {
		int d_year;
		int d_month;
		int d_day;
		int d_status;
		void status(int);
		int mdays(int, int) const;

	public:
		Date();
		Date(const int, const int, const int);
		int status() const;
		void clearError();
		bool isGood();

		Date& operator+=(int);
		Date& operator++();
		Date operator++(int);
		Date operator+(int);
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;


		std::istream& read(std::istream& is);
		std::ostream& write(std::ostream& os) const;

	};

	std::ostream& operator<<(std::ostream& os, const Date& d);
	std::istream& operator>>(std::istream& is, Date& d);
}
#endif // !DATE_H
