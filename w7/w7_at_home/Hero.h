/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/

#ifndef SICT_HERO_H
#define SICT_HERO_H
#include <iostream>

namespace sict {
	const int max_rounds = 10;

	class Hero {
	protected:
		char h_name[41];
		int h_health;
		int h_attack;

	public:
		Hero();
		Hero(const char*, int, int);

		void operator-=(int);
		bool isAlive() const;
		virtual int attackStrength() const;
		friend std::ostream& operator<<(std::ostream&, const Hero&);
	};

	const Hero& operator*(const Hero&, const Hero&);
}

#endif // !SICT_HERO_H
