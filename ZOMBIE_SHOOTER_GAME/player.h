#ifndef PLAYER_H
#define PLAYER_H

#include <graj.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <windows.h>
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

#endif // PLAYER_H
