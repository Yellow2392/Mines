#include "cruz.h"
#include <iostream>

using namespace std;


NivelCruz::NivelCruz(){
    srand(time(0));
    casillas = 81;
    X=9;
    Y=9;
    tablero=new char*[9];
    for(int i=0; i<9;i++){
        tablero[i] = new char[9];
    }
  tablero1 = new char*[9];
  for(int i=0; i<9;i++){
        tablero1[i] = new char[9];
    }
  //Generar matriz para nivel
  char nivel1[9][9];
  for(int i=0; i<X;i++){
        for(int j=0; j<X;j++){
          if (j==X/2 || j==X/2+1 || j == X/2-1 ){
            nivel1[i][j]='0';
          }
          else if(i==X/2 || i==X/2+1 || i == X/2-1 ){
            nivel1[i][j]='0';
          }
          else{
            nivel1[i][j]='|';
          }
        }
    }
  //Generar la posición de la mina de manera aleatoria
  //Generar 7 minas para la cruz
  for (int i=0;i<7;i++){
    int randX=(rand() % 9);
    int randY;
    if (randX>=0 && randX<3){
      randY=3+(rand() % (5-3+1));
    }
    else if(randX>=3 && randX<6){
      randY=(rand() % 9);
    }
    else{
      randY=3+(rand() % (5-3+1));
    }
    while (nivel1[randX][randY]=='*'){
      int randX=(rand() % 9);
      int randY=(rand() % 9);
    }
    nivel1[randX][randY]='*';
  }

  for(int i=0; i<X;i++){
        for(int j=0; j<X;j++){
            char val = nivel1[i][j];
            tablero[i][j]=val;
        }
    }

    for(int i=0; i<X;i++){
        for(int j=0; j<X;j++){
          if (j==X/2 || j==X/2+1 || j == X/2-1 ){
            tablero1[i][j]='0';
          }
          else if(i==X/2 || i==X/2+1 || i == X/2-1 ){
            tablero1[i][j]='0';
          }
          else{
            tablero1[i][j]='|';
          }
        }
    }
  
}

void NivelCruz::print() {
cout<<"  ";
  for (int i=1;i<=X;i++){
    if(i!=X)
      cout<<i<<"     ";
    else
      cout<<i<<endl;
  }

   for (int i=0;i<X;i++){
    for(int j=0;j<X;j++){
      if (j==0){
        cout<<i+1<<" "<<tablero1[i][j]<<"-----";
      }
      else if (j==X-1){
        cout<<tablero1[i][j];
      }
      else
        cout<<tablero1[i][j]<<"-----";
      }
    cout<<endl;
     for (int k=0;k<X;k++){
       if (i!=X-1){
      if(k==0){
        cout<<"  "<<"|"<<"     ";}
      else if (k==X-1){
        cout<<"|"<<endl;
      }
      else{
        cout<<"|"<<"     ";}
     }
    
       }
    }
}
/*
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

*/