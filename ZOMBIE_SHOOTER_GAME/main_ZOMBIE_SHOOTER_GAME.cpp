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
        player.poruszanie(sciany_sprites,elapsed);

        for(auto &el : zombieVector)
        {
            el->poruszanie(player_sprite,sciany_sprites,elapsed); // poruszanie zombie


        }


        for (unsigned i=0; i < bullets.size(); i++) {
//lot kuli
            bullets[i]->bulletShooted(elapsed);
//kolizja pocisk - zombie + usuwanie zombie jesli <0 hp
            bulletSprite = bullets[i]->getSprite();
            for(unsigned j=0; j < zombieVector.size(); j++)
            {
                zombieSprite = zombieVector[j]->getSprite();

                if(bulletSprite.getGlobalBounds().intersects(zombieSprite.getGlobalBounds()))
                {
                    bullets.erase(bullets.begin()+i);


                        zombieVector[i]->odejmijHPZombie();
                        if(zombieVector[i]->zwrocHPZombie()<=0)
                        {
                            zombieVector.erase(zombieVector.begin()+j);

                        }


                }
 //kolizja zomie -> gracz
                sf::Clock time_zombie_intersects_player;

                if(zombieSprite.getGlobalBounds().intersects(player_sprite.getGlobalBounds()))
                {
                    sf::Time time_intersection = time_zombie_intersects_player.restart();
                czas_styku=czas_styku+time_intersection.asSeconds();
                if(czas_styku>=0.00002)
                {
                    player.odejmijHPPlayer(1);
                    czas_styku=0;
                    std::cout<<player_hp<<std::endl;
                }
                }


            }
//kula poza mapa
            if(bullets[i]->bulletPozaMapa(bulletSprite))
            {
                bullets.erase(bullets.begin()+i);
            }

        }
        if(player_hp<=0)
        {
             obslugagry.restart(player_hp,zombieVector,bullets);
        }






}

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
