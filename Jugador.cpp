#include "Jugador.h"
#include <iostream>

Jugador::~Jugador() {
    for (Carta* carta : mano) delete carta;
    for (Planta* planta : jardin) delete planta;
}

void Jugador::agregarCarta(Carta* carta) {
    mano.push_back(carta);
}

void Jugador::mostrarMano() const {
    std::cout << "Mano de " << nombre << ":" << std::endl;
    for (size_t i = 0; i < mano.size(); ++i) {
        std::cout << i + 1 << ". ";
        mano[i]->mostrar();
    }
}

void Jugador::mostrarJardin() const {
    std::cout << "Jardín de " << nombre << ":" << std::endl;
    if (jardin.empty()) {
        std::cout << "Vacio" << std::endl;
        return;
    }
    for (const Planta* planta : jardin) {
        planta->mostrar();
    }
}

bool Jugador::tieneTresPlantasDeColoresDiferentes() const {
    bool tieneRojo = false, tieneAzul = false, tieneAmarillo = false;
    for (const Planta* planta : jardin) {
        if (planta->obtenerColor() == "rojo") tieneRojo = true;
        if (planta->obtenerColor() == "azul") tieneAzul = true;
        if (planta->obtenerColor() == "amarillo") tieneAmarillo = true;
    }
    return tieneRojo && tieneAzul && tieneAmarillo;
}

void Jugador::eliminarCartaDeMano(int indice) {
    delete mano[indice];
    mano.erase(mano.begin() + indice);
}

void Jugador::agregarPlantaAlJardin(Planta* planta) {
    if (jardin.size() < 5) {
        jardin.push_back(planta);
    }
    else {
        std::cout << "El jardín está lleno. No se puede agregar más plantas." << std::endl;
    }
}

Planta* Jugador::obtenerPlantaEnJardin(int indice) const {
    if (indice < jardin.size()) return jardin[indice];
    return nullptr;
}

void Jugador::eliminarPlantaDelJardin(int indice) {
    if (indice < jardin.size()) {
        delete jardin[indice];
        jardin.erase(jardin.begin() + indice);
    }
}
