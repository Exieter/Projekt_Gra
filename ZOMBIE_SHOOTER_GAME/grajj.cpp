#include "grajj.h"

//konstruktory
Graj::Graj()
{

}



Player::Player(sf::Texture &texture_)
{
    this->texture=texture_;

    sprite.setTexture(texture);
    sprite.setScale(0.3, 0.3);
    sprite.setTextureRect(sf::IntRect(32,30,265,162));
    sprite.setPosition(320,320);
}

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

Zombie::Zombie()
{

}


SmallZombie::SmallZombie(sf::Texture &texture_)
{
    this->texture=texture_;

    sprite.setTexture(texture);
    sprite.setScale(0.2, 0.2);
    sprite.setTextureRect(sf::IntRect(24,70,215,207));
    // sprite.setPosition(320,320);
}

MediumZombie::MediumZombie(sf::Texture &texture_)
{

    this->texture=texture_;

    sprite.setTexture(texture);
    sprite.setScale(0.35, 0.35);
    sprite.setTextureRect(sf::IntRect(24,70,215,207));
    sprite.setPosition(100,120);
}
BigZombie::BigZombie(sf::Texture &texture_)
{
    this->texture=texture_;

    sprite.setTexture(texture);
    sprite.setScale(0.5, 0.5);
    sprite.setTextureRect(sf::IntRect(24,70,215,207));
    sprite.setPosition(200,320);
}
Otoczenie::Otoczenie(sf::Texture &texture_,sf::Texture &podloga_)
{
    //podloga
    podlogatexture=podloga_;
    podlogasprite.setTexture(podlogatexture);
    podlogatexture.setRepeated(true);
    podlogasprite.setScale(0.15,0.15);
    podlogasprite.setTextureRect(sf::IntRect(0,0,1100/0.15,900/0.15));


    //sciany
    this->texture=texture_;
    //lewo gorny rog
    //pion
    sf::Sprite wall1;
    wall1.setTexture(texture);
    texture.setRepeated(true);
    wall1.setScale(0.6, 0.6);
    wall1.setTextureRect(sf::IntRect(-300/0.6,-300/0.6,350/0.6,625/0.6));
    wall1.setPosition(-300,-300);
    sciany.emplace_back(wall1);
    //poziom

    sf::Sprite wall2;
    wall2.setTexture(texture);
    texture.setRepeated(true);
    wall2.setScale(0.6, 0.6);
    wall2.setPosition(0,-300);
    wall2.setTextureRect(sf::IntRect(0/0.6,-300/0.6,400/0.6,350/0.6));
    sciany.emplace_back(wall2);

    //prawy gorny rog
    //poziom
    sf::Sprite wall3;
    wall3.setTexture(texture);
    texture.setRepeated(true);
    wall3.setScale(0.6, 0.6);
    wall3.setPosition(700,-300);
    wall3.setTextureRect(sf::IntRect(700/0.6,-300/0.6,800/0.6,350/0.6));
    sciany.emplace_back(wall3);

    //pion
    sf::Sprite wall4;
    wall4.setTexture(texture);
    texture.setRepeated(true);
    wall4.setScale(0.6, 0.6);
    wall4.setPosition(1050,0);
    wall4.setTextureRect(sf::IntRect(1050/0.6,0/0.6,350/0.6,325/0.6));
    sciany.emplace_back(wall4);

    //dolny lewy rog
    //pion
    sf::Sprite wall5;
    wall5.setTexture(texture);
    texture.setRepeated(true);
    wall5.setScale(0.6, 0.6);
    wall5.setPosition(-300,600);
    wall5.setTextureRect(sf::IntRect(-300/0.6,400/0.6,350/0.6,400/0.6));
    sciany.emplace_back(wall5);
    //poziom
    sf::Sprite wall6;
    wall6.setTexture(texture);
    texture.setRepeated(true);
    wall6.setScale(0.6, 0.6);
    wall6.setPosition(0,850);
    wall6.setTextureRect(sf::IntRect(0/0.6,850/0.6,400/0.6,350/0.6));
    sciany.emplace_back(wall6);
    //prawy dolny rog
    //pion
    sf::Sprite wall7;
    wall7.setTexture(texture);
    texture.setRepeated(true);
    wall7.setScale(0.6, 0.6);
    wall7.setPosition(1050,600);
    wall7.setTextureRect(sf::IntRect(1050/0.6,600/0.6,350/0.6,600/0.6));
    sciany.emplace_back(wall7);
    //poziom
    sf::Sprite wall8;
    wall8.setTexture(texture);
    texture.setRepeated(true);
    wall8.setScale(0.6, 0.6);
    wall8.setPosition(700,850);
    wall8.setTextureRect(sf::IntRect(700/0.6,850/0.6,400/0.6,350/0.6));
    sciany.emplace_back(wall8);

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

std::vector<sf::Sprite> Otoczenie::getScianyVectorSprite() const
{
    return sciany;
}

void Player::poruszanie(std::vector<sf::Sprite> &sciany,sf::Time &elapsed)
{
    sprite.setOrigin( (sprite.getLocalBounds().height / 2)-11 , (sprite.getLocalBounds().width / 2) - 10); // potrzebne do rotacji tesktury
    sf::FloatRect player_bounds = sprite.getGlobalBounds();

    if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) ||(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            sprite.setRotation(-45);
            if(player_bounds.left+player_bounds.width < 1100)
            {
                sprite.move( moveSpeed*elapsed.asSeconds(),0);
                for(auto &el : sciany)
                {
                    if(el.getGlobalBounds().intersects(sprite.getGlobalBounds()))
                    {
                        sprite.move( -moveSpeed*elapsed.asSeconds(),0);
                    }
                }
            }
            if(player_bounds.top > 0)
            {
                sprite.move(0,- moveSpeed*elapsed.asSeconds());
                for(auto &el : sciany)
                {
                    if(el.getGlobalBounds().intersects(sprite.getGlobalBounds()))
                    {
                        sprite.move(0, moveSpeed*elapsed.asSeconds());
                    }
                }
            }
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            sprite.setRotation(405);
            if(player_bounds.left+player_bounds.width < 1100)
            {
                sprite.move( moveSpeed*elapsed.asSeconds(),0);
                for(auto &el : sciany)
                {
                    if(el.getGlobalBounds().intersects(sprite.getGlobalBounds()))
                    {
                        sprite.move(- moveSpeed*elapsed.asSeconds(),0);
                    }
                }

            }
            if(player_bounds.top + player_bounds.height < 900)
            {
                sprite.move(0, moveSpeed*elapsed.asSeconds());
                for(auto &el : sciany)
                {
                    if(el.getGlobalBounds().intersects(sprite.getGlobalBounds()))
                    {
                        sprite.move(0, -moveSpeed*elapsed.asSeconds());
                    }
                }
            }
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            sprite.setRotation(-135);
            if(player_bounds.left > 0)
            {
                sprite.move( -moveSpeed*elapsed.asSeconds(),0);
                for(auto &el : sciany)
                {
                    if(el.getGlobalBounds().intersects(sprite.getGlobalBounds()))
                    {
                        sprite.move( moveSpeed*elapsed.asSeconds(),0);
                    }
                }
            }
            if(player_bounds.top  > 0)
            {
                sprite.move(0, -moveSpeed*elapsed.asSeconds());
                for(auto &el : sciany)
                {
                    if(el.getGlobalBounds().intersects(sprite.getGlobalBounds()))
                    {
                        sprite.move(0, moveSpeed*elapsed.asSeconds());
                    }
                }
            }
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            sprite.setRotation(135);

            if(player_bounds.left > 0)
            {
                sprite.move( -moveSpeed*elapsed.asSeconds(),0);
                for(auto &el : sciany)
                {
                    if(el.getGlobalBounds().intersects(sprite.getGlobalBounds()))
                    {
                        sprite.move( moveSpeed*elapsed.asSeconds(),0);
                    }
                }
            }
            if(player_bounds.top + player_bounds.height < 900)
            {
                sprite.move(0, moveSpeed*elapsed.asSeconds());
                for(auto &el : sciany)
                {
                    if(el.getGlobalBounds().intersects(sprite.getGlobalBounds()))
                    {
                        sprite.move(0, -moveSpeed*elapsed.asSeconds());
                    }
                }
            }
        }
    } else
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if(player_bounds.top>0)
            {
                sprite.setRotation(270);
                sprite.move(0, -moveSpeed*elapsed.asSeconds());
                for(auto &el : sciany)
                {
                    if(el.getGlobalBounds().intersects(sprite.getGlobalBounds()))
                    {
                        sprite.move(0, moveSpeed*elapsed.asSeconds());
                    }
                }
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if(player_bounds.top+player_bounds.height<900)
            {
                sprite.setRotation(-270);
                sprite.move(0, moveSpeed*elapsed.asSeconds());
                for(auto &el : sciany)
                {
                    if(el.getGlobalBounds().intersects(sprite.getGlobalBounds()))
                    {
                        sprite.move(0,-moveSpeed*elapsed.asSeconds());
                    }
                }
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if(player_bounds.left>0)
            {
                sprite.setRotation(180);
                sprite.move( -moveSpeed*elapsed.asSeconds(),0);
                for(auto &el : sciany)
                {
                    if(el.getGlobalBounds().intersects(sprite.getGlobalBounds()))
                    {
                        sprite.move( moveSpeed*elapsed.asSeconds(),0);
                    }
                }
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if(player_bounds.left+player_bounds.width < 1100)
            {
                sprite.setRotation(0);
                sprite.move( moveSpeed*elapsed.asSeconds(),0);
                for(auto &el : sciany)
                {
                    if(el.getGlobalBounds().intersects(sprite.getGlobalBounds()))
                    {
                        sprite.move( -moveSpeed*elapsed.asSeconds(),0);
                    }
                }
            }
        }
    }

}

