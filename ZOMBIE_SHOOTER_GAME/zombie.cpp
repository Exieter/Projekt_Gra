#include "zombie.h"

Zombie::Zombie()
{

}
void Zombie::setZombiePosition()
{
    switch (rand()%4) {
    case 0:
        sprite.setPosition(550,-40); //gora
        break;
    case 1:
        sprite.setPosition(550,940);//dol
        break;
    case 2:
        sprite.setPosition(-40,450);//lewo
        break;
    case 3:
        sprite.setPosition(1140,450);//prawo
        break;
    default:
        std::cerr<< " ERROR IN SETTING POS" << std::endl;
    }
}
void Zombie::poruszanie( sf::Sprite &player_sprite,std::vector<sf::Sprite> &sciany_sprites, sf::Time &elapsed )
{
    angle_zombie_player_to_move = atan2(player_sprite.getPosition().y - sprite.getPosition().y, player_sprite.getPosition().x - sprite.getPosition().x);

    sprite.setOrigin( (sprite.getLocalBounds().height / 2) , (sprite.getLocalBounds().width / 2) ); // os obrotu na srodku tekstury
    player_sprite.setOrigin( (player_sprite.getLocalBounds().height / 2) , (player_sprite.getLocalBounds().width / 2));

    angle_zombie_player_to_face = angle_zombie_player_to_move * 57.32; // 57.32 == 360/2pi
    sprite.setRotation(angle_zombie_player_to_face);
    if(!sprite.getGlobalBounds().intersects(player_sprite.getGlobalBounds())) // to w mAIN MUSI aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    {
    moveSpeedZombieX=std::cos(angle_zombie_player_to_move) * moveSpeedZombie;
    moveSpeedZombieY=std::sin(angle_zombie_player_to_move) * moveSpeedZombie;
    }
    animate(moveSpeedZombieX*elapsed.asSeconds(),moveSpeedZombieY*elapsed.asSeconds());

}
