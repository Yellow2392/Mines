#ifndef PROYEC_PROGRA_MINA_H
#define PROYEC_PROGRA_MINA_H 

#include <iostream>
using namespace std;

class mina{
private:
  int pos_x=0;
  int pos_y=0;
  bool ifMina=0;
  char caracter='M';// colocar al momento de tocar una mina 

public:
  mina();
  mina(int x, int y);
  int get_posx();
  int get_posy();
  char get_caracter();

};



#endif