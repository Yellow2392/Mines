
#ifndef BUSCAMINAS_TABLERO_H
#define BUSCAMINAS_TABLERO_H
#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <cstdlib>


bool isValidPos(int i, int j, int X, int Y);


class Tablero {
protected:
    int casillas = 0;
    char **tablero = nullptr;
    char **tablero1 = nullptr;
    int X = 0, Y = 0;
    void elegir(int x, int y);
    void elegir2(int x, int y);
public:
    Tablero(){};
    ~Tablero();
    int get_casillas(){return casillas;}
    bool elegir_casilla(int x, int y);
    virtual void print()=0;
    bool casilla_mina(int x,int y);
    bool gano(bool f);
    bool es_posible_elegir();
    void colocarBandera(int x, int y);
    void asignar_a_valorCercano(int x, int y);
};

#endif //BUSCAMINAS_TABLERO_H
