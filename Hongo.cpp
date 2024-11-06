#include "Hongo.h"
#include <iostream>

Hongo::Hongo(int grado) : Carta("Hongo"), grado(grado) {}

int Hongo::obtenerGrado() const {
    return grado;
}

void Hongo::mostrar() const {
    std::cout << "Hongo de grado " << grado << std::endl;
}
