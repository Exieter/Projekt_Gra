#ifndef OBSLUGAGRY_H
#define OBSLUGAGRY_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <graj.h>
#include <bullet.h>
#include <zombie.h>
class ObslugaGry
{
    bool is_paused = 0;
public:
    ObslugaGry();
    bool pause();
    void restart(int &liczba_hp_player, std::vector<std::unique_ptr<Zombie>> &zombieVector,std::vector<std::unique_ptr<Bullet>> &bullets);

};

#endif // OBSLUGAGRY_H
