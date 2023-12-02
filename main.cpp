#include "EstadoTablero.h"
#include "Nodo.h"
#include <iostream>
#include <vector>
#include <climits>

using namespace std_connect4;

int realizarMovimientoConMinimax(const EstadoTablero& estado, int profundidad) {
    std::vector<int> columnasDisponibles = estado.obtenerColumnasDisponibles();
    int mejorMovimiento = -1;
    int mejorValor = INT_MIN;

    for (int columna : columnasDisponibles) {
        EstadoTablero nuevoEstado = estado;
        if (nuevoEstado.hacerMovimiento(columna, 1)) {
            Nodo nodoHijo(nuevoEstado);
            int valor = nodoHijo.minimax(profundidad - 1, INT_MIN, INT_MAX, false);
            if (valor > mejorValor) {
                mejorValor = valor;
                mejorMovimiento = columna;
            }
        }
    }

    return mejorMovimiento;
}

void imprimirTablero(const EstadoTablero& estado) {
    const auto& tablero = estado.tablero;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (tablero[i][j] == 0) {
                std::cout << "- ";
            } else if (tablero[i][j] == 1) {
                std::cout << "X ";
            } else {
                std::cout << "O ";
            }
            
        }
        std::cout << std::endl;
    }
    std::cout << "-------------"<<std::endl;
    std::cout << "1 2 3 4 5 6 7";
    std::cout << std::endl;
}

int main() {
    EstadoTablero estadoInicial;

    int dificultad;
    std::cout << "Selecciona la dificultad:" << std::endl;
    std::cout << "1. Fácil" << std::endl;
    std::cout << "2. Moderado" << std::endl;
    std::cout << "3. Difícil" << std::endl;
    std::cout << "Ingrese el número correspondiente a la dificultad: ";
    std::cin >> dificultad;

    int profundidad;
    switch (dificultad) {
        case 1:
            profundidad = 3;
            break;
        case 2:
            profundidad = 5;
            break;
        case 3:
            profundidad = 7;
            break;
        default:
            profundidad = 5;
    }

    imprimirTablero(estadoInicial);
    // Bucle principal
    while (!estadoInicial.tableroCompleto() && !estadoInicial.esGanador(1) && !estadoInicial.esGanador(2)) {
        

        int columnaJugador;
        std::cout << "Turno del jugador (O). Ingresa la columna (1-7): ";
        std::cin >> columnaJugador;

        while ((columnaJugador-1) < 0 || columnaJugador >= COLS || estadoInicial.tablero[0][columnaJugador-1] != 0) {
            std::cout << "Movimiento inválido. Ingresa una columna válida: ";
            std::cin >> columnaJugador;
        }

        estadoInicial.hacerMovimiento((columnaJugador-1), 2);
        imprimirTablero(estadoInicial);


        if (estadoInicial.esGanador(2)) {
            std::cout << "¡Felicidades! ¡Has ganado!" << std::endl;
            break;
        }


        int columnaMaquina = realizarMovimientoConMinimax(estadoInicial, profundidad);
        std::cout << "Turno de la máquina (X). La máquina elige la columna " << columnaMaquina+1 << std::endl;

        estadoInicial.hacerMovimiento(columnaMaquina, 1);
        imprimirTablero(estadoInicial);

        if (estadoInicial.esGanador(1)) {
            std::cout << "¡La máquina ha ganado!" << std::endl;
            break;
        }
    }

    if (estadoInicial.tableroCompleto() && !estadoInicial.esGanador(1) && !estadoInicial.esGanador(2)) {
        std::cout << "El juego ha terminado en empate." << std::endl;
    }

    return 0;
}
