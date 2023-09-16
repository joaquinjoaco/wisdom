#include "punto.h"

#include <math.h>

#include <iostream>

using namespace std;

struct nodo_punto {
    int x;
    int y;
};

// Crea un punto
punto crear() {
    punto nuevoPto = new (nodo_punto);
    return nuevoPto;
};

// Setea la componente horizontal del punto
punto setAbscisa(punto pto, int x) {
    pto->x = x;
    return pto;
}

// Setea la componente horizontal del punto
punto setOrdenada(punto pto, int y) {
    pto->y = y;
    return pto;
}

// Suma vectorial de dos puntos
punto sumaV(punto pto1, punto pto2) {
    punto aux = new (nodo_punto);
    aux->x = pto1->x + pto2->x;
    aux->y = pto1->y + pto2->y;

    return aux;
}

// Diferencia entre dos puntos
punto diferenciaV(punto pto1, punto pto2) {
    punto aux = new (nodo_punto);
    aux->x = pto1->x - pto2->x;
    aux->y = pto1->y - pto2->y;

    return aux;
}

// Largo del segmento
float largo_segmento(punto pto1, punto pto2) {
    float largo;
    punto diferencia = new (nodo_punto);
    diferencia = diferenciaV(pto1, pto2);

    largo = sqrt((diferencia->x * diferencia->x) + (diferencia->y * diferencia->y));

    return largo;
}

// Imprime un punto
void imprimir(punto p) {
    cout << "(" << p->x << "/" << p->y << ")";
}

// Libera la memoria donde se encuentra guardado un punto
void destruir(punto &pto) {
    delete pto;
}

// todo: largo del segmento, origen
