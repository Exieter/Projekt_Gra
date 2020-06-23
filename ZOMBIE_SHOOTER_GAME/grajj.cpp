#include "grajj.h"

//konstruktory
Graj::Graj()
{

}

Player::Player(sf::Texture &texture_)
{
    this->texture=texture_;

    sprite.setTexture(texture);
    sprite.setScale(0.5, 0.5);
    sprite.setTextureRect(sf::IntRect(32,30,265,162));
    sprite.setPosition(320,320);
}

Zombie::Zombie()
{

}
SmallZombie::SmallZombie(sf::Texture &texture_)
{
    this->texture=texture_;

    sprite.setTexture(texture);
    sprite.setScale(0.3, 0.3);
    sprite.setTextureRect(sf::IntRect(24,70,215,207));
   // sprite.setPosition(320,320);
}

MediumZombie::MediumZombie(sf::Texture &texture_)
{

    this->texture=texture_;

    sprite.setTexture(texture);
    sprite.setScale(0.45, 0.45);
    sprite.setTextureRect(sf::IntRect(24,70,215,207));
    sprite.setPosition(100,120);
}
BigZombie::BigZombie(sf::Texture &texture_)
{
    this->texture=texture_;

    sprite.setTexture(texture);
    sprite.setScale(0.6, 0.6);
    sprite.setTextureRect(sf::IntRect(24,70,215,207));
    sprite.setPosition(200,320);
}
Otoczenie::Otoczenie(sf::Texture &texture_,sf::Texture &podloga_)
{
    podlogatexture=podloga_;
    podlogasprite.setTexture(podlogatexture);
    podlogatexture.setRepeated(true);
    podlogasprite.setScale(0.15,0.15);
    podlogasprite.setTextureRect(sf::IntRect(0,0,1100/0.15,900/0.15));
    this->texture=texture_;


sf::Sprite wall1;
    wall1.setTexture(texture);
    texture.setRepeated(true);
    wall1.setScale(0.6, 0.6);
    wall1.setTextureRect(sf::IntRect(-300/0.6,-300/0.6,50/0.6,500/0.6));
   // sprite.setPosition(200,320);
    sciany.emplace_back(wall1);

sf::Sprite wall2;
        wall2.setTexture(texture);
        texture.setRepeated(true);
        wall2.setScale(0.6, 0.6);
        wall2.setTextureRect(sf::IntRect(-300/0.6,-300/0.6,500/0.6,50/0.6));
        sciany.emplace_back(wall2);

        sf::Sprite wall3;
                wall3.setTexture(texture);
                texture.setRepeated(true);
                wall3.setScale(0.6, 0.6);
               // wall3.setPosition(1250,-300);
                wall3.setTextureRect(sf::IntRect(600/0.6,-300/0.6,800/0.6,50/0.6));
                sciany.emplace_back(wall3);
}




// funkcje
void Graj::rysuj(sf::RenderWindow &window_) const
{
    window_.draw(sprite);
}
void Otoczenie::rysuj(sf::RenderWindow &window_)
{
    window_.draw(podlogasprite);
 for(auto &el : sciany)
 {
     window_.draw(el);
 }
}






