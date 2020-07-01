#ifndef ZOMBIECLASSES_H
#define ZOMBIECLASSES_H

#include <graj.h>
#include <zombie.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <windows.h>




class SmallZombie : public Zombie
{
private:
    int hp = 20;
    int damage = 5;
int moveSpeedZombie=200000;
public:
    SmallZombie(sf::Texture &texture_);
};

class MediumZombie : public Zombie
{
private:
    int hp = 50;
    int damage = 10;

public:
    MediumZombie(sf::Texture &texture_);
};

class BigZombie : public Zombie
{
private:
    int hp = 100;
    int damage = 30;

public:
    BigZombie(sf::Texture &texture_);
};

#endif // ZOMBIECLASSES_H
