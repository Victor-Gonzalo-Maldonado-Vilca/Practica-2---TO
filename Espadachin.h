#ifndef ESPADACHIN_H
#define ESPADACHIN_H

#include "Personaje.h"
#include "Espada.h"

class Espadachin : public Personaje {
private:
    int tecnicaEspada;
public:
    Espadachin(string nombre, char genero, int edad, double altura, double peso, int tecnicaEspada)
        : Personaje(nombre, genero, edad, altura, peso, ESPADACHIN), tecnicaEspada(tecnicaEspada) {
        agregarObjeto(new Espada("Espada Basica", 15, 10, 8, 10));
    }

    void ataqueEspada() {
        if (!estado) { cout << nombre << " esta muerto.\n"; return; }
        if (stamina < 8) { cout << nombre << " no tiene suficiente stamina.\n"; return; }
        cout << nombre << " realiza un ataque con espada (tecnica: " << tecnicaEspada << ")\n";
        stamina -= 8;
    }
};

#endif

