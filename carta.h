#ifndef CARTA_H
#define CARTA_H

#include <string>  

class Carta {
public:
    Carta(const std::string& tipo);
    virtual std::string obtenerColor() const = 0;
    virtual void mostrar() const = 0;

protected:
    std::string tipo;
};

#endif // CARTA_H
