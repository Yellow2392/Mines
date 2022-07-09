
#ifndef BUSCAMINAS_REGISTROS_H
#define BUSCAMINAS_REGISTROS_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "heap.h"
void registro(string jugador){
    //Se debe leer el archivo primero para verificar que el
    //el nombre no haya estado antes
    ifstream archivoOp("scores.txt");
    string line;
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
        ifstream archivo("scores.txt");
        string line1;
        int score;
        vector <string> data;
        while (getline(archivo,line1)){
            auto found = line1.find(jugador);
            if (found!=std::string::npos){
                string temp="";
                bool flag1=0;
                for (int i=0;i<line1.size();i++){
                    if (line1[i]==','){
                        flag1=1;
                    }
                    if (flag1==1){
                        temp=temp+line1[i];
                    }
                }
                temp.erase(temp.begin());
                score=stoi(temp);
            }
            else{
                data.push_back(line1);
            }

        }
        archivo.close();
        score=score+1;
        //Abre el archivo en modo de escritura para actualizarlo
        ofstream archivoEd("scores.txt");
        archivoEd<<jugador<<","<<to_string(score)<<endl;
        for (auto &c:data){
            archivoEd<<c<<endl;
        }
        archivoEd.close();
    }
        //Si no lo encuentra, registrara el nombre
    else{
        ofstream archivo("scores.txt",fstream::app);
        archivo<<jugador<<",1"<<endl;
        archivo.close();
    }

}

void escribir(double m){
    ofstream archivo("movimientos.txt",fstream::app);
    archivo<<m<<endl;
    archivo.close();
}

void mostrar_puntajes(){

    string filename("movimientos.txt");
    string line;
    heap<double> h1;
    double num;
    ifstream input_file(filename);
    while (getline(input_file, line)){

        num=stod(line);
        h1.push(num);
    }

    int posicion=1;
    for(int i=0;i<5;i++){
        cout<< posicion<<".     "<<h1.top()<<" seg"<<endl;
        h1.pop();
        posicion ++;
    }
    input_file.close();

}
#endif //BUSCAMINAS_REGISTROS_H
