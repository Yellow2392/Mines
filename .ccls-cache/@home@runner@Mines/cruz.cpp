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
            tablero1[i][j]='#';
          }
          else if(i==X/2 || i==X/2+1 || i == X/2-1 ){
            tablero1[i][j]='#';
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
