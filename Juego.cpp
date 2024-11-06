#include "Juego.h"
#include <algorithm>
#include <iostream>
#include <random>
#include <chrono>

Juego::Juego(int numJugadores) {
    inicializarPool();

    // Mezclar el pool de cartas
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(poolCartas.begin(), poolCartas.end(), std::default_random_engine(seed));

    // Solicitar nombres de los jugadores e inicializarlos
    for (int i = 0; i < numJugadores; i++) {
        std::string nombre;
        std::cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
        std::cin >> nombre;
        jugadores.push_back(new Jugador(nombre));
    }

    repartirCartasIniciales();
}

void Juego::iniciar() {
    bool victoria = false;
    int turno = 0;

    while (!victoria) {
        turnoJugador(jugadores[turno]);
        victoria = verificarCondicionVictoria(jugadores[turno]);

        if (victoria) {
            std::cout << "¡" << jugadores[turno]->obtenerNombre() << " ha ganado el juego!" << std::endl;
        }
        else {
            turno = (turno + 1) % jugadores.size(); // Siguiente turno
        }
    }
}

// Ejemplo de inicialización del pool de cartas
void Juego::inicializarPool() {
    // Agregar 4 plantas de cada color
    for (int i = 0; i < 4; ++i) {
        poolCartas.push_back(new Planta("rojo"));
        poolCartas.push_back(new Planta("azul"));
        poolCartas.push_back(new Planta("amarillo"));
    }

    // Agregar hongos de cada grado
    for (int i = 0; i < 10; ++i) poolCartas.push_back(new Hongo(1));
    for (int i = 0; i < 5; ++i) poolCartas.push_back(new Hongo(2));
    for (int i = 0; i < 3; ++i) poolCartas.push_back(new Hongo(3));

    // Agregar fungicidas
    for (int i = 0; i < 3; ++i) {
        poolCartas.push_back(new Fungicida("rojo"));
        poolCartas.push_back(new Fungicida("azul"));
        poolCartas.push_back(new Fungicida("amarillo"));
    }

    // Agregar cartas de truco
    for (int i = 0; i < 6; ++i) poolCartas.push_back(new Truco("Trasplante"));
    for (int i = 0; i < 3; ++i) poolCartas.push_back(new Truco("Intercambio de jardín"));
}

// Repartición de cartas iniciales
void Juego::repartirCartasIniciales() {
    for (Jugador* jugador : jugadores) {
        for (int i = 0; i < 4; ++i) {
            jugador->agregarCarta(poolCartas.back());
            poolCartas.pop_back();
        }
    }
}

// Implementación de un turno
void Juego::turnoJugador(Jugador* jugador) {
    std::cout << "Turno de " << jugador->obtenerNombre() << std::endl;
    jugador->mostrarMano();
    jugador->mostrarJardin();

    int opcion;
    std::cout << "Seleccione la carta a jugar (1-4) o 0 para pasar: ";
    std::cin >> opcion;

    if (std::cin.fail() || opcion < 0 || opcion > jugador->obtenerMano().size()) {
        throw std::runtime_error("Selección de carta no válida.");
    }

    // Lógica de juego continúa aquí
}
catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    std::cin.clear();  // Limpia el estado de error
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
}
