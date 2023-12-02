#include "Nodo.h"
#include <climits>

namespace std_connect4 {

Nodo::Nodo(const EstadoTablero& estado) : estado(estado), valor(0) {}

int Nodo::minimax(int profundidad, int alfa, int beta, bool esMaximizador) {
    if (profundidad == 0 || estado.esGanador(1) || estado.esGanador(2) || estado.tableroCompleto()) {
        return estado.evaluar();
    }

    std::vector<int> columnasDisponibles = estado.obtenerColumnasDisponibles();

    if (esMaximizador) {
        int maxEval = INT_MIN;
        for (int columna : columnasDisponibles) {
            EstadoTablero nuevoEstado = estado;
            if (nuevoEstado.hacerMovimiento(columna, 1)) {
                Nodo hijo(nuevoEstado);
                int eval = hijo.minimax(profundidad - 1, alfa, beta, false);
                maxEval = std::max(maxEval, eval);
                alfa = std::max(alfa, eval);
                if (beta <= alfa)
                    break;  // Poda alfa-beta
            }
        }
        return maxEval;
    } else {
        int minEval = INT_MAX;
        for (int columna : columnasDisponibles) {
            EstadoTablero nuevoEstado = estado;
            if (nuevoEstado.hacerMovimiento(columna, 2)) {
                Nodo hijo(nuevoEstado);
                int eval = hijo.minimax(profundidad - 1, alfa, beta, true);
                minEval = std::min(minEval, eval);
                beta = std::min(beta, eval);
                if (beta <= alfa)
                    break;  // Poda alfa-beta
            }
        }
        return minEval;
    }
}

}
