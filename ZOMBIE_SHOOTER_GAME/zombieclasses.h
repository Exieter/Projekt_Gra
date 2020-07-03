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
    void odejmijHPZombie();
    int zwrocHPZombie() const;
};

class MediumZombie : public Zombie
{
private:
    int hpMedium = 30;

public:
    MediumZombie(sf::Texture &texture_);
    void odejmijHPZombie();
    int zwrocHPZombie() const;
};

class BigZombie : public Zombie
{
private:
    int hpBig = 45;

public:
    BigZombie(sf::Texture &texture_);
    void odejmijHPZombie();
    int zwrocHPZombie() const;
};

#endif // ZOMBIECLASSES_H
