
#include "Menu.h"
#include "grajj.h"
int main() {


    sf::RenderWindow window(sf::VideoMode(900, 800), "Tytul");

    //wczytaj tekstury
    sf::Texture texturePlayer;
    if (!texturePlayer.loadFromFile("E:\\POLIBUDA\\II\\PSIO\\Prace domowe\\10 labirynt\\build-LABIRYNT-Desktop_Qt_5_13_2_MinGW_64_bit-Debug\\debug\\grass.png")) {
        std::cout << "Could not load texture 1" << std::endl;
        return 1;
    }
    //obiekty
    Player player(texturePlayer);





    while (window.isOpen()) {
        sf::Clock clock;
        sf::Event event;



        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.display();
        player.rysuj(window);
    }
;
    return 0;
}
