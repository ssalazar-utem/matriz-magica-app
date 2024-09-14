#include "Matriz.h"

Matriz::Matriz(int largo) {
    if (largo < 3 || largo % 2 == 0) {
        // caso triste
        this->largo = 0;
        std::cerr << "Es necesario un valor entero positivo impar" << std::endl;
    } else {
        this->largo = largo;
        // Asignar la memoria dinámica
        this->datos = new int*[largo];
        for (int fila = 0; fila < largo; fila++) {
            datos[fila] = new int[largo]();
        }
    }
}

Matriz::Matriz(const Matriz& orig) {
    this->largo = orig.largo;
    this->datos = orig.datos;
}

Matriz::~Matriz() {
    for (int fila = 0; fila < largo; fila++) {
        delete[] datos[fila];
    }
    delete[] datos;
}

void Matriz::imprimir() const {
    if (largo > 0) {
        for (int fila = 0; fila < largo; fila++) {
            for (int columna = 0; columna < largo; columna++) {
                std::cout << std::setfill('0') << std::setw(2) << datos[fila][columna] << " ";
            }
            std::cout << std::endl;
        }
    }
}

int Matriz::GetLargo() const {
    return largo;
}

void Matriz::SetValor(int fila, int columna, int valor) {
    if (fila < largo && columna < largo) {
        this->datos[fila][columna] = valor;
    }
}

int Matriz::GetValor(int fila, int columna) const {
    int valor = -99;
    if (fila < largo && columna < largo) {
        valor = datos[fila][columna];
    }
    return valor;
}

bool Matriz::esMagica() const {
    if (largo <= 0) {
        return false;
    }

    // Esta variable nos ayudará con los calculos
    int sumaMagica = 0;
    // Revisamos la suma de la primera fila (vamos de columna en columna)
#pragma omp parallel for reduction (+:sumaMagica)
    for (int columna = 0; columna < largo; columna++) {
        sumaMagica += datos[0][columna];
    }

    bool filaValida = true;
    // verificamos por fila (excluyendo la primera (0)
#pragma omp parallel for
    for (int fila = 1; fila < largo; fila++) {
        if (filaValida) {
            int sumaXfila = 0;
            for (int columna = 0; columna < largo; columna++) {
                sumaXfila += datos[fila][columna];
            }

            if (sumaXfila != sumaMagica) {
#pragma omp atomic write
                filaValida = false;
            }
        }
    }
    // Si en paralelo se dermina inválido. Termina
    if (!filaValida) {
        return false;
    }


    bool columnaValida = true;
    // verificamos por columna
#pragma omp parallel for
    for (int columna = 0; columna < largo; columna++) {
        if (columnaValida) {
            int sumaXcolumna = 0;
            for (int fila = 0; fila < largo; fila++) {
                sumaXcolumna += datos[fila][columna];
            }

            if (sumaXcolumna != sumaMagica) {
#pragma omp atomic write
                columnaValida = false;
            }
        }
    }

    if (!columnaValida) {
        return false;
    }

    // Verificamos la diagonal principal
    int sumaXdiagonalPrincipal = 0;
#pragma omp parallel for reduction (+:sumaXdiagonalPrincipal)
    for (int principal = 0; principal < largo; principal++) {
        sumaXdiagonalPrincipal += datos[principal][principal];
    }

    if (sumaXdiagonalPrincipal != sumaMagica) {
        return false;
    }

    // Verificamos la diagonal secundaria
    int sumaXdiagonalSecundaria = 0;
#pragma omp parallel for reduction (+:sumaXdiagonalSecundaria)
    for (int secundaria = 0; secundaria < largo; secundaria++) {
        sumaXdiagonalSecundaria += datos[secundaria][largo - secundaria - 1];
    }

    if (sumaXdiagonalSecundaria != sumaMagica) {
        return false;
    }

    return true;
}
