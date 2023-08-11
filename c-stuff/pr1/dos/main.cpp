#include <iostream>

#include "punto.h"

using namespace std;

int main() {
    punto p1, p2, suma, diferencia;
    int largo;

    p1 = crear();
    p2 = crear();

    p1 = setAbscisa(p1, 2);
    p1 = setOrdenada(p1, 5);

    p2 = setAbscisa(p2, 1);
    p2 = setOrdenada(p2, 1);

    suma = sumaV(p1, p2);
    diferencia = diferenciaV(p1, p2);
    largo = largo_segmento(p1, p2);

    cout << "Punto 1: ";
    imprimir(p1);
    cout << endl;

    cout << "Punto 2: ";
    imprimir(p2);
    cout << endl;

    cout << "Suma vectorial: ";
    imprimir(suma);
    cout << endl;

    cout << "Diferencia vectorial: ";
    imprimir(diferencia);
    cout << endl;

    cout << "Largo del segmento: ";
    cout << largo;
    cout << endl;

    destruir(p1);
    destruir(p2);
    destruir(suma);
    destruir(diferencia);

    return 0;
}