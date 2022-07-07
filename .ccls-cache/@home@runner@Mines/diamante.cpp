#include "diamante.h"
#include <iostream>

using namespace std;
NivelDiamante::NivelDiamante(){
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
  for(int i=0; i<=4;i++){
      for(int j=0; j<=4;j++){
        if(i+j==4||i+j==5||i+j==6||i+j==7||i+j==8) {
          nivel1[i][j]='0';
        }
        else{
          nivel1[i][j]='|';
        }
    }
  }

  for (int i=0;i<=4;i++){
    for (int j=4;j<X;j++){
      if(j<=i+4){
        nivel1[i][j]='0';
      }
      else{
        nivel1[i][j]='|';
      }
    }
  }

  for (int i=4;i<X;i++){
    for (int j=0;j<=4;j++){
      if(j>=i-4){
        nivel1[i][j]='0';
      }
      else{
        nivel1[i][j]='|';
      }
    }
  }

  for(int i=4; i<X;i++){
      for(int j=4; j<X;j++){
        if(i+j==12||i+j==11||i+j==10||i+j==9||i+j==8) {
          nivel1[i][j]='0';
        }
        else{
          nivel1[i][j]='|';
        }
    }
  }
  //Generar la posición de la mina de manera aleatoria
  //9 minas para la forma diamante
  for (int i=0;i<9;i++){
  int randX=(rand() % 9);
  int randY=(rand() % 9);
  
  if (nivel1[randX][randY]=='*'){
    i--;
  }
  else if(nivel1[randX][randY]=='0'){
  nivel1[randX][randY]='*';}
  else{
    i--;
  }
}
  for(int i=0; i<X;i++){
        for(int j=0; j<X;j++){
            char val = nivel1[i][j];
            tablero[i][j]=val;
        }
    }
//tablero1
    for(int i=0; i<=4;i++){
      for(int j=0; j<=4;j++){
        if(i+j==4||i+j==5||i+j==6||i+j==7||i+j==8) {
          tablero1[i][j]='#';
        }
        else{
          tablero1[i][j]='|';
        }
    }
  }

  for (int i=0;i<=4;i++){
    for (int j=4;j<X;j++){
      if(j<=i+4){
        tablero1[i][j]='#';
      }
      else{
        tablero1[i][j]='|';
      }
    }
  }

  for (int i=4;i<X;i++){
    for (int j=0;j<=4;j++){
      if(j>=i-4){
        tablero1[i][j]='#';
      }
      else{
        tablero1[i][j]='|';
      }
    }
  }

  for(int i=4; i<X;i++){
      for(int j=4; j<X;j++){
        if(i+j==12||i+j==11||i+j==10||i+j==9||i+j==8) {
          tablero1[i][j]='#';
        }
        else{
          tablero1[i][j]='|';
        }
    }
  }
  
  }

void NivelDiamante::print(){
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
void NivelDiamante::print() {
    cout << "  1     2     3     4     5     6     7     8     9" << endl;
    cout << "1                         " << tablero[0][4] << endl;
    cout << "                          |" << endl;
    cout << "2                   ";
    cout << tablero[1][3] << "-----" << tablero[1][4] << "-----" << tablero[1][5] << endl;
    cout << "                    |     |     |" << endl;
    cout << "3             ";
    cout << tablero[2][2] << "-----" << tablero[2][3] << "-----" << tablero[2][4] << "-----" << tablero[2][5] << "-----" << tablero[2][6] << endl;
    cout << "              |     |     |     |     |" << endl;
    cout << "4       ";
    cout << tablero[3][1] << "-----" << tablero[3][2] << "-----" << tablero[3][3] << "-----" << tablero[3][4] << "-----" << tablero[3][5] << "-----" << tablero[3][6] << "-----" << tablero[3][7] << endl;
    cout << "        |     |     |     |     |     |     |" << endl;
    cout << "5 ";
    cout << tablero[4][0] << "-----" << tablero[4][1] << "-----" << tablero[4][2] << "-----" << tablero[4][3] << "-----" << tablero[4][4] << "-----" << tablero[4][5] << "-----" << tablero[4][6] << "-----" << tablero[4][7] << "-----" << tablero[4][8] << endl;
    cout << "        |     |     |     |     |     |     |" << endl;
    cout << "6       ";
    cout << tablero[5][1] << "-----" << tablero[5][2] << "-----" << tablero[5][3] << "-----" << tablero[5][4] << "-----" << tablero[5][5] << "-----" << tablero[5][6] << "-----" << tablero[5][7] << endl;
    cout << "              |     |     |     |     |" << endl;
    cout << "7             ";
    cout << tablero[6][2] << "-----" << tablero[6][3] << "-----" << tablero[6][4] << "-----" << tablero[6][5] << "-----" << tablero[6][6] << endl;
    cout << "                    |     |     |" << endl;
    cout << "8                   ";
    cout << tablero[7][3] << "-----" << tablero[7][4] << "-----" << tablero[7][5] << endl;
    cout << "                          |" << endl;
    cout << "9                         " << tablero[8][4] << endl;
}
*/