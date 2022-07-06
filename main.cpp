#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "tablero.h"
#include "nivel1.h"
#include "nivel2.h"
#include "nivel3.h"
#include "cruz.h"
#include "diamante.h"

using namespace std;

void registro(int n, string jugador){
  //Se debe leer el archivo primero para verificar que el
  //el nombre no haya estado antes
  ifstream archivoOp("scores.txt");
  string line,line1;
  bool flag=false;
  while (getline(archivoOp, line)) {
    auto found = line.find(jugador);
    if (found!=std::string::npos){
      flag=true;
      break;
    }
}
  archivoOp.close();
  //Si se encontro el nombre del jugador, actualizara
  //el contador de victorias
  if (flag==true){
    fstream archivo("scores.txt",fstream::app);
    string line1;
    while (!archivo.eof()){
      std::getline(archivo,line1);
      auto found = line1.find(jugador);
      if (found!=std::string::npos){
        //Error esta aca. No agrega elementos al vector
        vector <string> words;
        istringstream iss(line1);
        do
        {
            string subs;
            iss >> subs;
            words.push_back(subs);
        } while (iss);
        words.pop_back();
        for (auto &c:words){
          cout<<c<<endl;
        }
        int new_n = stoi(words[1]);
        new_n=new_n+n;
        string Sn=to_string(new_n);
      line1.replace(line1.find(words[1]),words[1].length(),Sn);
      }
      
    }
    archivo.close();
  }
  //Si no lo encuentra, registrara el nombre
  else{
    ofstream archivo("scores.txt",fstream::app);
    archivo<<jugador<<" "<<n<<endl;
    archivo.close();
  }
  
}

int main() {
    int result;
    int selec;
    do{
        cout<<endl<<"Menu - Juego Buscaminas"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"1. Nivel1 = Principiante"<<endl;
        cout<<"2. Nivel2 = Intermedio"<<endl;
        cout<<"3. Nivel3 = Avanzado"<<endl;
        cout<<"4. Perzonalizar nivel"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"0. Salir del Juego"<<endl;
        cin>>result;
        cout<<"\n";
    } while (result >= 5 or result <0);
    if(result == 0){cout<<"Gracias por jugar!"; return 0;}
    Tablero* tablero=nullptr;
    switch(result){
        case 1:
            tablero = new Nivel1();
            break;
        case 2:
            tablero = new Nivel2();
            break;
        case 3:
            tablero = new Nivel3();
            break;
        case 4: 
              do{
                  cout<<endl<<"Menu - Perzonalizado"<<endl;
                  cout<<"--------------------------------"<<endl;
                  cout<<"1. Perzonalizar Tamaño"<<endl;
                  cout<<"2. Nivel Cruz"<<endl;
                  cout<<"3. Nivel Diamante"<<endl;
                  cout<<"--------------------------------"<<endl;
                  cout<<"0. Salir del Juego"<<endl;
                  cin>>selec;
                  cout<<"\n";
              } while (selec >= 4 or result <0);
              if(selec==0){cout<<"Gracias por jugar!"; return 0;}
              switch(selec){
                  case 1:
                      cout<<"Escogio nivel perzonalizable!"<<endl;
                      break;
                  case 2:
                      tablero = new NivelCruz();
                      break;
                  case 3:
                      tablero = new NivelDiamante();
                      break;
                 }             
    cout<<"Ingrese su nombre (No debe contener espacios): ";
    string jugador;
    int victoria=0;
    cin>>jugador;
    //Agregar condicion para los espacios
    cout<<endl;
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
        tablero -> print();
        cout<<endl;
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
      victoria++;
      //Registro del jugador y su victoria
      registro(victoria,jugador);
      
    } else {
        return 0;
    }
    return 0;
}
  }
