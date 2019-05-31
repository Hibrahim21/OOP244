/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "Date.h"
namespace ama {

	Date::Date() {
		d_year = 0;
		d_month = 0;
		d_day = 0;
		d_status = no_error;
	};

	Date::Date(int year, int month, int day) {
		if (year >= min_year && year <= max_year) {
			if (month >= 1 && 12 >= month) {
				if (day > 0 && day <= mdays(year, month)) {
					d_year = year;
					d_month = month;
					d_day = day;
					status(no_error);
				}
				else {
					*this = Date();
					status(error_day);
				}
			}
			else {
				*this = Date();
				status(error_mon);
			}
		}
		else {
			*this = Date();
			status(error_year);
		}
	};

	int Date::mdays(int year, int mon) const
	{
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));;
	};

	void Date::status(int newStatus) {
		d_status = newStatus;
	};

	int Date::status() const {
		return this->d_status;
	}
	bool Date::isGood() {
		if (this->d_day > 0 && this->d_day <= mdays(this->d_year, this->d_month) && status() == 0) {
			return true;
		}
		else {
			return false;
		}
	};
	void Date::clearError() {
		d_status = no_error;
	};


	Date& Date::operator+=(int days) {
		if (this->d_status != 0 && this->d_year == 0) {
			this->d_status = error_invalid_operation;
		}
		else if (status() || (this->d_day + days <= 0 || this->d_day + days > mdays(this->d_year, this->d_month))) {
			this->d_status = error_invalid_operation;
		}
		else {
			this->d_day += days;
		}
		return *this;
	};

	Date& Date::operator++() {
		if (this->d_status != 0 && this->d_year == 0) {
			status(error_invalid_operation);
		}
		else if (this->d_day <= 0 || this->d_day >= mdays(this->d_year, this->d_month)) {
			status(error_invalid_operation);
		}
		else {
			this->d_day = this->d_day + 1;
		}
		return *this;
	};

	Date Date::operator++(int days) {
		Date t;
		if (this->d_status != 0 && this->d_year == 0) {
			this->status(error_invalid_operation);
		}
		else if (this->d_day <= 0 || this->d_day > mdays(this->d_year, this->d_month)) {
			this->status(error_invalid_operation);
		}
		else {
			t = *this;
			++(*this);
		}
		return t;
	};

	Date Date::operator+(int days) {
		Date t = *this;
		return t += days;
	};

	bool Date::operator==(const Date& rhs)  const {
		bool valid = d_year == rhs.d_year && d_month == rhs.d_month && d_day == rhs.d_day;
		return valid;
	};

	bool Date::operator!=(const Date& rhs) const {

		bool valid = !(d_year == rhs.d_year && d_month == rhs.d_month && d_day == rhs.d_day);
		return valid;
	};

	bool Date::operator<(const Date& rhs) const {
		bool valid = (d_year < rhs.d_year) || (d_month < rhs.d_month && d_year == rhs.d_year) || (d_day < rhs.d_day && d_month == rhs.d_month && d_year == rhs.d_year);
		return valid;
	};

	bool Date::operator>(const Date& rhs) const {
		bool valid = (d_year > rhs.d_year) || (d_month > rhs.d_month && d_year == rhs.d_year) || (d_day > rhs.d_day && d_month == rhs.d_month && d_year == rhs.d_year);
		return valid;
	};

	bool Date::operator<=(const Date& rhs) const {
		bool valid = *this < rhs || *this == rhs;
		return valid;
	};

	bool Date::operator>=(const Date& rhs) const {
		bool valid = *this > rhs || *this == rhs;
		return valid;
	};

	std::istream& Date::read(std::istream& is) {
		char sep;
		int year, month, day;
		is >> year >> sep >> month >> sep >> day;
		if (is.fail()) {
			*this = Date();
			status(error_input);
		}
		else {
			if (year >= min_year && year <= max_year) {
				if (month >= 1 && 12 >= month) {
					if (day > 0 && day <= mdays(year, month)) {
						d_year = year;
						d_month = month;
						d_day = day;
						status(no_error);
					}
					else {
						*this = Date();
						status(error_day);
					}
				}
				else {
					*this = Date();
					status(error_mon);
				}
			}
			else {
				*this = Date();
				status(error_year);
			}
		}
		return is;
	};

	std::ostream& Date::write(std::ostream& os) const {
		char sep = '/';

		os.width(4);
		os.fill('0');
		os << d_year;
		os << sep;
		if (d_month < 10) {
			os << "0";
		}
		os << d_month;
		os << sep;
		if (d_day < 10) {
			os << "0";
		}
		os << d_day;

		os.fill(' ');
		return os;
	};

	std::ostream& operator<<(std::ostream& os, const Date& d) {
		return d.write(os);
	};

	std::istream& operator>>(std::istream& is, Date& d) {
		return d.read(is);
	}
}