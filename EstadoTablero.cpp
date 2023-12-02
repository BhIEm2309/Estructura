#include "EstadoTablero.h"

namespace std_connect4 {
    
EstadoTablero::EstadoTablero() : tablero(ROWS, std::vector<int>(COLS, 0)) {
}
int EstadoTablero::evaluarLinea(int c1, int c2, int c3, int c4) const {
    int puntuacion = 0;

    if (c1 == 1) puntuacion++;
    if (c2 == 1) puntuacion++;
    if (c3 == 1) puntuacion++;
    if (c4 == 1) puntuacion++;

    if (c1 == 2) puntuacion--;
    if (c2 == 2) puntuacion--;
    if (c3 == 2) puntuacion--;
    if (c4 == 2) puntuacion--;

    return puntuacion;
}

int EstadoTablero::evaluar() const {
    int evaluacion = 0;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS - 3; ++j) {
            evaluacion += evaluarLinea(tablero[i][j], tablero[i][j + 1], tablero[i][j + 2], tablero[i][j + 3]);
        }
    }

    for (int i = 0; i < ROWS - 3; ++i) {
        for (int j = 0; j < COLS; ++j) {
            evaluacion += evaluarLinea(tablero[i][j], tablero[i + 1][j], tablero[i + 2][j], tablero[i + 3][j]);
        }
    }

    for (int i = 0; i < ROWS - 3; ++i) {
        for (int j = 0; j < COLS - 3; ++j) {
            evaluacion += evaluarLinea(tablero[i][j], tablero[i + 1][j + 1], tablero[i + 2][j + 2], tablero[i + 3][j + 3]);
        }
    }

    for (int i = 0; i < ROWS - 3; ++i) {
        for (int j = 3; j < COLS; ++j) {
            evaluacion += evaluarLinea(tablero[i][j], tablero[i + 1][j - 1], tablero[i + 2][j - 2], tablero[i + 3][j - 3]);
        }
    }

    return evaluacion;
}

bool EstadoTablero::esGanador(int jugador) const {
    for (int i = 3; i < ROWS; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            if (tablero[i][j] == jugador &&
                tablero[i][j + 1] == jugador &&
                tablero[i][j + 2] == jugador &&
                tablero[i][j + 3] == jugador) {
                return true;
            }
        }
    }

    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (tablero[i][j] == jugador &&
                tablero[i + 1][j] == jugador &&
                tablero[i + 2][j] == jugador &&
                tablero[i + 3][j] == jugador) {
                return true;
            }
        }
    }

    for (int i = 3; i < ROWS; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            if (tablero[i][j] == jugador &&
                tablero[i - 1][j + 1] == jugador &&
                tablero[i - 2][j + 2] == jugador &&
                tablero[i - 3][j + 3] == jugador) {
                return true;
            }
        }
    }

    for (int i = 0; i <= ROWS - 4; ++i) {
        for (int j = 0; j <= COLS - 4; ++j) {
            if (tablero[i][j] == jugador &&
                tablero[i + 1][j + 1] == jugador &&
                tablero[i + 2][j + 2] == jugador &&
                tablero[i + 3][j + 3] == jugador) {
                return true;
            }
        }
    }

    return false;
}

bool EstadoTablero::tableroCompleto() const {
    for (int j = 0; j < COLS; ++j) {
        if (tablero[0][j] == 0) {
            return false;
        }
    }
    return true;
}

std::vector<int> EstadoTablero::obtenerColumnasDisponibles() const {
    std::vector<int> columnasDisponibles;
    for (int j = 0; j < COLS; ++j) {
        if (tablero[0][j] == 0) {
            columnasDisponibles.push_back(j);
        }
    }
    return columnasDisponibles;
}

bool EstadoTablero::hacerMovimiento(int columna, int jugador) {
    if (tablero[0][columna] != 0) {
        return false;
    }

    int fila = ROWS - 1;
    while (fila >= 0 && tablero[fila][columna] != 0) {
        --fila;
    }

    if (fila >= 0) {
        tablero[fila][columna] = jugador;
        return true;
    } else {
        return false;
    }
}

}
