#ifndef ARCO_H
#define ARCO_H

#include "Objeto.h"

class Arco : public Objeto {
private:
    int precision;

public:
    Arco(string nombre, int fuerza, int agilidad, int inteligencia, int precision)
        : Objeto(nombre, fuerza, agilidad, inteligencia), precision(precision) {}

    void setPrecision(int p) { precision = p; }
    int getPrecision() const { return precision; }

    double nivelPoder() const override {
        return ((agilidad * 2 + inteligencia) * 1.0 / fuerza) * precision;
    }
};

#endif

