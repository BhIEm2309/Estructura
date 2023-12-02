#ifndef ESTADOTABLERO_H
#define ESTADOTABLERO_H

#include <vector>

namespace std_connect4 {

const int ROWS = 6;
const int COLS = 7;

class EstadoTablero {
public:
    std::vector<std::vector<int>> tablero;

    EstadoTablero();

    int evaluar() const;

    bool esGanador(int jugador) const;

    bool tableroCompleto() const;

    std::vector<int> obtenerColumnasDisponibles() const;

    bool hacerMovimiento(int columna, int jugador);

private:
    int evaluarLinea(int c1, int c2, int c3, int c4) const;
};

}

#endif