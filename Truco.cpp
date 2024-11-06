#include "Truco.h"
#include <iostream>

Truco::Truco(const std::string& efecto) : Carta("Truco"), efecto(efecto) {}

std::string Truco::obtenerEfecto() const {
    return efecto;
}

void Truco::mostrar() const {
    std::cout << "Truco: " << efecto << std::endl;
}
