/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/

#ifndef SICT_HERO_H
#define SICT_HERO_H

namespace sict {
    const int max_rounds = 10;

    class Hero {
        char h_name[41];
        int h_health;
        int h_attack;

    public:
        Hero();
        Hero(const char*, const int, const int);

        void operator-=(int);
        bool isAlive() const;
        int attackStrength() const;
        friend std::ostream& operator<<(std::ostream&, const Hero&);
        friend const Hero& operator*(const Hero&, const Hero&);
    };
}
#endif // !SICT_HERO_H