#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include "Jugador.h"

class Juego {
public:
    Juego(int numeroJugadores, const std::vector<std::string>& nombres);
    void iniciar();

private:
    int numeroJugadores;
    std::vector<Jugador*> jugadores;
    std::vector<Carta*> poolCartas;

    void inicializarPoolCartas();
    void repartirCartas();
    void turnoJugador(Jugador* jugador);
    bool verificarCondicionVictoria();
};

#endif // JUEGO_H
