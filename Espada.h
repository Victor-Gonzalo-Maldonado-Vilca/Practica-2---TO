#ifndef ESPADA_H
#define ESPADA_H

#include "Objeto.h"

class Espada : public Objeto {
private:
    int filo;

public:
    Espada(string nombre, int fuerza, int agilidad, int inteligencia, int filo)
        : Objeto(nombre, fuerza, agilidad, inteligencia), filo(filo) {}

    void setFilo(int f) { filo = f; }
    int getFilo() const { return filo; }

    double nivelPoder() const override {
        return ((agilidad + fuerza) * 1.0 / inteligencia) * filo;
    }
};

#endif

