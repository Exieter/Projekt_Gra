#ifndef GRAJJ_H
#define GRAJJ_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
//#include <windows.h>

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
    int hpPlayer=100;

    int moveSpeed = 30000;

public:
    Player(sf::Texture &texture_);
    void poruszanie(std::vector<sf::Sprite> &sciany, sf::Time &elapsed);
    int odejmijHP();
    sf::Sprite getSpritePlayer() const;
};



class Zombie : public Graj
{
protected:
    int moveSpeedZombie=25000;

float angle_zombie_player_to_move = 0; //  do poruszania w strone gracza
float angle_zombie_player_to_face = 0; // do rotacji zombie w strone gracza

int random_position = rand()%4;

public:
    Zombie();
    void poruszanie(sf::Sprite &player_sprite,std::vector<sf::Sprite> &sciany_sprites,sf::Time &elapsed );
    void setZombiePosition();

};

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




class Otoczenie : public sf::Sprite
{
private:
    std::vector<sf::Sprite> sciany;
    sf::Texture texture; // sciana

    sf::Sprite podlogasprite;
    sf::Texture podlogatexture; // podloga

public:
    Otoczenie(sf::Texture &texture_,sf::Texture &podloga_);
    void rysuj(sf::RenderWindow &window_);
    std::vector<sf::Sprite> getScianyVectorSprite() const;
};


#endif // GRAJJ_H