sf::Sprite Player::getSpritePlayer() const
{
    return sprite;
}
void Zombie::poruszanie( sf::Sprite &player_sprite,std::vector<sf::Sprite> &sciany_sprites, sf::Time &elapsed )
{
    angle_zombie_player_to_move = atan2(player_sprite.getPosition().y - sprite.getPosition().y, player_sprite.getPosition().x - sprite.getPosition().x);

    sprite.setOrigin( (sprite.getLocalBounds().height / 2) , (sprite.getLocalBounds().width / 2) ); // os obrotu na srodku tekstury
    player_sprite.setOrigin( (player_sprite.getLocalBounds().height / 2) , (player_sprite.getLocalBounds().width / 2));

    angle_zombie_player_to_face = angle_zombie_player_to_move * 57.32; // 57.32 == 360/2pi
    sprite.setRotation(angle_zombie_player_to_face);
    if(!sprite.getGlobalBounds().intersects(player_sprite.getGlobalBounds()))
    {
        sprite.move(std::cos(angle_zombie_player_to_move)* elapsed.asSeconds() * moveSpeedZombie, std::sin(angle_zombie_player_to_move) * elapsed.asSeconds() * moveSpeedZombie);
    }
//    for(auto &el : sciany_sprites)
//    {

//        if(sprite.getGlobalBounds().intersects(el.getGlobalBounds()))
//        {
//            sprite.setOrigin(sprite.getLocalBounds().top , sprite.getLocalBounds().left );
//            if(sprite.getGlobalBounds().top + sprite.getGlobalBounds().height <= 450 &&  sprite.getGlobalBounds().top + sprite.getGlobalBounds().height >= 200 )
//            {
//                if(sprite.getGlobalBounds().top<= el.getLocalBounds().top + el.getGlobalBounds().height)
//                {
//                    sprite.move(0,- std::sin(angle_zombie_player_to_move) * elapsed.asSeconds() * moveSpeedZombie);
//                }
//            }
//            if(sprite.getGlobalBounds().top + sprite.getGlobalBounds().height >= 450 && sprite.getGlobalBounds().top + sprite.getGlobalBounds().height <= 700)
//            {
//                if(sprite.getGlobalBounds().top+sprite.getGlobalBounds().height>= el.getLocalBounds().top + el.getGlobalBounds().height)
//                {
//                    sprite.move(0,- std::sin(angle_zombie_player_to_move) * elapsed.asSeconds() * moveSpeedZombie);
//                }
//            }
//        }

//    }

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







