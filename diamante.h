
#ifndef BUSCAMINAS_DIAMANTE_H
#define BUSCAMINAS_DIAMANTE_H
#include "tablero.h"

class NivelDiamante : public Tablero{
public:
    NivelDiamante();
    void print() override;
};
#endif //BUSCAMINAS_DIAMANTE_H
