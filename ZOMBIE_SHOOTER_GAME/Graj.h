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

    void animate( const int &moveSpeedX_, const int &moveSpeedY_);
    virtual sf::Vector2i getSpeedXY()=0;
    virtual int zwrocHP() const=0;
    virtual void odejmijHP()=0;


};

#endif // GRAJ_H
