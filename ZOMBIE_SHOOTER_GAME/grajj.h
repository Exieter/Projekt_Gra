#ifndef GRAJJ_H
#define GRAJJ_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Graj : public sf::Sprite
{
protected:
    sf::Texture texture;
    sf::Sprite sprite;
public:
  Graj();
  void wynik();
  bool czyPrzegrana();
  //virtual void poruszanie();
};

class Player : public Graj
{
private:
    int hpPlayer;

public:
    Player(sf::Texture &texture_);
    void rysuj(sf::RenderWindow &window_) const;
    void poruszanie();
    int odejmijHP();
};



class Zombie : public Graj
{
protected:
    int hp;
    int damage;

public:
    Zombie(sf::Texture &texture_);
   // virtual void rysuj(sf::RenderWindow &window_) const;
    void poruszanie();

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
class Sciana : public Graj
{
public:

};


#endif // GRAJJ_H
