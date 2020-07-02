#ifndef GRAJ_H
#define GRAJ_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <windows.h>


class Graj : public sf::Sprite
{
protected:
    sf::Texture texture;
    sf::Sprite sprite;
public:
  Graj();
  void rysuj(sf::RenderWindow &window_) const;
  sf::Sprite getSprite();

};

#endif // GRAJ_H
