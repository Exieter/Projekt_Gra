#include "bullet.h"

Bullet::Bullet(sf::Texture &texture_, Player &player)
{
    this->texture=texture_;

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,220,590));
    sprite.setOrigin((sprite.getGlobalBounds().left+sprite.getGlobalBounds().width)/2,(sprite.getGlobalBounds().top+sprite.getGlobalBounds().height)/2);
    sprite.rotate(90);
    sprite.setScale(0.02, 0.02);

     rotation_angle =this->setreturnBulletPosition(player);

}

void Bullet::bulletShooted(sf::Time &elapsed)
{


    switch(rotation_angle)
    {
    case 0:
        sprite.move(bullet_speed *elapsed.asSeconds(),0);
        break;
    case 45:
        sprite.move(bullet_speed*elapsed.asSeconds(),bullet_speed*elapsed.asSeconds());
        break;
    case 90:
        sprite.move(0,bullet_speed*elapsed.asSeconds());
        break;
    case 135:
        sprite.move(-bullet_speed*elapsed.asSeconds(),bullet_speed*elapsed.asSeconds());
        break;
    case 180:
        sprite.move(-bullet_speed *elapsed.asSeconds(),0);
        break;
    case 225:
        sprite.move(-bullet_speed*elapsed.asSeconds(),-bullet_speed*elapsed.asSeconds());
        break;
    case 270:
        sprite.move(0,-bullet_speed*elapsed.asSeconds());
        break;
    case 315:
        sprite.move(bullet_speed*elapsed.asSeconds(),-bullet_speed*elapsed.asSeconds());
        break;
    }

}



float Bullet::setreturnBulletPosition(Player &player)
{
    sprite.setPosition(player.getSpritePlayer().getPosition());
    sprite.setRotation(player.getSpritePlayer().getRotation()+90);
    return player.getSpritePlayer().getRotation();

}
