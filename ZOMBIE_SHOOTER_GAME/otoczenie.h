#ifndef OTOCZENIE_H
#define OTOCZENIE_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Otoczenie : public sf::Sprite
{
private:
    std::vector<sf::Sprite> sciany;
    sf::Texture texture; // sciana

    sf::Sprite podlogasprite;
    sf::Texture podlogatexture; // podloga

public:
    Otoczenie(sf::Texture &texture_,sf::Texture &podloga_);
    void rysuj(sf::RenderWindow &window_);
    std::vector<sf::Sprite> getScianyVectorSprite() const;
};


#endif // OTOCZENIE_H
