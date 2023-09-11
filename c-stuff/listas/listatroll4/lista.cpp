#include "lista.h"

#include <stdio.h>

struct nodo_lista {
    int dato;
    lista sig;
};

lista null() {
    // Crea la lista vacia.
    return NULL;
}

lista cons(int x, lista l) {
    // Inserta n al inicio de l.
    lista aux = new (nodo_lista);
    aux->dato = x;
    aux->sig = l;
    l = aux;
    return l;
}

bool isEmpty(lista l) {
    // Retorna true si l es vacia, false en caso contrario.
    // *ya es "iterativo"*
    return (l == NULL);
}

int head(lista l) {
    // Retorna el primer elemento de la lista.
    // Pre: l no vacia.
    // *ya es "iterativo"*
    return l->dato;
}

lista tail(lista l) {
    // Retorna el "resto" de la lista.
    // Pre: l no vacia.
    // *ya es "iterativo"*
    return l->sig;
}

lista destruir(lista l) {
    delete l;
    return l;
}

bool IsElement(int x, lista l) {
    // Retorna true si x pertenece a l, false en caso contrario.

    if (isEmpty(l)) {  // Caso base: si la lista está vacía, x no está en la lista.
        return false;
    } else if (head(l) == x) {  // Si el primer elemento de la lista es igual a x, retornar true.
        return true;
    } else {
        return IsElement(x, tail(l));  // Llamada recursiva para verificar el resto de la lista.
    }
}

lista Remove(int x, lista l) {
    // Retorna la lista fruto de eliminar x en l.
    // l no comparte memoria con la lista resultado.

    if (isEmpty(l)) {
        // Caso base: si la lista está vacía, no hay nada que eliminar.
        return null();

    } else if (head(l) == x) {
        // Si el primer elemento de la lista es igual a 'x', lo salteamos y continuamos con el resto de la lista.
        return Remove(x, tail(l));

    } else {
        // Insertamos los datos a la nueva lista del stack *y no se invierte, holy shit* (por el stack)
        return cons(head(l), Remove(x, tail(l)));
    }
}

int Length(lista l) {
    // Retorna la cantidad de elementos de la lista.

    if (isEmpty(l)) {
        return 0;
    }

    return 1 + Length(tail(l));
}
