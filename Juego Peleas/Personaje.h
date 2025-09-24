#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include <vector>
#include "Objeto.h"
#include "Comida.h"

using namespace std;

enum TipoPersonaje { ESPADACHIN, ESCUDERO, ARQUERO };

class Personaje {
protected:
    string nombre;
    char genero;
    int edad;
    double altura;
    double peso;
    vector<Objeto*> inventario;
    double poder;
    int stamina;
    bool estado;
    int vida;
    TipoPersonaje tipo;

public:
    Personaje(string nombre, char genero, int edad, double altura, double peso, TipoPersonaje tipo)
        : nombre(nombre), genero(genero), edad(edad), altura(altura), peso(peso),
          poder(0), stamina(100), estado(true), vida(100), tipo(tipo) {}

    virtual ~Personaje() {
        for (Objeto* obj : inventario) delete obj;
        inventario.clear();
    }

    string getNombre() const { return nombre; }
    char getGenero() const { return genero; }
    int getEdad() const { return edad; }
    double getAltura() const { return altura; }
    double getPeso() const { return peso; }
    double getPoder() const { return poder; }
    int getStamina() const { return stamina; }
    bool getEstado() const { return estado; }
    int getVida() const { return vida; }
    TipoPersonaje getTipo() const { return tipo; }

    void setStamina(int s) { stamina = s; }
    void setVida(int v) { vida = v; }
    void setNombre(string n) { nombre = n; }
    void setGenero(char g) { genero = g; }
    void setEdad(int e) { edad = e; }
    void setAltura(double a) { altura = a; }
    void setPeso(double p) { peso = p; }

    void agregarObjeto(Objeto* n) {
        inventario.push_back(n);
        poder += n->nivelPoder();
    }

    virtual void peleaPersonaje(Personaje* oponente) {
        double multiplicador = 1.0;

        // Lógica de ventaja/desventaja según tipo
        if (tipo == ESPADACHIN && oponente->getTipo() == ARQUERO) multiplicador = 1.5;
        else if (tipo == ESPADACHIN && oponente->getTipo() == ESCUDERO) multiplicador = 0.7;
        else if (tipo == ESCUDERO && oponente->getTipo() == ESPADACHIN) multiplicador = 1.5;
        else if (tipo == ESCUDERO && oponente->getTipo() == ARQUERO) multiplicador = 0.7;
        else if (tipo == ARQUERO && oponente->getTipo() == ESCUDERO) multiplicador = 1.5;
        else if (tipo == ARQUERO && oponente->getTipo() == ESPADACHIN) multiplicador = 0.7;

        double poderEfectivo = poder * multiplicador;
        double poderOponente = oponente->getPoder();

        if (poderEfectivo > poderOponente) {
            cout << "Gano: " << nombre << endl;
            stamina -= 10;
            oponente->setStamina(oponente->getStamina() - 30);
        } else if (poderEfectivo < poderOponente) {
            cout << "Gano: " << oponente->getNombre() << endl;
            stamina -= 30;
            oponente->setStamina(oponente->getStamina() - 10);
        } else {
            cout << "Empate entre " << nombre << " y " << oponente->getNombre() << endl;
            stamina -= 20;
            oponente->setStamina(oponente->getStamina() - 20);
        }

        if (stamina < 0) stamina = 0;
        if (oponente->getStamina() < 0) oponente->setStamina(0);

        cout << nombre << " -> Stamina: " << stamina << endl;
        cout << oponente->getNombre() << " -> Stamina: " << oponente->getStamina() << endl;

        morir();
        oponente->morir();
    }

    void comer(Comida* c) {
        if (!estado) {
            cout << "El personaje " << nombre << " está muerto y no puede comer." << endl;
            return;
        }
        stamina += c->getEnergia();
        if (stamina > 100) stamina = 100;
        cout << nombre << " comió " << c->getNombre() << " y recuperó "
             << c->getEnergia() << " de stamina. Stamina actual: " << stamina << endl;
    }

    void mostrarPersonaje() const {
        cout << "Nombre: " << nombre << " - Edad: " << edad
             << " - Genero: " << genero << " - Altura: " << altura
             << " - Peso: " << peso << endl;
        cout << "\tObjetos" << endl;
        for (Objeto* i : inventario) i->mostrarObjeto();
    }

    void morir() {
        if (stamina <= 0 || vida <= 0) {
            estado = false;
            cout << "El personaje " << nombre << " ha muerto" << endl;
        }
    }
};

#endif

