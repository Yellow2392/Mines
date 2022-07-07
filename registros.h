#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "heap.h"
#ifndef PROYECTOFINAL_REGISTROS_H
#define PROYECTOFINAL_REGISTROS_H

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

void escribir(int m){
    ofstream archivo("movimientos.txt",fstream::app);
    archivo<<m<<endl;
    archivo.close();
}

void mostrar_puntajes(){

    string filename("movimientos.txt");
    string line;
    heap<int> h1;
    int num;
    ifstream input_file(filename);
    while (getline(input_file, line)){
        num=stoi(line);
        h1.push(num);
    }

    int posicion=1;
    for(int i=0;i<5;i++){
        cout<< posicion<<".      "<<h1.top()<<"     "<<endl;
        h1.pop();
        posicion ++;
    }

    input_file.close();


}

#endif //PROYECTOFINAL_REGISTROS_H
