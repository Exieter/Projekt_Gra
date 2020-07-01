#include "obslugagry.h"

ObslugaGry::ObslugaGry()
{

}

bool ObslugaGry::pause()
{
    Sleep(150); // przystanek zeby sie nie zapauzowywala i odpauzowywala przy jednym kliknieciu przycisku
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
