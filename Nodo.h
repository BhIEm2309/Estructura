#ifndef NODO_H
#define NODO_H

#include "EstadoTablero.h"

namespace std_connect4 {

class Nodo {
public:
    EstadoTablero estado;
    int valor;

    Nodo(const EstadoTablero& estado);

    int minimax(int profundidad, int alfa, int beta, bool esMaximizador);
};

}

#endif
