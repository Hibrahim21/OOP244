/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/

#include <iostream>
#include <cstring>
#include "SuperHero.h"

using namespace std;

namespace sict {

	SuperHero::SuperHero() : Hero() {
		s_bonus = 0;
		s_defence = 0;
	}

	SuperHero::SuperHero(const char *S_name, int S_health, int S_attack, int S_bonus, int S_defence) : Hero(S_name, S_health, S_attack) {
		s_bonus = S_bonus;
		s_defence = S_defence;
	}

	int SuperHero::attackStrength() const {
		if (Hero::attackStrength() != 0) {
			return  Hero::attackStrength() + s_bonus;
		}
		else {
			return 0;;
		}
	}

	int SuperHero::defend() const {
		if (s_defence != 0) {
			return s_defence;
		}
		else {
			return 0;
		}
	}

	const SuperHero & operator*(const SuperHero & first, const SuperHero & second) {
		int roundNum = 0;
		SuperHero leftHero = first, rightHero = second, victor;

		for (int i = 0; i < max_rounds && (leftHero.isAlive() && rightHero.isAlive()); ++i) {
			leftHero -= rightHero.attackStrength() - leftHero.defend();
			rightHero -= leftHero.attackStrength() - rightHero.defend();
			roundNum = i;
		}
		roundNum++;

		if ((leftHero.isAlive() != true) && (rightHero.isAlive() != true)) {
			victor = leftHero;
			cout << "Super Fight! " << leftHero << " vs " << rightHero << " : Winner is " << leftHero << " in " << roundNum << " rounds." << endl;
			return first;
		}
		else if (leftHero.isAlive() != true) {
			victor = rightHero;
			cout << "Super Fight! " << leftHero << " vs " << rightHero << " : Winner is " << rightHero << " in " << roundNum << " rounds." << endl;
			return second;
		}
		else if (rightHero.isAlive() != true) {
			victor = leftHero;
			cout << "Super Fight! " << leftHero << " vs " << rightHero << " : Winner is " << leftHero << " in " << roundNum << " rounds." << endl;
			return first;
		}
		else {
			return first;
		}
	}
}
