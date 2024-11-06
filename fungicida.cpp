#include "Fungicida.h"
#include <iostream>

Fungicida::Fungicida(const std::string& color) : Carta("Fungicida"), color(color) {}

std::string Fungicida::obtenerColor() const {
    return color;
}

void Fungicida::mostrar() const {
    std::cout << "Fungicida de color " << color << std::endl;
}
