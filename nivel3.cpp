#include "nivel3.h"
#include <iostream>

using namespace std;
Nivel3::Nivel3(){
  srand(time(0));
    casillas = 144;
    X=12;
    Y=12;
    tablero=new char*[12];
    for(int i=0; i<12;i++){
        tablero[i] = new char[12];
    }
  tablero1 = new char*[12];
  for(int i=0; i<12;i++){
        tablero1[i] = new char[12];
    }
  //Generar matriz para nivel
  char nivel1[12][12];
  for(int i=0; i<X;i++){
        for(int j=0; j<X;j++){
          nivel1[i][j]='0';
        }
    }
  //Generar la posición de la mina de manera aleatoria
  for (int i=0;i<12;i++){
    int randX=(rand() % 12);
    int randY=(rand() % 12);
    while (nivel1[randX][randY]=='*'){
      int randX=(rand() % 12);
      int randY=(rand() % 12);
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
            char val = nivel1[i][j];
            tablero1[i][j]='#';
        }
    }
  
}



void Nivel3::print(){
    cout << "   1     2     3     4     5     6     7     8     9    10    11    12" << endl;
    cout << "1  ";
    for(int i=0;i<12;i++){
      cout<<tablero1[0][i];
      if(i!=11){cout<<"-----";}
      
    }
    cout<<endl;
    cout << "   |     |     |     |     |     |     |     |     |     |     |     |" << endl;
    cout << "2  ";
     for(int i=0;i<12;i++){
      cout<<tablero1[1][i];
      if(i!=11){cout<<"-----";}   
    }
    cout<<endl;
    cout << "   |     |     |     |     |     |     |     |     |     |     |     |" << endl;
    cout << "3  ";
    for(int i=0;i<12;i++){
      cout<<tablero1[2][i];
      if(i!=11){cout<<"-----";} 
    }
    cout<<endl;
    cout << "   |     |     |     |     |     |     |     |     |     |     |     |" << endl;
    cout << "4  ";
    for(int i=0;i<12;i++){
      cout<<tablero1[3][i];
      if(i!=11){cout<<"-----";} 
    }
    cout<<endl;
    cout << "   |     |     |     |     |     |     |     |     |     |     |     |" << endl;
    cout << "5  ";
     for(int i=0;i<12;i++){
      cout<<tablero1[4][i];
      if(i!=11){cout<<"-----";}      
    }
    cout<<endl;
    cout << "   |     |     |     |     |     |     |     |     |     |     |     |" << endl;
    cout << "6  ";
     for(int i=0;i<12;i++){
      cout<<tablero1[5][i];
      if(i!=11){cout<<"-----";}  
    }
    cout<<endl;
    cout << "   |     |     |     |     |     |     |     |     |     |     |     |" << endl;
    cout << "7  ";
    for(int i=0;i<12;i++){
      cout<<tablero1[6][i];
      if(i!=11){cout<<"-----";} 
    }
    cout<<endl;
    cout << "   |     |     |     |     |     |     |     |     |     |     |     |" << endl;
    cout << "8  ";
     for(int i=0;i<12;i++){
      cout<<tablero1[7][i];
      if(i!=11){cout<<"-----";}  
    }
    cout<<endl;
    cout << "   |     |     |     |     |     |     |     |     |     |     |     |" << endl;
    cout << "9  ";
    for(int i=0;i<12;i++){
      cout<<tablero1[8][i];
      if(i!=11){cout<<"-----";} 
    }
    cout<<endl;
    cout << "   |     |     |     |     |     |     |     |     |     |     |     |" << endl;
    cout << "10 ";
    for(int i=0;i<12;i++){
      cout<<tablero1[9][i];
      if(i!=11){cout<<"-----";} 
    }
    cout<<endl;
    cout << "   |     |     |     |     |     |     |     |     |     |     |     |" << endl;
    cout << "11 ";
     for(int i=0;i<12;i++){
      cout<<tablero1[10][i];
      if(i!=11){cout<<"-----";}  
    }
    cout<<endl;
    cout << "   |     |     |     |     |     |     |     |     |     |     |     |" << endl;
    cout << "12 ";
     for(int i=0;i<12;i++){
      cout<<tablero1[11][i];
      if(i!=11){cout<<"-----";}  
    }
    

}



/*
void Nivel3::print(){
    cout << "  1     2     3     4     5     6     7     8     9     10     11     12" << endl;
    cout << "1 ";
    cout << tablero1[0][0] <<"-----" << tablero1[0][1] << "-----" << tablero1[0][2] << "-----" << tablero1[0][3] << "-----" << tablero1[0][4] << "-----"<<tablero1[0][5]<<"-----" <<tablero1[0][6]<<"-----" <<tablero[0][7]<<"-----" <<tablero[0][8]<<"-----" <<tablero[0][9]<<"-----" <<tablero[0][10]<<"-----"<<tablero[0][11]<< endl;
    cout << "  |     |     |     |     |     |     |     |     |     |     |     |" << endl;
    cout << "2 ";
    cout << tablero1[1][0]<<"-----" <<tablero1[1][1] << "-----" << tablero1[1][2] << "-----" << tablero1[1][3] << "-----" << tablero1[1][4] << "-----" << tablero1[1][5] << endl;
    cout << "  |     |     |     |     |     |     |     |     |     |     |     |" << endl;
    cout << "3 ";
    cout << tablero1[2][0] << "-----" << tablero1[2][1] << "-----" << tablero1[2][2] << "-----" << tablero1[2][3] << "-----" << tablero1[2][4] << "-----" << tablero1[2][5] << endl;
    cout << "  |     |     |     |     |     |     |     |     |     |     |     |" << endl;
    cout << "4 ";
    cout << tablero1[3][0] << "-----" << tablero1[3][1] << "-----" << tablero1[3][2] << "-----" << tablero1[3][3] << "-----" << tablero1[3][4] << "-----" << tablero1[3][5] <<  endl;
    cout << "  |     |     |     |     |     |     |     |     |     |     |     |" << endl;
    cout << "5 ";
    cout << tablero1[4][0] << "-----" << tablero1[4][1] << "-----" << tablero1[4][2] << "-----" << tablero1[4][3] << "-----" << tablero1[4][4] << "-----" << tablero1[4][5] <<   endl;
    cout << "  |     |     |     |     |     |     |     |     |     |     |     |     |" << endl;
    cout << "6 ";
    cout <<tablero1[5][0] << "-----" << tablero1[5][1] << "-----" << tablero1[5][2] << "-----" << tablero1[5][3] << "-----" << tablero1[5][4] << "-----" << tablero1[5][5] << endl;

}

*/