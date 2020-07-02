#ifndef BULLET_H
#define BULLET_H

#include <graj.h>
#include <player.h>




class Bullet : public Graj
{
private:
    int bullet_speed=1000000;
    int rotation_angle=0;
    float time_since_last_shot=0;

    float setreturnBulletPosition(Player &player);

public:
    Bullet(sf::Texture &texture_,Player &player); //wczytuje teksture inicjueje do sprite
    void bulletShooted(sf::Time &elapsed); //  kula ruszanie
    sf::Sprite getBulletSprite();
    bool bulletPozaMapa(sf::Sprite &bulletSprite);

};

#endif // BULLET_H
