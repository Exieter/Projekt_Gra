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
        moveSpeedBulletX=10000000;
        moveSpeedBulletY=0;
        break;
    case 45:
        moveSpeedBulletX=10000000;
        moveSpeedBulletY=10000000;
        break;
    case 90:
        moveSpeedBulletX=0;
        moveSpeedBulletY=10000000;
        break;
    case 135:
        moveSpeedBulletX=-10000000;
        moveSpeedBulletY=10000000;
        break;
    case 180:
        moveSpeedBulletX=-10000000;
        moveSpeedBulletY=0;
        break;
    case 225:
        moveSpeedBulletX=-10000000;
        moveSpeedBulletY=-10000000;
        break;
    case 270:
        moveSpeedBulletX=0;
        moveSpeedBulletY=-10000000;
        break;
    case 315:
        moveSpeedBulletX=10000000;
        moveSpeedBulletY=-10000000;
        break;
    }
    animate(moveSpeedBulletX*elapsed.asSeconds(),moveSpeedBulletY*elapsed.asSeconds());

}

sf::Sprite Bullet::getBulletSprite()
{
    return sprite;
}

bool Bullet::bulletPozaMapa(sf::Sprite &bulletSprite)
{
    if(bulletSprite.getGlobalBounds().left<-100 || bulletSprite.getGlobalBounds().left>1200 || bulletSprite.getGlobalBounds().top < -100 || bulletSprite.getLocalBounds().top > 1000)
    {
        return 1;
    }
    return 0;
}

sf::Vector2i Bullet::getSpeedXY()
{
    return sf::Vector2i(moveSpeedBulletX,moveSpeedBulletY);
}



float Bullet::setreturnBulletPosition(Player &player)
{
    sprite.setPosition(player.getSpritePlayer().getPosition());
    sprite.setRotation(player.getSpritePlayer().getRotation()+90);
    return player.getSpritePlayer().getRotation();

}
