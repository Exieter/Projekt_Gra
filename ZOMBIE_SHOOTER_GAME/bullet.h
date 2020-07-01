#ifndef BULLET_H
#define BULLET_H

#include <graj.h>
#include <player.h>




class Bullet : public Graj
{
private:
    int bullet_speed=100000;
    int rotation_angle=0;
    float time_since_last_shot=0;

    float setreturnBulletPosition(Player &player);

public:
    Bullet(sf::Texture &texture_,Player &player); //wczytuje teksture inicjueje do sprite
    void bulletShooted(sf::Time &elapsed); //  kula ruszanie


};

#endif // BULLET_H
