#ifndef GRAJJ_H
#define GRAJJ_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

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
  void rysuj(sf::RenderWindow &window_) const;
};

class Player : public Graj
{
private:
    int hpPlayer;

    int moveSpeed = 50000;

public:
    Player(sf::Texture &texture_);
    void poruszanie(sf::Event &event,sf::Time &elapsed);
    int odejmijHP();
};



class Zombie : public Graj
{
protected:


public:
    Zombie();
    void poruszanie();

};

class SmallZombie : public Zombie
{
    int hp = 20;
    int damage = 5;
public:
    SmallZombie(sf::Texture &texture_);//w nim poruszanie sie
};

class MediumZombie : public Zombie
{
    int hp = 50;
    int damage = 10;
public:
    MediumZombie(sf::Texture &texture_);
};

class BigZombie : public Zombie
{
    int hp = 100;
    int damage = 30;
public:
    BigZombie(sf::Texture &texture_);
};




class Otoczenie : public sf::Sprite
{
    std::vector<sf::Sprite> sciany;
    sf::Sprite podlogasprite;
    sf::Texture podlogatexture;
    sf::Texture texture;
public:
    Otoczenie(sf::Texture &texture_,sf::Texture &podloga_);
    void rysuj(sf::RenderWindow &window_);
};


#endif // GRAJJ_H
