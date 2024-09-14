#include <iostream>
#include <string>
#include <cstdlib>
#include "Matriz.h"


/**
 * Función que muestra los participantes del grupo
 * @param programa nombre del ejecutable
 */
void participantes(std::string programa);

/**
 * 
 * @param min Valor mínimo
 * @param max Valor máximo
 * @return un número aleatoreo entre los valores del argumento
 */
int aleatoreo(int min, int max);

/**
 * Taller computacional
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * @return El código de salida del programa
 */
int main(int argc, char** argv) {
    srand(time(0));
    /**
     * Incluir acá la lógica del programa
     * 
     */
    if (argc > 1) {
        int largo = std::stoi(argv[1]);

        Matriz magica(largo);

        for (int fila = 0; fila < largo; fila++) {
            for (int columna = 0; columna < largo; columna++) {
                int valor = aleatoreo(1, 99);
                magica.SetValor(fila, columna, valor);
            }
        }

        magica.imprimir();
        std::cout << std::endl << "La matriz es magica " << magica.esMagica() << std::endl;


    } else {
        // Mostrar los integrantes
        participantes(argv[0]);
    }
    return EXIT_SUCCESS;
}

void participantes(std::string programa) {
    std::cout << std::endl << "=== Programa de ejemplo " << programa << " ===" << std::endl;
    std::cout << std::endl << "Sebastián Salazar Molina"; // Reemplazar por su nombre
    std::cout << std::endl << "14/09/2024 :: Sólo uso académico." << std::endl; // Reemplazar por su nombre
}

int aleatoreo(int min, int max) {
    return (rand() % (max - min + 1)) +min;
}
