#include "listacirc.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <iostream>

using namespace std;

struct nodo_listacirc {
    int dato;
    listacirc sig;
};

listacirc crear() {
    // Crea la lista circular vacia.
    return NULL;
}

listacirc copy(listacirc l) {
    // Crea una nueva lista a partir de la que recibe.

    listacirc copia = crear();
    listacirc reversedCopia = crear();

    if (l != NULL) {
        listacirc inicio = l;
        // insertamos el primer dato de 'l' en la copia.
        copia = cons(copia, l->dato);
        l = l->sig;
        // insertamos los datos de 'l' en la copia.
        while (l != inicio) {
            copia = cons(copia, l->dato);
            l = l->sig;
        }

        listacirc inicioCopia = copia;
        // insertamos el primer dato de 'l' en la copia.
        reversedCopia = cons(reversedCopia, copia->dato);
        copia = copia->sig;
        // invertimos la copia de la misma manera que copiamos la primera vez.
        while (copia != inicioCopia) {
            reversedCopia = cons(reversedCopia, copia->dato);
            copia = copia->sig;
        }
    }

    return reversedCopia;
}

listacirc cons(listacirc l, int n) {
    // Inserta n al inicio de l.

    listacirc aux = new (nodo_listacirc);
    aux->dato = n;

    if (l != NULL) {
        aux->sig = l;  // lo pone al principio
        listacirc inicio = l;
        // recorremos la lista hasta llegar al anterior al inicio.
        while (l->sig != inicio) {
            l = l->sig;
        }
        l->sig = aux;  // último elemento apuntará a aux.
    } else {
        // sólo si la lista es vacía, el único elemento
        //  de la lista quedará apuntando a si mismo.
        aux->sig = aux;
    }

    return aux;
}

listacirc snoc(listacirc l, int n) {
    // Inserta n al final de l.

    listacirc aux = new (nodo_listacirc);
    aux->dato = n;

    if (l != NULL) {
        aux->sig = l;  // lo pone al principio
        listacirc inicio = l;
        // recorremos la lista hasta llegar al anterior al inicio.
        while (l->sig != inicio) {
            l = l->sig;
        }
        l->sig = aux;  // último elemento apuntará a aux.
    } else {
        // sólo si la lista es vacía, el único elemento
        //  de la lista quedará apuntando a si mismo.
        aux->sig = aux;
    }

    return l;
}

int head(listacirc l) {
    // Retorna el primer elemento de la lista circular.
    // Pre: l no vacia.

    return l->dato;
}

listacirc tail(listacirc l) {
    // Retorna el "resto" de la lista circular.
    // Pre: l no vacia.

    // Si la lista tiene un solo elemento, libera la memoria y devuelve NULL.
    if (l->sig == l) {
        delete l;
        return NULL;
    }

    // Encuentra el último elemento de la lista.
    listacirc ultimo = l;
    while (ultimo->sig != l) {
        ultimo = ultimo->sig;
    }

    // Ajusta los punteros para que el último elemento apunte al segundo elemento.
    ultimo->sig = l->sig;

    // Libera la memoria del primer elemento.
    listacirc primer_elemento = l;
    l = l->sig;  // Avanza al segundo elemento.
    delete primer_elemento;

    return l;  // Devuelve el "resto" de la lista.
}

bool isEmpty(listacirc l) {
    // Retorna true si l es vacia, false en caso contrario.
    return (l == NULL);
}

int cant(listacirc l) {
    // Retorna la cantidad de elementos de l.
    int cantidad = 0;
    if (l != NULL) {
        // si 'l' tiene elementos los contaremos.
        while (l != NULL) {
            cantidad++;
            l = tail(l);
        }
    }

    return cantidad;
}

listacirc destruir(listacirc l) {
    // Destruye l y libera la memoria asociada.
    delete l;
    return l;
}