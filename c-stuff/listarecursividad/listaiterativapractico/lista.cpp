// Estructuras de Datos y Algoritmos - Curso 2021
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// lista.c
// Lista Simple de Enteros

#include "lista.h"

#include <stdio.h>

struct nodo_lista {
    int dato;
    lista sig;
    // int cantidad;
};

lista crear() {
    // Crea la lista vacia.
    return NULL;
}

lista cons(lista l, int n) {
    // Inserta n al inicio de l.
    lista aux = new (nodo_lista);
    aux->dato = n;
    aux->sig = l;
    l = aux;
    return l;
}

lista snoc(lista l, int n) {
    // Inserta n al final de l.
    lista aux = new (nodo_lista);
    aux->dato = n;
    aux->sig = NULL; // es elemento final que tendra la lista

    if (isEmpty(l)) {
        return cons(l, n);
    } else {
        l->sig = aux;
        return snoc(tail(l), n);
    }
}

int head(lista l) {
    // Retorna el primer elemento de la lista.
    // Pre: l no vacia.
    return l->dato;
}

lista tail(lista l) {
    // Retorna el "resto" de la lista.
    // Pre: l no vacia.
    return l->sig;
}

bool isEmpty(lista l) {
    // Retorna true si l es vacia, false en caso contrario.
    return (l == NULL);
}

int cant(lista l) {
    int cantidad = 0;
    // Retorna la cantidad de elementos de l (recursiva).
    // *ITERATIVO*
    while (!isEmpty(l)) {
        cantidad++;
        l = l->sig;
    }
    return cantidad;
}

int cant_iterativa(lista l) {
    // Retorna la cantidad de elementos de l (iterativa).
    int cant = 0;
    while (l != NULL) {
        cant++;
        l = l->sig;
    }
    return cant;
}

bool pertenece(lista l, int n) {  // isElement
    // Retorna true si n pertenece a l, false en caso contrario.
    // *ITERATIVO*
    while (!isEmpty(l)) {
        if (l->dato == n) {
            return true;  // pertenece, retorna true
        } else {
            l = l->sig;  // no pertenece, sigue con el siguiente elemento
        }
    }
    return false;  // recorrió toda la lista sin encontrarlo, retorna false
}

int Max(lista l) {
    // Retorna el máximo elemento de l.
    // Pre: l no es vacía.
    // *ITERATIVO*
    int maximo = l->dato;
    while (!isEmpty(l)) {
        if (maximo < l->dato) {
            maximo = l->dato;
            l = l->sig;
        } else {
            l->sig;
        }
    }

    return maximo;
}

lista elim(lista l, int elem) {
    // En caso de que elem pertenezca a l, retorna l sin ese elemento.
    if (isEmpty(l)) {
        return l;
    } else {
        if (head(l) == elem) {
            l->dato = NULL;  // se quita el valor del elemento
            return l;  // el elemento pertence, se devuelve l sin el elemento.
        } else {
            pertenece(tail(l), elem);  // sigue buscando en el resto de la lista
        }
    }
}

lista destruir(lista l) { delete l; }
