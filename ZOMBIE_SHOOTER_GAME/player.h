#ifndef PLAYER_H
#define PLAYER_H

#include <graj.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Player : public Graj
{
private:
    int hpPlayer=200;
    int moveSpeed = 6000000;

public:
    Player(sf::Texture &texture_);
    void poruszanie(std::vector<sf::Sprite> &sciany, sf::Time &elapsed);
    sf::Sprite getSpritePlayer() const;
    void odejmijHPPlayer(const int &liczba_do_odjecia);
    int zwrocHPPlayer() const;
    void odejmijHP();
    int zwrocHP() const;
};

#endif // PLAYER_H
