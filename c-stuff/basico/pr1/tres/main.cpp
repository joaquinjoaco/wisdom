#include <iostream>

#include "racional.h"

using namespace std;

int main() {
    racional r1, r2, sumaR, diferenciaR, productoR, cocienteR;

    // ---------Creacion----------

    r1 = crear();
    r2 = crear();

    r1 = setNumerador(r1, 8);
    r1 = setDenominador(r1, 3);

    r2 = setNumerador(r2, 1);
    r2 = setDenominador(r2, 2);
    // ---------------------------

    // --------Operaciones--------
    sumaR = suma(r1, r2);
    diferenciaR = diferencia(r1, r2);
    productoR = producto(r1, r2);
    cocienteR = cociente(r1, r2);

    // ---------------------------

    // --Impresiones en pantalla--
    cout << "Racional 1: ";
    imprimir(r1);
    cout << endl;

    cout << "Racional 2: ";
    imprimir(r2);
    cout << endl;

    // Igualdad
    cout << "r1 y r2 ";
    igualdad(r1, r2);
    cout << endl;

    // Suma
    cout << "r1 + r2 = ";
    imprimir(sumaR);
    cout << endl;

    // Diferencia
    cout << "r1 - r2 = ";
    imprimir(diferenciaR);
    cout << endl;

    // Producto
    cout << "r1 * r2 = ";
    imprimir(productoR);
    cout << endl;

    // Cociente
    cout << "r1 / r2 = ";
    imprimir(cocienteR);
    cout << endl;

    // -------------------------

    // -------destruccion-------
    destruir(r1);
    destruir(r2);
    destruir(sumaR);
    destruir(diferenciaR);
    destruir(productoR);
    destruir(cocienteR);

    // -------------------------

    return 0;
}