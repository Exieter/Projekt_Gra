#include "graj.h"

Graj::Graj()
{

}
void Graj::rysuj(sf::RenderWindow &window_) const
{
    window_.draw(sprite);
}

sf::Sprite Graj::getSprite()
{
    return sprite;
}
