#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

int main() {

    sf::RenderWindow window(sf::VideoMode(900, 800), "Tytul");
    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
    rectangle.setPosition(500.0, 400.0);
    rectangle.setFillColor(sf::Color(100, 50, 250));

    while (window.isOpen()) {
        sf::Clock clock;
        sf::Event event;



        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.display();
    }

    return 0;
}
