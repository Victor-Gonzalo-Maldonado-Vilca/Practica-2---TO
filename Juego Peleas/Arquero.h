#ifndef ARQUERO_H
#define ARQUERO_H

#include "Personaje.h"
#include "Arco.h"
#include <iostream>
using namespace std;

class Arquero : public Personaje {
private:
    int precision;
public:
    Arquero(string nombre, char genero, int edad, double altura, double peso, int precision)
        : Personaje(nombre, genero, edad, altura, peso, ARQUERO), precision(precision) {
        agregarObjeto(new Arco("Arco Basico", 5, 15, 12, 8));
    }

    int getPrecision() const { return precision; }
    void setPrecision(int p) { precision = p; }

    void dispararFlecha() {
        if (!estado) { 
            cout << nombre << " esta muerto.\n"; 
            return; 
        }
        if (stamina < 5) { 
            cout << nombre << " no tiene suficiente stamina.\n"; 
            return; 
        }
        cout << nombre << " dispara una flecha con precision " << precision << endl;
        stamina -= 5;
    }
};

#endif

