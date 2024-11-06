#ifndef FUNGICIDA_H
#define FUNGICIDA_H

#include "Carta.h"
#include <string>

class Fungicida : public Carta {
public:
    Fungicida(const std::string& color); // Constructor
    std::string obtenerColor() const override; // Implementación de obtenerColor
    void mostrar() const override; // Implementación de mostrar

private:
    std::string color; // Miembro para almacenar el color
};

#endif // FUNGICIDA_H
