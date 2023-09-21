#include "listade.h"

#include <stdio.h>

struct nodo_listade {
    int dato;
    listade sig;
    listade ant;
};

listade crear() {
    // Crea la lista doblemente encadenada vacia.
    return NULL;
}

listade cons(listade l, int n) {
    // Inserta n al inicio de l.

    listade aux = new (nodo_listade);
    aux->dato = n;
    aux->ant = NULL;

    if (l == NULL) {
        aux->sig = NULL;
        return aux;
    } else {
        listade current = l;

        while (current->ant != NULL) {
            current = current->ant;
        }

        current->ant = aux;
        aux->sig = current;
        return l;
    }
}

listade snoc(listade l, int n) {
    // Inserta n al final de l.

    listade aux = new (nodo_listade);
    aux->dato = n;
    aux->sig = NULL;

    if (l == NULL) {
        aux->ant = NULL;
        return aux;
    } else {
        listade current = l;

        while (current->sig != NULL) {
            current = current->sig;
        }

        current->sig = aux;
        aux->ant = current;
        return l;
    }
}

listade insOrd(listade l, int n) {
    // Inserta ordenadamente en l.
    // Pre: l ordenada.
    // Supongo de menor a mayor.

    listade aux = new (nodo_listade);
    aux->dato = n;

    if (l == NULL) {
        aux->ant = NULL;
        aux->sig = NULL;
        return aux;
    } else {
        listade inicio = l;

        // vamos al inicio de la lista.
        while (inicio->ant != NULL) {
            inicio = inicio->ant;
        }

        // empezamos a recorrer la lista desde el inicio
        while (inicio->sig != NULL) {
            if (n < inicio->dato) {
                // si n es menor al dato de la lista, lo insertamos al
                // principio.
                aux->sig = inicio;
                aux->ant = inicio->ant;
                inicio->ant = aux;
            } else {
                // como aux->dato es mayor, avanzamos al siguiente para la
                // iteración.
                inicio = inicio->sig;
            }
        }

        if (n > inicio->dato) {
            // Caso donde n fue mayor que todos.
            // Lo insertamos al final.
            inicio->sig = aux;
            aux->ant = inicio;
            aux->sig = NULL;
        }
        return l;
    }
}

int first(listade l) {
    // Retorna el primer elemento de la lista.
    // Pre: l no vacia.

    // vamos al principio de la lista.
    if (l->ant == NULL) {
        return l->dato;
    } else {
        return first(l->ant);
    }
}

int last(listade l) {
    // Retorna el ultimo elemento de la lista.
    // Pre: l no vacia.

    if (l->sig == NULL) {
        return l->dato;
    } else {
        return last(l->sig);
    }
}

int actual(listade l) {
    // Retorna el elemento "actual" de la lista.
    // Pre: l no vacia.
    return l->dato;
}

listade ant(listade l) {
    // Retorna los "anteriores" al nodo actual de la lista.
    // Pre: l no vacia.
    return l->ant;
}

listade sig(listade l) {
    // Retorna los "siguientes" al nodo actual de la lista.
    // Pre: l no vacia.
    return l->sig;
}

bool isEmpty(listade l) {
    // Retorna true si l es vacia, false en caso contrario.
    return (l == NULL);
}

int cant(listade l) {
    // Retorna la cantidad de elementos de l.

    int cantidad = 0;
    if (l != NULL) {
        // vamos al inicio
        while (l->ant != NULL) {
            l = l->ant;
        }

        while (l != NULL) {
            cantidad++;
            l = l->sig;
        }
    }

    return cantidad;
}

bool pertenece(listade l, int n) {
    // Retorna true si n pertenece a l, false en caso contrario.

    bool pertenece = false;

    if (l != NULL) {
        // vamos al inicio
        while (l->ant != NULL) {
            l = l->ant;
        }

        // recorremos desde el inicio y evaluamos
        while (l != NULL && pertenece == false) {
            if (l->dato == n) {
                pertenece = true;
            } else {
                l = l->sig;
            }
        }
    }

    return pertenece;
}

listade elim(listade l, int elem) {
    // En caso de que elem pertenezca a l, retorna l sin ese elemento.

    // TENGO UN PROBLEMA QUE VIOLO EL SEGMENTO CUANDO BORRO EL ULTIMO DE LA
    // LISTA

    if (l == NULL) {
        return l;
    } else {
        // vamos al inicio con una copia de l.
        listade current = l;
        while (current->ant != NULL) {
            current = current->ant;
        }

        // recorremos desde el inicio y eliminamos todas las ocurrencias.
        while (current != NULL) {
            if (current->dato == elem) {
                // encontramos una ocurrencia.
                listade anterior = current->ant;
                listade siguiente = current->sig;

                // si 'l' era justamente el dato a borrar, no podemos hacerlo
                // porque sino no podemos retornarla.
                if (l == current) {
                    // nos fijamos que no estuviese al principio.
                    if (anterior != NULL) {
                        // no estaba al principio, podemos asignar l como el
                        // anterior.
                        l = anterior;
                    } else {
                        // estaba al principio, podemos asignar l como el
                        // siguiente.
                        l = siguiente;
                    }
                }

                // borramos la ocurrencia y vamos al siguiente.
                delete current;
                current = siguiente;

                // para evitar violación de segmento primero veo si el elemento
                // anterior y el siguiente no son NULL
                // cuyo caso significaría que estamos en uno de los extremos de
                // la lista.

                if (anterior != NULL) {
                    // podemos ajustar punteros sin caer en violación de
                    // segmento.
                    anterior->sig = siguiente;
                }
                if (siguiente != NULL) {
                    // podemos ajustar punteros sin caer en violación de
                    // segmento.
                    siguiente->ant = anterior;
                }
            }
            current = current->sig;
        }
        return l;
    }
}

listade destruir(listade l) {
    // Destruye l y libera la memoria asociada.
}