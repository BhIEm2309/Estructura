Resumen de la Implementación:
-Esta implementación proporciona un juego de Cuatro en Línea con un oponente controlado por la inteligencia artificial utilizando el algoritmo Minimax con poda alfa-beta. El juego se juega en un tablero estándar de Cuatro en Línea, donde dos jugadores se turnan para soltar sus fichas en columnas. El primer jugador que conecta cuatro de sus fichas en vertical, horizontal o diagonal gana.

Componentes:
-EstadoTablero: Representa el estado del tablero del juego. Incluye funciones para realizar un movimiento, verificar un ganador y evaluar el estado actual.

-Nodo: Representa un nodo en el árbol de juego para el algoritmo Minimax. Incluye la función minimax, que explora de forma recursiva los movimientos posibles para determinar el movimiento óptimo para el jugador controlado por la IA.

-main.cpp: Implementa el bucle del juego, los movimientos de los jugadores y la IA. Proporciona opciones para jugar el juego con distintas dificultades en donde se configura la profundidad del algoritmo Minimax.

Decisiones de Diseño:
-Representación del Tablero:
El tablero de juego se representa como una matriz 2D, donde cada celda contiene la ficha de un jugador (1 o 2) o está vacía (0). La clase EstadoTablero maneja el estado del tablero y la lógica del juego.

Algoritmo Minimax:
-Se utiliza el algoritmo minimax para explorar el árbol de juego y determinar el movimiento óptimo para el jugador controlado por la IA. La técnica de poda alfa-beta se implementa para reducir la cantidad de nodos explorados, mejorando la eficiencia del algoritmo reduciendo tiempos de ejecucion.

Ejecutar el Juego
-Compile el programa usando el comando g++ proporcionado:
g++ -o main main.cpp EstadoTablero.cpp Nodo.cpp

Ejecute el ejecutable:
./main

Siga las instrucciones en pantalla para jugar el juego.

Resultados de las Pruebas:
-El juego se probó con diferentes escenarios para comparar el rendimiento del algoritmo Minimax con y sin poda alfa-beta. Los resultados mostraron una mejora significativa en la velocidad de toma de decisiones de la IA cuando se aplicó la poda alfa-beta, especialmente en escenarios de búsqueda más profunda.
