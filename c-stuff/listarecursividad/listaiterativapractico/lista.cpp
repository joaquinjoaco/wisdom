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
    // *ya es "iterativo"*
    return NULL;
}

lista cons(lista l, int n) {
    // Inserta n al inicio de l.
    // *ya es "iterativo"*
    lista aux = new (nodo_lista);
    aux->dato = n;
    aux->sig = l;
    l = aux;
    return l;
}

lista snoc(lista l, int n) {
    // *ITERATIVO* (sin usar procedimientos auxiliares)
    // Inserta n al final de l.

    if (isEmpty(l)) {
        l = cons(l, n);  // inserta uno al principio si es vacía
    } else {
        lista current = l;
        // estoy haciendo un puntero a "l" con el que voy a poder enlazar un
        // nuevo nodo al final de "l"
        while (!isEmpty(current->sig)) {
            current = current->sig;  // avanza hasta el ultimo nodo
        }

        current->sig =
            cons(current->sig, n);  // en la ultima posición añade un nuevo nodo
    }
    return l;  // retorna "l" modificada con el nuevo nodo al final

    // sin procedimientos auxiliares
    // if (l == NULL) {
    //     lista aux = new (nodo_lista);
    //     aux->dato = n;
    //     aux->sig = NULL;
    //     l = aux;

    // } else {
    //     lista current = l;

    //     while (current->sig != NULL) {
    //         current = current->sig;
    //     }

    //     lista aux = new (nodo_lista);
    //     current->sig = aux; // se inserta un nuevo nodo al final de "l"
    //     (current es puntero de l) aux->dato = n; aux->sig = NULL;
    // }

    // return l;
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

bool isEmpty(lista l) {
    // Retorna true si l es vacia, false en caso contrario.
    // *ya es "iterativo"*
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
        if (maximo <= l->dato) {
            maximo = l->dato;
            l = l->sig;
        } else {
            l = l->sig;
        }
    }
    return maximo;
}

float Average(lista l) {
    // Retorna si la lista no es vacía el promedio de sus elementos.
    // Pre: l no es vacía.
    // *ITERATIVO*
    float avg;
    int cantidad = cant(l);

    while (!isEmpty(l)) {
        avg += l->dato;
        l = l->sig;
    }
    return avg / cantidad;
}

lista elim(lista l, int elem) {
    // *ITERATIVO*
    // En caso de que elem pertenezca a l, retorna l sin ese elemento.

    lista current = l;
    lista prev = NULL;
    while (current->dato != elem &&
           current != NULL) {    // si el usuario elige el primer elemento, entonces no entrara al while
        prev = current;          // guardo el previo
        current = current->sig;  // avanzo en la lista
    }

    if (current->dato == elem) {
        if (prev == NULL) {    // Si el previo es NULL es porque no entró al while, entonces estamos para borrar el primero
            l = current->sig;  // hacemos un tail de la lista, la dejamos sin el primero
        } else {
            prev->sig = current->sig;  // el previo ahora es el del siguiente al que borraremos.
        }
    }

    delete current;  // se borra el elemento
    return l;
}

lista destruir(lista l) {
    delete l;
}

lista Insert(int x, lista l) {
    // Inserta ordenadamente el elemento x en la lista ordenada l.
}

bool Equals(lista l, lista p) {
    // Verifica si las listas l y p son iguales (mismos elementos en el mismo orden).

    // fuaa sandra
}
