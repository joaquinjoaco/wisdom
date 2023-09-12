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

bool isElement(int x, lista l) {
    // Retorna true si x pertenece a l, false en caso contrario.

    if (isEmpty(l)) {  // Caso base: si la lista está vacía, x no está en la lista.
        return false;
    } else if (head(l) == x) {  // Si el primer elemento de la lista es igual a x, retornar true.
        return true;
    } else {
        return isElement(x, tail(l));  // Llamada recursiva para verificar el resto de la lista.
    }
}

lista remove(int x, lista l) {
    // Retorna la lista fruto de eliminar x en l.
    // l no comparte memoria con la lista resultado.

    if (isEmpty(l)) {
        // Caso base: si la lista está vacía, no hay nada que eliminar.
        return null();

    } else if (head(l) == x) {
        // Si el primer elemento de la lista es igual a 'x', lo salteamos y continuamos con el resto de la lista.
        return remove(x, tail(l));

    } else {
        // Insertamos los datos a la nueva lista del stack *y no se invierte, holy shit* (por el stack)
        return cons(head(l), remove(x, tail(l)));
    }
}

int length(lista l) {
    // Retorna la cantidad de elementos de la lista.
    if (isEmpty(l)) {
        return 0;
    }

    return 1 + length(tail(l));
}

lista snoc(int x, lista l) {
    // Retorna la lista fruto de insertar el elemento x al final de la lista l.
    // l no comparte memoria con la lista resultado.

    if (isEmpty(l))
        return cons(x, null());
    else
        return cons(head(l), snoc(x, tail(l)));

    // ejemplo con lista  4 -> 3 -> 2 -> 1
    // cons(4, cons(3, cons(2, cons(1, cons(x, null())))));
}

lista append(lista l, lista p) {
    // Retorna la lista fruto de agregar la lista p al final de la lista l.
    // l y p no comparten memoria con la lista resultado.

    if (isEmpty(p)) {  // si p es vacía, no hay nada que agregar a 'l'.
        return l;
    }

    if (!isEmpty(l)) {
        // si 'l' tiene elementos, hacemos una llamada recursiva (que se irá sumando al stack),
        // para construir la nueva lista con los elementos de 'l'.
        return cons(head(l), append(tail(l), p));
    }

    if (isEmpty(l)) {
        // cuando lleguemos al final de 'l', se hará lo mismo pero con 'l',
        // siendo null y se agregarán entonces los elementos de 'p'.
        return cons(head(p), append(null(), tail(p)));
    }
}

int last(lista l) {
    // Retorna el último elemento.
    // Pre: l no vacía.

    if (!isEmpty(tail(l))) {
        return last(tail(l));
    }

    return head(l);
}

int howMany(int x, lista l) {
    // Cuenta las ocurrencias del natural x en la lista l
    if (isEmpty(l)) {
        return 0;
    }

    if (head(l) != x) {
        return 0 + howMany(x, tail(l));
    }

    return 1 + howMany(x, tail(l));
}

int max(lista l) {
    // Retorna el máximo elemento de l.
    // Pre: l no vacía.

    if (isEmpty(tail(l))) {
        return head(l);
    } else {
        int max_tail = max(tail(l));
        if (head(l) > max_tail) {
            return head(l);
        } else {
            return max_tail;
        }
    }
}
