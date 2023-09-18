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

    // cambiamos punteros
    if (l == NULL) {
        // sólo si la lista es vacía, el único elemento
        //  de la lista quedará apuntando a si mismo.
        aux->sig = aux;
        // retornamos aux ya que la lista vino vacía.
        l = aux;
    } else {
        aux->sig = l;           // lo apunta al primero
        listacirc current = l;  // copia de 'l' para recorrer
        // recorremos la lista hasta llegar al anterior al inicio.
        while (current->sig != l) {
            current = current->sig;
        }
        current->sig = aux;  // último elemento apuntará a aux.
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
    listacirc current = l;
    while (current->sig != l) {
        current = current->sig;
    }

    current->sig = l->sig;  // último elemento apunta al segundo elemento.
    l = l->sig;
    return l;  // Devuelve el "resto" de la lista.
}

bool isEmpty(listacirc l) {
    // Retorna true si l es vacia, false en caso contrario.
    return (l == NULL);
}

int cant(listacirc l) {
    // Retorna la cantidad de elementos de l.
    int cantidad = 0;
    // si 'l' tiene elementos los contaremos.
    while (l != NULL) {
        cantidad++;
        l = tail(l);
    }

    return cantidad;
}

bool pertenece(listacirc l, int n) {
    // Retorna true si n pertenece a l, false en caso contrario.
    bool pertenece = false;
    // si 'l' tiene elementos los contaremos.
    while (l != NULL && pertenece == false) {
        if (l->dato == n) {
            pertenece = true;
        }
        l = tail(l);
    }

    return pertenece;
}

listacirc destruir(listacirc l) {
    // Destruye l y libera la memoria asociada.
    delete &l;
    return l;
}