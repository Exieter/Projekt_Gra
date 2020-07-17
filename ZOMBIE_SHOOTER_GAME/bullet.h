#ifndef BULLET_H
#define BULLET_H

#include <graj.h>
#include <player.h>




class Bullet : public Graj
{
private:
    int bullet_speed=10000000;
    int rotation_angle=0;
    float time_since_last_shot=0;

    int moveSpeedBulletX=0;
    int moveSpeedBulletY=0;

    float setreturnBulletPosition(Player &player);

public:
    Bullet(sf::Texture &texture_,Player &player); //wczytuje teksture inicjueje do sprite
    void bulletShooted(sf::Time &elapsed); //  kula ruszanie
    sf::Sprite getBulletSprite();
    bool bulletPozaMapa(sf::Sprite &bulletSprite);

    sf::Vector2i getSpeedXY();

    //
    int zwrocHP() const{return 0;};
    void odejmijHP(){;};

};

#endif // BULLET_H
