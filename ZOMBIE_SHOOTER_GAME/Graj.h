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
private:
    int HP=0;
protected:
    sf::Texture texture;
    sf::Sprite sprite;

public:
  Graj();
  void rysuj(sf::RenderWindow &window_) const;
  sf::Sprite getSprite();

    void animate( const int &moveSpeedX_, const int &moveSpeedY_);
    virtual sf::Vector2i getSpeedXY()=0;
    int zwrocHP() const;
    void odejmijHP(const int &ilosc_do_odjecia);


};

#endif // GRAJ_H
