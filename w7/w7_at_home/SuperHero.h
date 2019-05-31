/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/

#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include <iostream>
#include "Hero.h"
namespace sict {

	class SuperHero : public Hero {
	protected:
		int s_bonus;
		int s_defence;
	public:
		SuperHero();
		SuperHero(const char*, int, int, int, int);

		int attackStrength() const;
		int defend() const;
	};

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif // !SICT_SUPERHERO_H