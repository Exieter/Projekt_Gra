#ifndef ZOMBIECLASSES_H
#define ZOMBIECLASSES_H


#include <zombie.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class SmallZombie : public Zombie
{
private:
    int hpSmall = 15;

public:
    SmallZombie(sf::Texture &texture_);
;
    int zwrocHP() const;
    void odejmijHP();

};

class MediumZombie : public Zombie
{
private:
    int hpMedium = 30;

public:
    MediumZombie(sf::Texture &texture_);

    int zwrocHP() const;
    void odejmijHP();

};

class BigZombie : public Zombie
{
private:
    int hpBig = 45;

public:
    BigZombie(sf::Texture &texture_);

    int zwrocHP() const;
    void odejmijHP();

};

#endif // ZOMBIECLASSES_H
