#include "grajj.h"

//konsturktury
Graj::Graj()
{

}

Player::Player(sf::Texture &texture_)
{
    this->texture=texture_;

    sprite.setTexture(texture);
    texture.setRepeated(true);
    sprite.setScale(0.3, 0.3);
    //sprite.setTextureRect(sf::IntRect(0, 0, window.getSize().x/0.3, window.getSize().y/0.3));
}

// funckje
void Player::rysuj(sf::RenderWindow &window_) const
{
    window_.draw(sprite);
}
