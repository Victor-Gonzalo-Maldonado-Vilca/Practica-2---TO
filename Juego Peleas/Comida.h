#ifndef COMIDA_H
#define COMIDA_H

#include <string>
using namespace std;

class Comida {
private:
    string nombre;
    int energia;

public:
    Comida(string nombre, int energia) : nombre(nombre), energia(energia) {}
    string getNombre() const { return nombre; }
    int getEnergia() const { return energia; }
};

#endif

