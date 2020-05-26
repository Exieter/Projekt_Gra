#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Zombie : public sf::Sprite
{
protected:
    int hp;
    int damage;
    std::string path_to_graphics;
    int amount_of_zombies;

public:
    virtual void spawn_zombie(int amount_of_zombies);

};

class SmallZombie : public Zombie
{
public:
    SmallZombie(int hp_, int damage_, std::string path_to_graphics_);
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

#endif // ZOMBIE_H
