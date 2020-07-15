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

sf::Sprite Graj::getSprite()
{
    return sprite;
}

void Graj::odejmijHP(const int &ilosc_do_odjecia)
{
   this->HP=this->HP-ilosc_do_odjecia;
    std::cout<<this->HP<<std::endl;
}
