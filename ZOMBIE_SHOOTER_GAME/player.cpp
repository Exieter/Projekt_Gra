#include "player.h"



Player::Player(sf::Texture &texture_)
{
    this->texture=texture_;

    sprite.setTexture(texture);
    sprite.setScale(0.3, 0.3);
    sprite.setTextureRect(sf::IntRect(32,30,265,265));//162
    sprite.setPosition(320,320);
}
void Player::poruszanie(sf::Time &elapsed)
{
    sprite.setOrigin( (sprite.getLocalBounds().height / 2)-11 , (sprite.getLocalBounds().width / 2) - 10); // potrzebne do rotacji tesktury

    moveSpeedX=0;
    moveSpeedY=0;
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) ||(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            sprite.setRotation(-45);
           moveSpeedX=6000000;
           moveSpeedY=-6000000;
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            sprite.setRotation(405);
           moveSpeedX=6000000;
           moveSpeedY=6000000;
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            sprite.setRotation(-135);
            moveSpeedX=-6000000;
            moveSpeedY=-6000000;

        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            sprite.setRotation(135);
            moveSpeedX=-6000000;
            moveSpeedY=6000000;
        }
    } else
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
             sprite.setRotation(270);
            moveSpeedX=0;
            moveSpeedY=-6000000;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            sprite.setRotation(-270);
            moveSpeedX=0;
            moveSpeedY=6000000;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            sprite.setRotation(180);
            moveSpeedX=-6000000;
            moveSpeedY=0;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            sprite.setRotation(0);
            moveSpeedX=6000000;
            moveSpeedY=0;
        }
    }

    animate(moveSpeedX*elapsed.asSeconds(),moveSpeedY*elapsed.asSeconds()); // poruszanie

}

sf::Sprite Player::getSpritePlayer() const
{
    return sprite;
}

sf::Vector2i Player::getSpeedXY()
{
    return sf::Vector2i(moveSpeedX,moveSpeedY);
}

int Player::zwrocHP() const
{
    return hpPlayer;
}

void Player::odejmijHP()
{
    hpPlayer=hpPlayer-2;
}



