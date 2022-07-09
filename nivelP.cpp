#include "nivelP.h"
#include <iostream>

using namespace std;

NivelP::NivelP(){
    srand(time(0));
    cout<<"Ingresa el numero de filas (mayor que 6, menor que 16): "<<endl;
    cin>>X;
    if (X<=6){X=7;}
    else if(X>=16){X=15;}
    cout<<"Ingresa el numero de columnas (mayor que 6, menor que 15): "<<endl;
    cin>>Y;
    if (Y<=6){Y=7;}
    else if(Y>=16){Y=15;}
    int n_minas;
    cout<<"Ingresa el numero de minas (mayor que 0): "<<endl;
    cin>>n_minas;
    casillas = X*Y;
    if (n_minas<=0){n_minas=1;}
    else if(n_minas>casillas){n_minas=casillas;}
    tablero=new char*[X];
    for(int i=0; i<X;i++){
        tablero[i] = new char[Y];
    }
    tablero1 = new char*[X];
    for(int i=0; i<X;i++){
        tablero1[i] = new char[Y];
    }
    //Generar matriz para nivel
    char nivel1[X][Y];
    for(int i=0; i<X;i++){
        for(int j=0; j<Y;j++){
            nivel1[i][j]='0';
        }
    }
    //Generar la posición de la mina de manera aleatoria
    for (int i=0;i<n_minas;i++){
        int randX=(rand() % X);
        int randY=(rand() % Y);
        while (nivel1[randX][randY]=='*'){
            int randX=(rand() % X);
            int randY=(rand() % Y);
        }
        nivel1[randX][randY]='*';
    }


    for(int i=0; i<X;i++){
        for(int j=0; j<Y;j++){
            char val = nivel1[i][j];
            tablero[i][j]=val;
        }
    }

    for(int i=0; i<X;i++){
        for(int j=0; j<Y;j++){
            char val = nivel1[i][j];
            tablero1[i][j]='#';
        }
    }

}

void NivelP::print(){
    cout<<"  ";
    for (int i=1;i<=Y;i++){
        if(i!=Y)
            cout<<i<<"     ";
        else
            cout<<i<<endl;
    }

    for (int i=0;i<X;i++){
        for(int j=0;j<Y;j++){
            if (j==0){
                cout<<i+1<<" "<<tablero1[i][j]<<"-----";
            }
            else if (j==Y-1){
                cout<<tablero1[i][j];
            }
            else
                cout<<tablero1[i][j]<<"-----";
        }
        cout<<endl;
        for (int k=0;k<Y;k++){
            if (i!=X-1){
                if(k==0){
                    cout<<"  "<<"|"<<"     ";}
                else if (k==Y-1){
                    cout<<"|"<<endl;
                }
                else{
                    cout<<"|"<<"     ";}
            }

        }
    }
}