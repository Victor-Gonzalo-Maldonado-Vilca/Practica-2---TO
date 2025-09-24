#include <iostream>
#include "Arquero.h"
#include "Espadachin.h"
#include "Escudero.h"
#include "Comida.h"

using namespace std;

int main() {
    Arquero* robin = new Arquero("Robin Hood", 'M', 25, 1.75, 70, 15);
    Espadachin* arturo = new Espadachin("Rey Arturo", 'M', 30, 1.80, 80, 18);
    Escudero* lancelot = new Escudero("Lancelot", 'M', 28, 1.78, 75, 20);

    cout << "=== PERSONAJES CREADOS ===" << endl;
    robin->mostrarPersonaje();
    cout << "Poder total: " << robin->getPoder() << endl << endl;

    arturo->mostrarPersonaje();
    cout << "Poder total: " << arturo->getPoder() << endl << endl;

    lancelot->mostrarPersonaje();
    cout << "Poder total: " << lancelot->getPoder() << endl << endl;

    cout << "=== SISTEMA DE VENTAJAS ===" << endl;
    cout << "Arquero > Escudero > Espadachin > Arquero" << endl << endl;

    cout << "--- Arquero vs Escudero ---" << endl;
    robin->peleaPersonaje(lancelot);
    cout << endl;

    robin->setStamina(100);
    arturo->setStamina(100);

    cout << "--- Espadachin vs Arquero ---" << endl;
    arturo->peleaPersonaje(robin);
    cout << endl;

    cout << "=== HABILIDADES ESPECIALES ===" << endl;
    robin->dispararFlecha();
    arturo->ataqueEspada();
    lancelot->bloquear();
    cout << endl;

    // Liberar memoria
    delete robin;
    delete arturo;
    delete lancelot;

    return 0;
}

