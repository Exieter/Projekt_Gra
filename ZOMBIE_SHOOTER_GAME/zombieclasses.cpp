#include "zombieclasses.h"
//small
SmallZombie::SmallZombie(sf::Texture &texture_)
{
    this->texture=texture_;

    sprite.setTexture(texture);
    sprite.setScale(0.2, 0.2);
    sprite.setTextureRect(sf::IntRect(24,70,215,207));

}




int SmallZombie::zwrocHP() const
{
    return hpSmall;
}

void SmallZombie::odejmijHP()
{
    hpSmall=hpSmall-15;
}



//medium
MediumZombie::MediumZombie(sf::Texture &texture_)
{

    this->texture=texture_;

    sprite.setTexture(texture);
    sprite.setScale(0.35, 0.35);
    sprite.setTextureRect(sf::IntRect(24,70,215,207));

}




int MediumZombie::zwrocHP() const
{
    return hpMedium;
}

void MediumZombie::odejmijHP()
{
    hpMedium=hpMedium-15;
}


//big
BigZombie::BigZombie(sf::Texture &texture_)
{
    this->texture=texture_;

    sprite.setTexture(texture);
    sprite.setScale(0.5, 0.5);
    sprite.setTextureRect(sf::IntRect(24,70,215,207));

}

int BigZombie::zwrocHP() const
{
    return hpBig;
}

void BigZombie::odejmijHP()
{
    hpBig=hpBig-15;
}


