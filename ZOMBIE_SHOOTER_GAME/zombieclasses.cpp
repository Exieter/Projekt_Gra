#include "zombieclasses.h"


//small
SmallZombie::SmallZombie(sf::Texture &texture_)
{
    this->texture=texture_;

    sprite.setTexture(texture);
    sprite.setScale(0.2, 0.2);
    sprite.setTextureRect(sf::IntRect(24,70,215,207));

}


//medium
MediumZombie::MediumZombie(sf::Texture &texture_)
{

    this->texture=texture_;

    sprite.setTexture(texture);
    sprite.setScale(0.35, 0.35);
    sprite.setTextureRect(sf::IntRect(24,70,215,207));

}


//big
BigZombie::BigZombie(sf::Texture &texture_)
{
    this->texture=texture_;

    sprite.setTexture(texture);
    sprite.setScale(0.5, 0.5);
    sprite.setTextureRect(sf::IntRect(24,70,215,207));

}




