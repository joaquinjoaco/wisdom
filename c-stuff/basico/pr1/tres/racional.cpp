#include "racional.h"

#include <iostream>

using namespace std;

struct nodo_racional {
    int num;
    int den;
};

// Crea un racional (pide memoria).
racional crear() {
    racional aux = new (nodo_racional);
    return aux;
}

// Setea el nominador del racional
racional setNumerador(racional r, int a) {
    r->num = a;
    return r;
}

// Setea el denominador
racional setDenominador(racional r, int b) {
    r->den = b;
    return r;
}

// Retorna el numerador de r.
int getNumerador(racional r) { return r->num; }

// Retorna el denominador de r.
int getDenominador(racional r) { return r->den; }

// Suma de dos racionales
racional suma(racional r1, racional r2) {
    racional aux = crear();
    aux->num = r1->num * r2->den + r2->num * r1->den;
    aux->den = r1->den * r2->den;

    return aux;
}

// Diferencia de dos racionales
racional diferencia(racional r1, racional r2) {
    racional aux = crear();
    aux->num = r1->num * r2->den - r2->num * r1->den;
    aux->den = r1->den * r2->den;

    return aux;
}

// Producto de dos racionales
racional producto(racional r1, racional r2) {
    racional aux = crear();
    aux->num = r1->num * r2->num;
    aux->den = r1->den * r2->den;
    return aux;
}

// Cociente de dos racionales
racional cociente(racional r1, racional r2) {
    racional aux = crear();
    aux->num = r1->num * r2->den;
    aux->den = r1->den * r2->num;

    return aux;
}

// Igualdad de dos racionales
void igualdad(racional r1, racional r2) {
    if (r1->num == r2->num && r1->den == r2->den) {
        cout << "son iguales.";
    } else {
        cout << "son distintos.";
    }
}

// TODO
//  MCD del numerador y el denominador
//  racional mcd(racional r) {}

// Forma normal del racional
// racional formaNormal(racional r) {}

// Imprime el racional
void imprimir(racional r) { cout << r->num << "/" << r->den; }

// Destruye un racional y libera la memoria asociada.
void destruir(racional &r) { delete r; }