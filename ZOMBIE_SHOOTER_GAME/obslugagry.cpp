#include "obslugagry.h"

ObslugaGry::ObslugaGry()
{

}

bool ObslugaGry::pause()
{
    Sleep(150);
  if(!is_paused)
  {
      is_paused=1;
      return 1;
  }
  else
  {
      is_paused=0;
      return 0;
  }
}

void ObslugaGry::restart(int &liczba_hp_player, std::vector<std::unique_ptr<Zombie> > &zombieVector, std::vector<std::unique_ptr<Bullet> > &bullets)
{
    liczba_hp_player=200;


    for(unsigned long long i = 0; i<zombieVector.size(); i++)
    {
        zombieVector.erase(zombieVector.begin()+i);
    }
    for(unsigned long long i = 0; i<bullets.size(); i++)
    {
        bullets.erase(bullets.begin()+i);
    }
}
