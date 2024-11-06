#ifndef JUGADOR_H
#define JUGADOR_H

#include <vector>
#include <string>
#include "Carta.h"
#include "Planta.h"

class Jugador {
    std::string nombre;
    std::vector<Carta*> mano;    // Cartas en mano
    std::vector<Planta*> jardin; // Plantas en el jardín
public:
    Jugador(const std::string& nombre) : nombre(nombre) {}
    ~Jugador();
    void agregarCarta(Carta* carta);
    void mostrarMano() const;
    void mostrarJardin() const;
    bool tieneTresPlantasDeColoresDiferentes() const;
    std::string obtenerNombre() const { return nombre; }
    Carta* obtenerCartaDeMano(int indice) { return mano[indice]; }
    void eliminarCartaDeMano(int indice);
};

#endif
