#ifndef PLAYER_H
#define PLAYER_H

#include <graj.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Player : public Graj
{
private:
    int hpPlayer=200;

    int moveSpeedX=0;
    int moveSpeedY=0;

public:
    Player(sf::Texture &texture_);
    void poruszanie(sf::Time &elapsed);
    sf::Sprite getSpritePlayer() const;

    sf::Vector2i getSpeedXY();
    int zwrocHP() const;
    void odejmijHP();


};

#endif // PLAYER_H
