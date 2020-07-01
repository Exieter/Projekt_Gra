#ifndef OBSLUGAGRY_H
#define OBSLUGAGRY_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <windows.h>
class ObslugaGry
{
    bool is_paused = 0;
public:
    ObslugaGry();
    bool pause();

};

#endif // OBSLUGAGRY_H
