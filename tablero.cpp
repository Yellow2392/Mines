#include "tablero.h"
bool isValidPos(int i, int j, int X, int Y){
  if ((i>=0 && j>=0) && (i<=X && j<=Y))
    return true;
  return false;
  }

bool Tablero::elegir_casilla(int x, int y){
    if( x>=X || y >= Y) return false;
    if(tablero[x][y] == '0'){
        elegir(x,y);
        return true;
    } else{
        return false;
    }
}

bool Tablero::casilla_mina(int x, int y) {
    if( x>=X || y >= Y) return false;
    if(tablero[x][y] == '*'){
        elegir2(x,y);
        return true;
    } else{
        return false;
    }
}

void Tablero::elegir(int x, int y){
    casillas--;
  //Aqui
    int n=0;
  if (isValidPos(x-1,y-1,X,Y)){
    if (tablero[x-1][y-1]=='*')
        n++;
    }
  if (isValidPos(x-1,y,X,Y)){
    if (tablero[x-1][y]=='*')
        n++;
    }
  if (isValidPos(x-1,y+1,X,Y)){
    if (tablero[x-1][y+1]=='*')
        n++;
    }
  if (isValidPos(x,y-1,X,Y)){
    if (tablero[x][y-1]=='*')
        n++;
    }
  if (isValidPos(x,y+1,X,Y)){
    if (tablero[x][y+1]=='*')
        n++;
    }
  if (isValidPos(x+1,y-1,X,Y)){
    if (tablero[x+1][y-1]=='*')
        n++;
    }
  if (isValidPos(x+1,y,X,Y)){
    if (tablero[x+1][y]=='*')
        n++;
    }
  if (isValidPos(x+1,y+1,X,Y)){
    if (tablero[x+1][y+1]=='*')
        n++;
    }
    switch (n){
      case 1:
      tablero[x][y] = '1';
      tablero1[x][y] = '1';
      break;
      case 2:
      tablero[x][y] = '2';
      tablero1[x][y] = '2';
      break;
      case 3:
      tablero[x][y] = '3';
      tablero1[x][y] = '3';
      break;
      case 4:
      tablero[x][y] = '4';
      tablero1[x][y] = '4';
      break;
      case 5:
      tablero[x][y] = '5';
      tablero1[x][y] = '5';
      break;
      case 6:
      tablero[x][y] = '6';
      tablero1[x][y] = '6';
      break;
      case 7:
      tablero[x][y] = '7';
      tablero1[x][y] = '7';
      break;
      case 8:
      tablero[x][y] = '8';
      tablero1[x][y] = '8';
      break;
      default:
      tablero[x][y] = '0';
      tablero1[x][y] = ' ';
      break;
    }
    //tablero[x][y] = '+';
}
void Tablero::elegir2(int x,int y){
    casillas--;
    tablero[x][y] = '*';
}

bool Tablero::gano(){
    if(casillas == 1){
        return true;
    }
    return false;
}

bool Tablero::es_posible_elegir(){
    for(int i=0;i<X;i++){
        for(int j=0;j<Y;j++){
            if(tablero[i][j] == '0')
                return true;
            }
        }
    return false;
}

Tablero::~Tablero(){
    for(int i=0;i<Y;i++){
        delete[] tablero[i];
    }
    delete[] tablero;
}

void Tablero::colocarBandera(int x, int y){
  tablero1[x-1][y-1]='+';
}
