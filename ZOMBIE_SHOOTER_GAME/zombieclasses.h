#ifndef ZOMBIECLASSES_H
#define ZOMBIECLASSES_H


#include <zombie.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class SmallZombie : public Zombie
{
private:
    int hpSmall = 20;
    int damageSmall = 5;
int moveSpeedZombie=200000;
public:
    SmallZombie(sf::Texture &texture_);
    void odejmijHPZombie();
    int zwrocHPZombie();
};

class MediumZombie : public Zombie
{
private:
    int hpMedium = 50;
    int damageMedium = 10;

public:
    MediumZombie(sf::Texture &texture_);
    void odejmijHPZombie();
    int zwrocHPZombie();
};

class BigZombie : public Zombie
{
private:
    int hpBig = 100;
    int damageBig = 30;

public:
    BigZombie(sf::Texture &texture_);
    void odejmijHPZombie();
    int zwrocHPZombie();
};

#endif // ZOMBIECLASSES_H
