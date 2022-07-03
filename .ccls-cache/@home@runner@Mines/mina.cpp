#include "mina.h"
#include <stdlib.h>
#include <time.h>

mina::mina(int x, int y){
  srand(time(NULL));
  pos_x= 1+rand()%(x-1);
  pos_y= 1+1+rand()%(y-1);
}
char mina::get_caracter(){
  return caracter;
}
int mina::get_posx(){
  return pos_x;
}
int mina::get_posy(){
  return pos_y;
}