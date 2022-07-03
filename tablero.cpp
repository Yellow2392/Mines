#include "tablero.h"

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
    if(tablero[x][y] == '1'){
        elegir2(x,y);
        return true;
    } else{
        return false;
    }
}

void Tablero::elegir(int x, int y){
    casillas--;
    tablero[x][y] = '+';
}
void Tablero::elegir2(int x,int y){
    casillas--;
    tablero[x][y] = '1';
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
