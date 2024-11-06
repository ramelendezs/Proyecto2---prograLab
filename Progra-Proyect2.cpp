// Progra-Proyect2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Juego.h"
#include <iostream>
#include "Carta.h" 

int main() {
    int numJugadores;
    std::cout << "Ingrese la cantidad de jugadores (2-4): ";
    std::cin >> numJugadores;

    if (numJugadores < 2 || numJugadores > 4) {
        std::cerr << "Número de jugadores inválido." << std::endl;
        return 1;
    }

    std::vector<std::string> nombres;
    for (int i = 0; i < numJugadores; ++i) {
        std::string nombre;
        std::cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
        std::cin >> nombre;
        nombres.push_back(nombre);
    }

    Juego juego(numJugadores, nombres);
    juego.iniciar();

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
