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
  //void rysuj(sf::RenderWindow &window_) const;
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


public:
    Zombie(sf::Texture &texture_);
    void rysuj();
    void poruszanie();

};

class SmallZombie : public Zombie
{
    int hp = 20;
    int damage = 5;
public:
    SmallZombie(int hp_, int damage_, std::string path_to_graphics_);//w nim poruszanie sie
    void spawn_zombie(int amount_of_zombies);
};

class MediumZombie : public Zombie
{
    int hp = 50;
    int damage = 10;
public:
    MediumZombie(int hp_, int damage_, std::string path_to_graphics_);
    void spawn_zombie(int amount_of_zombies);
};

class BigZombie : public Zombie
{
    int hp = 100;
    int damage = 30;
public:
    BigZombie(int hp_, int damage_, std::string path_to_graphics_);
    void spawn_zombie(int amount_of_zombies);
};
class Sciana : public Graj
{
public:
    Sciana(sf::Texture &texture_);
    void rysuj();
};


#endif // GRAJJ_H
