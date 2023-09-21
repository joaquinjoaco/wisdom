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

// listacirc tailTroll(listacirc l) {
// Retorna el "resto" de la lista circular.
// Pre: l no vacia.

// Si la lista tiene un solo elemento, libera la memoria y devolvemos NULL.
// if (l->sig == l) {
//     delete l;
//     return NULL;
// }

// Encuentra el último elemento de la lista.
// listacirc current = l;
// while (current->sig != l) {
//     current = current->sig;
// }

// current->sig = l->sig;  // último elemento apunta al segundo elemento.
// l = l->sig;
// return l;  // Devuelve el "resto" de la lista.
// }

listacirc tail(listacirc l) {
    // Retorna el "resto" de la lista circular.
    // Pre: l no vacia.
    return l->sig;
}

bool isEmpty(listacirc l) {
    // Retorna true si l es vacia, false en caso contrario.
    return (l == NULL);
}

int cant(listacirc l) {
    // Retorna la cantidad de elementos de l.

    int cantidad = 0;

    if (!isEmpty(l)) {
        // contamos el primer elemento
        cantidad++;

        // contamos el resto
        listacirc current = tail(l);

        while (current != l) {
            cantidad++;
            current = tail(current);
        }
    }

    return cantidad;
}

bool pertenece(listacirc l, int n) {
    // Retorna true si n pertenece a l, false en caso contrario.
    bool pertenece = false;
    listacirc current = tail(l);
    if (l->dato == n) {
        pertenece = true;
    }
    // si 'l' tiene elementos los recorremos.
    while (current != l && pertenece == false) {
        if (current->dato == n) {
            pertenece = true;
        }
        current = tail(current);
    }

    return pertenece;
}

listacirc elim(listacirc l, int elem) {
    // En caso de que elem pertenezca a l, retorna l sin ese elemento.

    if (l == NULL) {
        // La lista está vacía, no hay nada que borrar.
        return l;
    }

    // Manejo especial para el primer elemento
    if (head(l) == elem) {
        listacirc temp = l;

        if (l->sig == l) {
            // Si solo hay un elemento en la lista, liberamos la memoria y devolvemos NULL.
            delete l;
            return NULL;
        } else {
            // Si hay más de un elemento, actualizamos el inicio de la lista y el último nodo.
            listacirc ultimo = l;
            while (ultimo->sig != l) {
                ultimo = ultimo->sig;
            }
            l = l->sig;
            ultimo->sig = l;
            delete temp;
        }
    } else {
        listacirc current = l;
        bool borrado = false;

        while (borrado == false) {
            if (head(current) == elem) {
                // Encontramos elem
                listacirc ultimo = l;
                while (ultimo->sig != current) {
                    ultimo = ultimo->sig;
                }

                // Apuntamos el nodo anterior al siguiente del nodo a borrar
                ultimo->sig = current->sig;
                delete current;
                borrado = true;
            } else {
                // Avanzamos al siguiente nodo en la lista
                current = current->sig;
            }
        }
    }

    return l;
}

listacirc destruir(listacirc l) {
    // Destruye l y libera la memoria asociada.
    delete l;
    return l;
}