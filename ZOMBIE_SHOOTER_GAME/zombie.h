#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <graj.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>




class Zombie : public Graj
{
protected:
    int moveSpeedZombie=2500000;

float angle_zombie_player_to_move = 0; //  do poruszania w strone gracza
float angle_zombie_player_to_face = 0; // do rotacji zombie w strone gracza

int moveSpeedZombieX=0;
int moveSpeedZombieY=0;


public:
    Zombie();
    void poruszanie(sf::Sprite &player_sprite,std::vector<sf::Sprite> &sciany_sprites,sf::Time &elapsed );
    void setZombiePosition();
    virtual void odejmijHPZombie()=0;
    virtual int zwrocHPZombie() const=0;

};

#endif // ZOMBIE_H
