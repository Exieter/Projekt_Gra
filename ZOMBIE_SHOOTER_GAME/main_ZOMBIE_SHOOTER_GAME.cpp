
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




    while (window.isOpen()) {
        sf::Clock clock;
        sf::Event event;



        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


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
