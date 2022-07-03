#include <iostream>
#include "tablero.h"
#include "nivel1.h"

using namespace std;

int main() {
int result;
    do{
        cout<<endl<<"Menu - Juego Buscaminas"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"1. Nivel1 = Principiante"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"0. Salir del Juego"<<endl;
        cin>>result;
        cout<<"\n";
    } while (result >= 2 or result <0);
    if(result == 0){cout<<"Gracias por jugar!"; return 0;}
    Tablero* tablero=nullptr;
    switch(result){
        case 1:
            tablero = new Nivel1();
            break;
    }
    tablero ->print();
    bool fail=false;
    while(tablero -> es_posible_elegir()){
        cout<<"\n"<<"Casillas restantes: "<<tablero->get_casillas()<<"\n";
        int x,y;
        cout<<"\n";

      //Funcion de banderas va aqui
      cout<<"Quiere colocar banderas?"<<endl;
      cout<<"1. Si | 2. No"<<endl;
      int r;
      cin>>r;
      while (r!=1 && r!=2){
        cout<<"Quiere colocar banderas?"<<endl;
        cout<<"1. Si | 2. No"<<endl;
        cin>>r;
      }
      if (r==1){
        cout<<"Ingrese la casilla donde la quiere colocar (fila, columna): ";
        int x1,y1;
        cin>>x1>>y1;
        cout<<endl;
        tablero->colocarBandera(x1,y1);
      }
      //End de la funcion
        cout<<"Ingrese la casilla que quiere buscar(fila, columna): ";
        cin>>x>>y;
        cout<<"\n";
        bool select = tablero ->elegir_casilla(x-1,y-1);
        if(!select){
            cout<<"La casilla no se puede elegir"<<endl;
        }
        bool mina = tablero ->casilla_mina(x-1,y-1);
        if(mina){
            cout<<"Perdiste :("<<endl;
            fail=true;
            break;
        }
        tablero -> print();

    }
    if(tablero->gano(fail)){
        cout<<"!Felicidades, ha completado el juego"<<endl;
    } else {
        return 0;
    }
    return 0;
}