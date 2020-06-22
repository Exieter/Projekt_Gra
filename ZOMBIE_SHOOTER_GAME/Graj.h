#ifndef GRAJ_H
#define GRAJ_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Graj : public sf::Sprite
{
public:
  Graj();
};

class Player : public Graj
{
public:
    Player(sf::Texture &texture);
};

class Zombie : public Graj
{
protected:
    int hp;
    int damage;
    std::string path_to_graphics;
    int amount_of_zombies;

public:
    virtual void spawn_zombie(int amount_of_zombies);
    void move_zombie(const sf::Time &elapsed);

};

class SmallZombie : public Zombie
{
public:
    SmallZombie(int hp_, int damage_, std::string path_to_graphics_);//w nim poruszanie sie
    void spawn_zombie(int amount_of_zombies);
};

class MediumZombie : public Zombie
{
public:
    MediumZombie(int hp_, int damage_, std::string path_to_graphics_);
    void spawn_zombie(int amount_of_zombies);
};

class BigZombie : public Zombie
{
public:
    BigZombie(int hp_, int damage_, std::string path_to_graphics_);
    void spawn_zombie(int amount_of_zombies);
};


#endif // GRAJ_H

