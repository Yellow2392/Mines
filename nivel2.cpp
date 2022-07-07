#include "nivel2.h"
#include <iostream>

using namespace std;

Nivel2::Nivel2(){
  srand(time(0));
    casillas = 36;
    X=6;
    Y=6;
    tablero=new char*[6];
    for(int i=0; i<9;i++){
        tablero[i] = new char[6];
    }
  tablero1 = new char*[6];
  for(int i=0; i<9;i++){
        tablero1[i] = new char[6];
    }
  //Generar matriz para nivel
  char nivel2[6][6];
  for(int i=0; i<X;i++){
        for(int j=0; j<X;j++){
          if (j<=i){
            nivel2[i][j]='0';
            }
          else{
            nivel2[i][j]='|';
          }
        }
    }
  
  //Generar la posición de la mina de manera aleatoria
//4 minas para la forma triangular
  for (int i=0;i<4;i++){
    int randX=(rand() % 6);
    int randY=(rand() % 6);

    if (randY>randX){
      randY=randX;
    }

    while (nivel2[randX][randY]=='*'){
      int randX=(rand() % 6);
      int randY=(rand() % 6);
    }
    nivel2[randX][randY]='*';
  }
  
  
    for(int i=0; i<X;i++){
        for(int j=0; j<X;j++){
            char val = nivel2[i][j];
            tablero[i][j]=val;
        }
    }
  
  for(int i=0; i<X;i++){
        for(int j=0; j<X;j++){
            //char val = nivel2[i][j];
          if (j<=i)
            tablero1[i][j]='#';
          else
            tablero1[i][j]='|';
        }
    }
  
}

void Nivel2::print(){
    cout << "  1     2     3     4     5     6" << endl;
    cout << "1 ";
    cout << tablero1[0][0] <<"-----" << tablero1[0][1] << "-----" << tablero1[0][2] << "-----" << tablero1[0][3] << "-----" << tablero1[0][4] << "-----"<<tablero1[0][5] << endl;
    cout << "  |     |     |     |     |     |" << endl;
    cout << "2 ";
    cout << tablero1[1][0]<<"-----" <<tablero1[1][1] << "-----" << tablero1[1][2] << "-----" << tablero1[1][3] << "-----" << tablero1[1][4] << "-----" << tablero1[1][5] << endl;
    cout << "  |     |     |     |     |     |" << endl;
    cout << "3 ";
    cout << tablero1[2][0] << "-----" << tablero1[2][1] << "-----" << tablero1[2][2] << "-----" << tablero1[2][3] << "-----" << tablero1[2][4] << "-----" << tablero1[2][5] << endl;
    cout << "  |     |     |     |     |     |" << endl;
    cout << "4 ";
    cout << tablero1[3][0] << "-----" << tablero1[3][1] << "-----" << tablero1[3][2] << "-----" << tablero1[3][3] << "-----" << tablero1[3][4] << "-----" << tablero1[3][5] <<  endl;
    cout << "  |     |     |     |     |     |" << endl;
    cout << "5 ";
    cout << tablero1[4][0] << "-----" << tablero1[4][1] << "-----" << tablero1[4][2] << "-----" << tablero1[4][3] << "-----" << tablero1[4][4] << "-----" << tablero1[4][5] <<   endl;
    cout << "  |     |     |     |     |     |" << endl;
    cout << "6 ";
    cout <<tablero1[5][0] << "-----" << tablero1[5][1] << "-----" << tablero1[5][2] << "-----" << tablero1[5][3] << "-----" << tablero1[5][4] << "-----" << tablero1[5][5] << endl;

}

