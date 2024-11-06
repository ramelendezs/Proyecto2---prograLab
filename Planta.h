#ifndef PLANTA_H
#define PLANTA_H

#include "Carta.h"
#include <string>

class Planta : public Carta {
public:
    Planta(const std::string& color);
    std::string obtenerColor() const override;
    void mostrar() const override;

private:
    std::string color;
};

#endif // PLANTA_H
