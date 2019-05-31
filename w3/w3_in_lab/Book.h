/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/
#ifndef SICT_BOOK_H
#define SICT_BOOK_H
namespace sict {
	const int max_title_size = 32;
	const int max_name_size = 16;
	const long long min_isbn_value = 1000000000000;
	const long long max_isbn_value = 9999999999999;

	class Book {
		
		char family_name[max_name_size + 1];
		char title[max_title_size + 1];
		char given_name[max_name_size + 1];
		long long isbn;

	public:

		Book();
		void set(const char *, const char *, const char *, long long);
		bool isEmpty() const;
		void display() const;
	};


}
#endif // !SICT_BOOK_H
