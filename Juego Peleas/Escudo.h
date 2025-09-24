#ifndef ESCUDO_H
#define ESCUDO_H

#include "Objeto.h"

class Escudo : public Objeto {
private:
    int nivelDefensa;

public:
    Escudo(string nombre, int fuerza, int agilidad, int inteligencia, int nd)
        : Objeto(nombre, fuerza, agilidad, inteligencia), nivelDefensa(nd) {}

    void setNivelDefensa(int nd) { nivelDefensa = nd; }
    int getNivelDefensa() const { return nivelDefensa; }

    double nivelPoder() const override {
        return ((agilidad + fuerza) * 1.0 / inteligencia) + nivelDefensa;
    }
};

#endif

