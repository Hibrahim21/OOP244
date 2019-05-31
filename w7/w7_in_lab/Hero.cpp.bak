/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/

#include <iostream>
#include <cstring>
#include "Hero.h"

using namespace std;

namespace sict {
    Hero::Hero(){
	h_name[0] = '\0';
	h_health = 0;
	h_attack = 0;
    }

    Hero::Hero(const char *name, int health, int attack){
	if (name[0] != '\0' && name != nullptr && health > 0 && attack > 0) {
	    strcpy(h_name, name);
	    h_health = health;
	    h_attack = attack;
	}
	else{
	    *this = Hero();
	}
    }

    void Hero::operator-=(int attack){
	if (attack > 0) {
	    this->h_health -= attack;

	    if (this->h_health < 0) {
		h_health = 0;
	    }
	}
    }

    bool Hero::isAlive() const{
	if (h_health > 0) {
	    return true;
	}
	else return false;
    }

    int Hero::attackStrength() const{
	if (h_name[0] == '\0') {
	    return 0;
	}
	else return h_attack;
    }

    std::ostream& operator<<(std::ostream& os, const Hero& hero){
	if (hero.h_name[0] != '\n' && hero.h_health >0 && hero.h_attack > 0) {
	    os << hero.h_name;
	}
	else {
	    os << "No hero";
	}
	return os;
    }

    const Hero& operator*(const Hero& first, const Hero& second){
	int roundNum = 0;
	Hero leftHero = first, rightHero = second, victor;

	for (int i = 0; i < max_rounds && (leftHero.isAlive() && rightHero.isAlive()); ++i){
	    leftHero -= rightHero.attackStrength();
	    rightHero -= leftHero.attackStrength();
	    roundNum = i;
	}
	roundNum++;

	if ((leftHero .isAlive() != true) && (rightHero.isAlive() != true)){
	    victor = leftHero;
	    cout << "Ancient Battle! " << leftHero.h_name << " vs " << rightHero.h_name << " : Winner is " << leftHero .h_name << " in "<< roundNum <<" rounds."<< endl;
	    return first;
	}
	else if (leftHero.isAlive() != true){
	    victor = rightHero;
	    cout << "Ancient Battle! " << leftHero.h_name << " vs " << rightHero.h_name << " : Winner is " << rightHero.h_name << " in " << roundNum << " rounds." << endl;
	    return second;
	}
	else if (rightHero.isAlive() != true){
	    victor = leftHero;
	    cout << "Ancient Battle! " << leftHero.h_name << " vs " << rightHero.h_name << " : Winner is " << leftHero.h_name << " in " << roundNum << " rounds." << endl;
	    return first;
	}
	else{
	    return first;
	}
    }
}
