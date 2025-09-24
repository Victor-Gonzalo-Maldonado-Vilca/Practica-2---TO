#ifndef ESCUDERO_H
#define ESCUDERO_H

#include "Personaje.h"
#include "Escudo.h"

class Escudero : public Personaje {
private:
    int resistencia;
public:
    Escudero(string nombre, char genero, int edad, double altura, double peso, int resistencia)
        : Personaje(nombre, genero, edad, altura, peso, ESCUDERO), resistencia(resistencia) {
        agregarObjeto(new Escudo("Escudo Basico", 12, 8, 10, 15));
    }

    void bloquear() {
        if (!estado) { cout << nombre << " esta muerto.\n"; return; }
        if (stamina < 3) { cout << nombre << " no tiene suficiente stamina.\n"; return; }
        cout << nombre << " se defiende con su escudo (resistencia: " << resistencia << ")\n";
        stamina -= 3;
    }
};

#endif

