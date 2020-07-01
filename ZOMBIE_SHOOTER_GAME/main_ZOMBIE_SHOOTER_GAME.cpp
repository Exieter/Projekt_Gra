
#include "graj.h"
#include "bullet.h"
#include "otoczenie.h"
#include "player.h"
#include "zombie.h"
#include "zombieclasses.h"

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

    while (window.isOpen()) {
        sf::Event event;
//spawn zombies in time:
        //smallzombie
        sf::Clock clock_to_spawn_smallzombie;

         time_enemies_smallzombie = clock_to_spawn_smallzombie.getElapsedTime().asSeconds();
        time_to_spawn_smallzombie = time_enemies_smallzombie + time_to_spawn_smallzombie * 1.0005;

            if(time_to_spawn_smallzombie >= 0.001)
            {
            zombieVector.emplace_back(new SmallZombie(textureZombie));
            zombieVector.back()->setZombiePosition();
            time_to_spawn_smallzombie = 0;
            }
        //mediumzombie
             sf::Clock clock_to_spawn_mediumzombie;

              time_enemies_mediumzombie = clock_to_spawn_smallzombie.getElapsedTime().asSeconds();
             time_to_spawn_mediumzombie = time_enemies_mediumzombie + time_to_spawn_mediumzombie * 1.0005;

                 if(time_to_spawn_mediumzombie >= 0.05)
                 {
                 zombieVector.emplace_back(new MediumZombie(textureZombie));
                 zombieVector.back()->setZombiePosition();
                 time_to_spawn_mediumzombie = 0;
                 }
         //bigzombie
                 sf::Clock clock_to_spawn_bigzombie;

                  time_enemies_bigzombie = clock_to_spawn_bigzombie.getElapsedTime().asSeconds();
                 time_to_spawn_bigzombie = time_enemies_bigzombie + time_to_spawn_bigzombie * 1.0005;

                     if(time_to_spawn_bigzombie >= 0.1)
                     {
                     zombieVector.emplace_back(new BigZombie(textureZombie));
                     zombieVector.back()->setZombiePosition();
                     time_to_spawn_bigzombie = 0;
                     }


                     //

     sf::Clock clock;

//sprite variable
    sf::Sprite player_sprite = player.getSpritePlayer();

//events

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

        }
        if ( sf::Keyboard::isKeyPressed(sf::Keyboard::P) )
                                {

                                }

        //jesli spacja = emplaceback new Bullet(texture,elapsed,player)

sf::Time elapsed = clock.restart();
       time_since_shooted=elapsed.asSeconds() + time_since_shooted;
       if(time_since_shooted>=0.002)
       {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
          bullets.emplace_back(new Bullet(textureBullet,player));
          time_since_shooted=0;
        }
       }
//poruszanie

        player.poruszanie(sciany_sprites,elapsed);

        for(auto &el : zombieVector)
        {
            el->poruszanie(player_sprite,sciany_sprites,elapsed); // poruszanie zombie
        }
        for(auto &el : bullets)
        {
            el->bulletShooted(elapsed);

         }

        //xollsion bulelts



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
