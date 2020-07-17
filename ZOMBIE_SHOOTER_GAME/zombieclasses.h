#ifndef ZOMBIECLASSES_H
#define ZOMBIECLASSES_H


#include <zombie.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class SmallZombie : public Zombie
{

public:
    SmallZombie(sf::Texture &texture_);
;


};

class MediumZombie : public Zombie
{


public:
    MediumZombie(sf::Texture &texture_);



};

class BigZombie : public Zombie
{


public:
    BigZombie(sf::Texture &texture_);



};

#endif // ZOMBIECLASSES_H
