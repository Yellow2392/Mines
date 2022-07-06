#include "cruz.h"
#include <iostream>

using namespace std;


NivelCruz::NivelCruz(){
  srand(time(0));
    casillas = 49;
    X=7;
    Y=7;
    tablero=new char*[7];
    for(int i=0; i<7;i++){
        tablero[i] = new char[7];
    }
  tablero1 = new char*[7];
  for(int i=0; i<7;i++){
        tablero1[i] = new char[7];
    }
  //Generar matriz para nivel
  char nivel1[7][7];
  for(int i=0; i<X;i++){
        for(int j=0; j<X;j++){
          nivel1[i][j]='0';
        }
    }
  }


void NivelCruz::print() {
    cout << "  1     2     3     4     5     6     7" << endl;
    cout << "1             ";
    cout << tablero[0][2] << "-----" << tablero[0][3] << "-----" << tablero[0][4] << endl;
    cout << "              |     |     |" << endl;
    cout << "2             ";
    cout << tablero[1][2] << "-----" << tablero[1][3] << "-----" << tablero[1][4] << endl;
    cout << "              |     |     |" << endl;
    cout << "3 ";
    cout << tablero[2][0] << "-----" << tablero[2][1] << "-----" << tablero[2][2] << "-----" << tablero[2][3] << "-----" << tablero[2][4] << "-----" << tablero[2][5] << "-----" << tablero[2][6] << endl;
    cout << "  |     |     |     |     |     |     |" << endl;
    cout << "4 ";
    cout << tablero[3][0] << "-----" << tablero[3][1] << "-----" << tablero[3][2] << "-----" << tablero[3][3] << "-----" << tablero[3][4] << "-----" << tablero[3][5] << "-----" << tablero[3][6] << endl;
    cout << "  |     |     |     |     |     |     |" << endl;
    cout << "5 ";
    cout << tablero[4][0] << "-----" << tablero[4][1] << "-----" << tablero[4][2] << "-----" << tablero[4][3] << "-----" << tablero[4][4] << "-----" << tablero[4][5] << "-----" << tablero[4][6] << endl;
    cout << "              |     |     |" << endl;
    cout << "6             ";
    cout << tablero[5][2] << "-----" << tablero[5][3] << "-----" << tablero[5][4] << endl;
    cout << "              |     |     |" << endl;
    cout << "7             ";
    cout << tablero[6][2] << "-----" << tablero[6][3] << "-----" << tablero[6][4] << endl;
}