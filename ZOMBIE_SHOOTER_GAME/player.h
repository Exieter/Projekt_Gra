#ifndef PLAYER_H
#define PLAYER_H

#include <graj.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Player : public Graj
{
private:
    int hpPlayer=200;

    int HP=100;

    int moveSpeedX=0;
    int moveSpeedY=0;

public:
    Player(sf::Texture &texture_);
    void poruszanie(sf::Time &elapsed);
    sf::Sprite getSpritePlayer() const;
    void odejmijHPPlayer(const int &liczba_do_odjecia);
    int zwrocHPPlayer() const;
    sf::Vector2i getSpeedXY();


};

#endif // PLAYER_H
