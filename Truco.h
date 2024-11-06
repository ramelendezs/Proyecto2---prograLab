#ifndef TRUCO_H
#define TRUCO_H

#include "Carta.h"
#include <string>

class Truco : public Carta {
public:
    Truco(const std::string& efecto);
    std::string obtenerEfecto() const override;
    void mostrar() const override;

private:
    std::string efecto;  // Puede ser "Trasplantar" o "Intercambio de jardín"
};

#endif // TRUCO_H
