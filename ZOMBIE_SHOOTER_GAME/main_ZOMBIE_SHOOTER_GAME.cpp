#include "graj.h"
#include "bullet.h"
#include "otoczenie.h"
#include "player.h"
#include "zombie.h"
#include "zombieclasses.h"
#include <obslugagry.h>

#include <memory>

int main() {
    sf::RenderWindow window(sf::VideoMode(1100, 900), "Tytul");

//wczytaj tekstury
    sf::Texture texturePlayer;
    if (!texturePlayer.loadFromFile("textures\\player.png")) {
        std::cout << "Could not load texture player.png" << std::endl;
        return 1;
    }

    sf::Texture textureBullet;
    if (!textureBullet.loadFromFile("textures\\naboj.jpg")) {
        std::cout << "Could not load texture bullet.jpg" << std::endl;
        return 1;
    }

    sf::Texture textureZombie;
    if (!textureZombie.loadFromFile("textures\\zombie_move.png")) {
        std::cout << "Could not load texture zombie_move.png" << std::endl;
        return 1;
    }
    sf::Texture textureSciana;
    if (!textureSciana.loadFromFile("textures\\wall.png")) {
        std::cout << "Could not load texture wall.png" << std::endl;
        return 1;
    }
    textureSciana.setRepeated(true);

    sf::Texture texturePodloga;
    if (!texturePodloga.loadFromFile("textures\\FLOOR3.png")) {
        std::cout << "Could not load texture FLOOR3.png" << std::endl;
        return 1;
    }
    texturePodloga.setRepeated(true);


//obiekty
    ObslugaGry obslugagry;
    Player player(texturePlayer);
    Otoczenie otoczenie(textureSciana,texturePodloga);

// sprite const

std::vector<sf::Sprite> sciany_sprites = otoczenie.getScianyVectorSprite();

//vector
std::vector<std::unique_ptr<Zombie>> zombieVector;
std::vector<std::unique_ptr<Bullet>> bullets;


//zmienne
float time_to_spawn_smallzombie=0;
float time_to_spawn_mediumzombie=0;
float time_to_spawn_bigzombie=0;

float time_enemies_mediumzombie=0;
float time_enemies_smallzombie=0;
float time_enemies_bigzombie=0;

float time_since_shooted;

float wspolczynnik_szybszego_spawnu=1;

        float czas_styku=0;

bool is_paused=false;
sf::Sprite bulletSprite;
sf::Sprite zombieSprite;



    while (window.isOpen()) {
            int player_hp = player.zwrocHPPlayer();

if(!is_paused)
{


//spawn zombies in time:
        //smallzombie
        sf::Clock clock_to_spawn_smallzombie;

         time_enemies_smallzombie = clock_to_spawn_smallzombie.getElapsedTime().asSeconds();
         wspolczynnik_szybszego_spawnu = (wspolczynnik_szybszego_spawnu + time_enemies_smallzombie)/1,07;
        time_to_spawn_smallzombie = time_enemies_smallzombie + time_to_spawn_smallzombie * wspolczynnik_szybszego_spawnu;



            if(time_to_spawn_smallzombie >= 0.0005)
            {
            zombieVector.emplace_back(new SmallZombie(textureZombie));
            zombieVector.back()->setZombiePosition();
            time_to_spawn_smallzombie = 0;
            }
        //mediumzombie
             sf::Clock clock_to_spawn_mediumzombie;

              time_enemies_mediumzombie = clock_to_spawn_smallzombie.getElapsedTime().asSeconds();
             time_to_spawn_mediumzombie = time_enemies_mediumzombie + time_to_spawn_mediumzombie * wspolczynnik_szybszego_spawnu;

                 if(time_to_spawn_mediumzombie >= 0.02)
                 {
                 zombieVector.emplace_back(new MediumZombie(textureZombie));
                 zombieVector.back()->setZombiePosition();
                 time_to_spawn_mediumzombie = 0;
                 }
         //bigzombie
                 sf::Clock clock_to_spawn_bigzombie;

                  time_enemies_bigzombie = clock_to_spawn_bigzombie.getElapsedTime().asSeconds();
                 time_to_spawn_bigzombie = time_enemies_bigzombie + time_to_spawn_bigzombie * wspolczynnik_szybszego_spawnu;

                     if(time_to_spawn_bigzombie >= 0.05)
                     {
                     zombieVector.emplace_back(new BigZombie(textureZombie));
                     zombieVector.back()->setZombiePosition();
                     time_to_spawn_bigzombie = 0;
                     }


                     //

     sf::Clock clock;


    //

sf::Time elapsed = clock.restart();
//bullet shoot
       time_since_shooted=elapsed.asSeconds() + time_since_shooted;
       if(time_since_shooted>=0.00001)
       {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
          bullets.emplace_back(new Bullet(textureBullet,player));
          time_since_shooted=0;
        }
       }
//poruszanie
       //sprite variable
           sf::Sprite player_sprite = player.getSpritePlayer();

        player.poruszanie(elapsed);
        sf::Vector2i moveSpeedVector = player.getSpeedXY();

        int x_move_speed = moveSpeedVector.x;
        int y_move_speed = moveSpeedVector.y;
        //player kolizja - sciana + wychodzenie poza mape          // NEW po poprawie
        for(auto &el : sciany_sprites)
        {
            if(player_sprite.getGlobalBounds().intersects(el.getGlobalBounds()))
            {
                //gora dol
                if(el.getGlobalBounds().contains(player_sprite.getGlobalBounds().left + 20,player_sprite.getGlobalBounds().top) || el.getGlobalBounds().contains(player_sprite.getGlobalBounds().left - 20 + player_sprite.getGlobalBounds().width,player_sprite.getGlobalBounds().top) )
                {
                        player.animate(0,abs(y_move_speed*elapsed.asSeconds()));
                }
                else if(el.getGlobalBounds().contains(player_sprite.getGlobalBounds().left + 20 ,player_sprite.getGlobalBounds().top + player_sprite.getGlobalBounds().height) || el.getGlobalBounds().contains(player_sprite.getGlobalBounds().left - 20 + player_sprite.getGlobalBounds().width,player_sprite.getGlobalBounds().top + player_sprite.getGlobalBounds().height) )
                {
                        player.animate(0,-abs(y_move_speed*elapsed.asSeconds()));
                }
                //lewo prawo
                if(el.getGlobalBounds().contains(player_sprite.getGlobalBounds().left,player_sprite.getGlobalBounds().top + 20) || el.getGlobalBounds().contains(player_sprite.getGlobalBounds().left,player_sprite.getGlobalBounds().top - 20 + player_sprite.getGlobalBounds().height) )
                {
                        player.animate(abs(x_move_speed*elapsed.asSeconds()),0);
                }
                else  if(el.getGlobalBounds().contains(player_sprite.getGlobalBounds().left+player_sprite.getGlobalBounds().width,player_sprite.getGlobalBounds().top + 20) || el.getGlobalBounds().contains(player_sprite.getGlobalBounds().left + player_sprite.getGlobalBounds().width,player_sprite.getGlobalBounds().top - 20 + player_sprite.getGlobalBounds().height) )
                {
                        player.animate(-abs(x_move_speed*elapsed.asSeconds()),0);
                }
            }

        }
        //wychodzenie poza mape
        if(player_sprite.getGlobalBounds().left<0)
        {
            player.animate(abs(x_move_speed*elapsed.asSeconds()),0);
        }
        else if(player_sprite.getGlobalBounds().left + player_sprite.getGlobalBounds().width>1100)
        {
            player.animate(-abs(x_move_speed*elapsed.asSeconds()),0);
        }
        else if(player_sprite.getGlobalBounds().top<0)
        {
            player.animate(0,abs(y_move_speed*elapsed.asSeconds()));
        }
        else  if(player_sprite.getGlobalBounds().top + player_sprite.getGlobalBounds().height>900)
        {
            player.animate(0,-abs(y_move_speed*elapsed.asSeconds()));
        }


        //zombie poruszanie

        for(auto &el : zombieVector)
        {
            sf::Vector2i moveSpeedZombie=el->getSpeedXY();

            el->poruszanie(player_sprite,sciany_sprites,elapsed); // poruszanie zombie
            //kolizja zombie gracz
            if(el->getSprite().getGlobalBounds().intersects(player_sprite.getGlobalBounds()))
            {
                el->animate(-moveSpeedZombie.x*elapsed.asSeconds(), -moveSpeedZombie.y*elapsed.asSeconds());
            }

        }

//lot kuli
        for (unsigned i=0; i < bullets.size(); i++)
        {
            bullets[i]->bulletShooted(elapsed);

        }
        //kolizja pocisk - zombie + usuwanie zombie jesli <0 hp
        for(unsigned i=0; i < bullets.size(); i++)
        {
            bulletSprite = bullets[i]->getSprite();
            for(unsigned j=0; j < zombieVector.size(); j++)
            {
                zombieSprite = zombieVector[j]->getSprite();

                if(bulletSprite.getGlobalBounds().intersects(zombieSprite.getGlobalBounds()))
                {
                        zombieVector[j]->odejmijHPZombie();
                }
 //kolizja zomie -> gracz
                sf::Clock time_zombie_intersects_player;

                if(zombieSprite.getGlobalBounds().intersects(player_sprite.getGlobalBounds()))
                {
                    sf::Time time_intersection = time_zombie_intersects_player.restart();
                czas_styku=czas_styku+time_intersection.asSeconds();
                if(czas_styku>=0.00002)
                {
                    player.odejmijHPPlayer(2);                                                    // aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
                    czas_styku=0;
                    std::cout<<player_hp<<std::endl;
                }
                }


            }


        }
        //usuwanie kuli kolizja zombie
        for(unsigned j=0; j < zombieVector.size(); j++)
        {
        bullets.erase(
            std::remove_if(bullets.begin(), bullets.end(),[&](std::unique_ptr<Bullet> &bullet) { return bullet->getSprite().getGlobalBounds().intersects(zombieVector[j]->getSprite().getGlobalBounds()); }),bullets.end() );
        }
        //bulllets poza mapa usuwanie
        for(size_t j = 0; j < bullets.size(); )
        {
        auto &bullet = bullets[j];
        bulletSprite = bullet->getBulletSprite();
            if (bullet->bulletPozaMapa(bulletSprite))
            {
                bullets.erase(bullets.begin()+j);
            }
            else
            {
                ++j;
            }
        }
        //usuwanie zombie =<0 hp
        for(size_t j = 0; j < zombieVector.size(); )
        {
        auto &zombie = zombieVector[j];;
            if (zombie->zwrocHPZombie()<=0)
            {
                zombieVector.erase(zombieVector.begin()+j);
            }
            else
            {
                ++j;
            }
        }



        if(player_hp<=0)
        {
             obslugagry.restart(player_hp,zombieVector,bullets);
        }






}

//player.odejmijHP(2);
//events
sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();



        }
        if ( sf::Keyboard::isKeyPressed(sf::Keyboard::P) )
        {
            is_paused = obslugagry.pause();
        }

//rysowanie
        window.display();
        otoczenie.rysuj(window);

        for(auto &el : bullets)
        {
            el->rysuj(window);
        }

       player.rysuj(window);

        for(auto &el : zombieVector)
        {
            el->rysuj(window);
        }


    }

    return 0;
}
