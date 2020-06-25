#include "Menu.h"
#include "grajj.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(1100, 900), "Tytul");

//wczytaj tekstury
    sf::Texture texturePlayer;
    if (!texturePlayer.loadFromFile("textures\\player.png")) {
        std::cout << "Could not load texture player.png" << std::endl;
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
    SmallZombie smallzombie(textureZombie);
    MediumZombie mediumzombie(textureZombie);
    BigZombie bigzombie(textureZombie);
    Otoczenie otoczenie(textureSciana,texturePodloga);

// sprite const

std::vector<sf::Sprite> sciany_sprites = otoczenie.getScianyVectorSprite();


    while (window.isOpen()) {
        sf::Event event;
        sf::Clock clock;

//sprite variable
    sf::Sprite player_sprite = player.getSpritePlayer();

//events
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

        }
//poruszanie
        sf::Time elapsed = clock.restart();
        player.poruszanie(sciany_sprites,elapsed);
        smallzombie.poruszanie(player_sprite,elapsed);
        mediumzombie.poruszanie(player_sprite,elapsed);
        bigzombie.poruszanie(player_sprite,elapsed);
//rysowanie
        window.display();

        otoczenie.rysuj(window);
        player.rysuj(window);
        smallzombie.rysuj(window);
        mediumzombie.rysuj(window);
        bigzombie.rysuj(window);

    }
;
    return 0;
}
