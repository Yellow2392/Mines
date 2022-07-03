#include "nivel1.h"
#include <iostream>

using namespace std;

Nivel1::Nivel1(){
  srand(time(0));
    casillas = 36;
    X=6;
    Y=6;
    tablero=new char*[6];
    for(int i=0; i<9;i++){
        tablero[i] = new char[6];
    }

  //Generar matriz para nivel
  char nivel1[6][6];
  for(int i=0; i<X;i++){
        for(int j=0; j<X;j++){
          nivel1[i][j]='0';
        }
    }
  //Generar la posición de la mina de manera aleatoria
  for (int i=0;i<6;i++){
    int randX=(rand() % 6);
    int randY=(rand() % 6);
    while (nivel1[randX][randY]=='*'){
      int randX=(rand() % 6);
      int randY=(rand() % 6);
    }
    nivel1[randX][randY]='*';
  }
  
  
    for(int i=0; i<X;i++){
        for(int j=0; j<X;j++){
            char val = nivel1[i][j];
            tablero[i][j]=val;
        }
    }
}

void Nivel1::print(){
    cout << "  1     2     3     4     5     6" << endl;
    cout << "1 ";
    cout << tablero[0][0] <<"-----" << tablero[0][1] << "-----" << tablero[0][2] << "-----" << tablero[0][3] << "-----" << tablero[0][4] << "-----"<<tablero[0][5] << endl;
    cout << "  |     |     |     |     |     |" << endl;
    cout << "2 ";
    cout << tablero[1][0]<<"-----" <<tablero[1][1] << "-----" << tablero[1][2] << "-----" << tablero[1][3] << "-----" << tablero[1][4] << "-----" << tablero[1][5] << endl;
    cout << "  |     |     |     |     |     |" << endl;
    cout << "3 ";
    cout << tablero[2][0] << "-----" << tablero[2][1] << "-----" << tablero[2][2] << "-----" << tablero[2][3] << "-----" << tablero[2][4] << "-----" << tablero[2][5] << endl;
    cout << "  |     |     |     |     |     |" << endl;
    cout << "4 ";
    cout << tablero[3][0] << "-----" << tablero[3][1] << "-----" << tablero[3][2] << "-----" << tablero[3][3] << "-----" << tablero[3][4] << "-----" << tablero[3][5] <<  endl;
    cout << "  |     |     |     |     |     |" << endl;
    cout << "5 ";
    cout << tablero[4][0] << "-----" << tablero[4][1] << "-----" << tablero[4][2] << "-----" << tablero[4][3] << "-----" << tablero[4][4] << "-----" << tablero[4][5] <<   endl;
    cout << "  |     |     |     |     |     |" << endl;
    cout << "6 ";
    cout <<tablero[5][0] << "-----" << tablero[5][1] << "-----" << tablero[5][2] << "-----" << tablero[5][3] << "-----" << tablero[5][4] << "-----" << tablero[5][5] << endl;

}

