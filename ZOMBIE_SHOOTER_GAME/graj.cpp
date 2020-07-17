#include "graj.h"

Graj::Graj()
{

}
void Graj::rysuj(sf::RenderWindow &window_) const
{
    window_.draw(sprite);
}
void Graj::animate(const int &moveSpeedX_, const int &moveSpeedY_)
{
    sprite.move(moveSpeedX_,moveSpeedY_);


}

int Graj::zwrocHP() const
{
    return HP;
}

void Graj::odejmijHP(const int &ilosc_do_odjecia)
{
    HP=HP - ilosc_do_odjecia;
}

sf::Sprite Graj::getSprite()
{
    return sprite;
}

