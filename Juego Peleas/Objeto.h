#ifndef OBJETO_H
#define OBJETO_H

#include <iostream>
#include <string>
using namespace std;

class Objeto {
protected:
    int fuerza;
    int agilidad;
    int inteligencia;

private:
    string nombre;

public:
    Objeto(string nombre, int fuerza, int agilidad, int inteligencia)
        : nombre(nombre), fuerza(fuerza), agilidad(agilidad), inteligencia(inteligencia) {}

    virtual ~Objeto() {}

    void setNombre(string n) { nombre = n; }
    string getNombre() const { return nombre; }

    void setFuerza(int f) { fuerza = f; }
    int getFuerza() const { return fuerza; }

    void setAgilidad(int a) { agilidad = a; }
    int getAgilidad() const { return agilidad; }

    void setInteligencia(int i) { inteligencia = i; }
    int getInteligencia() const { return inteligencia; }

    virtual double nivelPoder() const { return (agilidad + fuerza) * 1.0 / inteligencia; }

    virtual void mostrarObjeto() const {
        cout << "Nombre: " << nombre << " - Nivel Poder: " << nivelPoder() << endl;
    }
};

#endif

