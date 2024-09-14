#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <iomanip>
#include <omp.h>

class Matriz {
public:
    /**
     * Este constructor necesita un valor impar mayor que cero.
     * @param largo Indica el tamaño de la matriz
     */
    Matriz(int largo);

    /**
     * Asigna a nuestra matriz los valores referenciados por la matriz del argumento.
     * @param orig Matriz de copia
     */
    Matriz(const Matriz& orig);

    /**
     * Destructor que libera la memoria usada por la matriz.
     */
    virtual ~Matriz();

    /**
     * Imprime nuestra matriz en pantalla
     */
    void imprimir() const;

    /**
     * 
     * @return el tamaño de la matriz
     */
    int GetLargo() const;

    /**
     * 
     * @param fila Fila a buscar
     * @param columna Columna a buscar
     * @param valor Valor a modificar
     */
    void SetValor(int fila, int columna, int valor);

    /**
     * 
     * @param fila Fila a buscar
     * @param columna Columna a buscar
     * @return el valor de la posición indicada
     */
    int GetValor(int fila, int columna) const;

    /**
     * 
     * @return true si la matriz es mágica o false en cualquier otro caso
     */
    bool esMagicaSecuencial() const;
    
    /**
     * 
     * @return true si la matriz es mágica o false en cualquier otro caso
     */
    bool esMagicaOpenMP() const;
    
    /**
     * 
     * @return true si la matriz es mágica o false en cualquier otro caso
     */
    bool esMagicaMPI() const;
private:
    int** datos;
    int largo;
};

#endif /* MATRIZ_H */

