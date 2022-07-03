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
    while(tablero -> es_posible_elegir()){
        cout<<"\n"<<"Casillas restantes: "<<tablero->get_casillas()<<"\n";
        int x,y;
        cout<<"\n";
        cout<<"Ingrese la casilla que quiere buscar(fila, columna): ";
        cin>>x>>y;
        cout<<"\n";
        bool select = tablero ->elegir_casilla(x-1,y-1);
        if(!select){
            cout<<"La casilla no se puede elegir"<<endl;
        }
        bool mina = tablero ->casilla_mina(x-1,y-1);
        if(mina){
            cout<<"Perdiste :(";
            break;
        }
        tablero -> print();

    }
    if(tablero->gano()){
        cout<<"!Felicidades, ha completado el juego"<<endl;
    } else {
        return 0;
    }
    return 0;
}