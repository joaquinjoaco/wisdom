#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <iostream>

using namespace std;

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
    return (l == NULL);
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

lista destruir(lista l) {
    delete l;
    return l;
}

bool isElement(int x, lista l) {
    // Retorna true si x pertenece a l, false en caso contrario.

    if (isEmpty(l)) {
        // Caso base: si la lista está vacía, x no está en la lista.
        return false;
    } else if (head(l) == x) {
        // Si el primer elemento de la lista es igual a
        // x, retornar true.
        return true;
    } else {
        // Llamada recursiva para verificar el resto de la lista.
        return isElement(x, tail(l));
    }
}

lista remove(int x, lista l) {
    // Retorna la lista fruto de eliminar x en l.
    // l no comparte memoria con la lista resultado.

    if (isEmpty(l)) {
        // Caso base: si la lista está vacía, no hay nada que eliminar.
        return null();

    } else if (head(l) == x) {
        // Si el primer elemento de la lista es igual a 'x', lo salteamos y
        // continuamos con el resto de la lista.
        return remove(x, tail(l));

    } else {
        // Insertamos los datos a la nueva lista del stack *y no se invierte,
        // holy shit* (por el stack)
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
        // si 'l' tiene elementos, hacemos una llamada recursiva (que se irá
        // sumando al stack), para construir la nueva lista con los elementos de
        // 'l'.
        return cons(head(l), append(tail(l), p));
    }

    if (isEmpty(l)) {
        // cuando lleguemos al final de 'l', se hará lo mismo pero con 'l',
        // siendo null y se agregarán entonces los elementos de 'p'.
        return cons(head(p), append(null(), tail(p)));
    }
}

lista insert(int x, lista l) {
    // Retorna la lista fruto de insertar ordenadamente el elemento x en la
    // lista ordenada l. l no comparte memoria con la lista resultado.

    // 1,2,3,4,5 quiero meter el 6
    if (isEmpty(l))
        return cons(x, null());
    else if (head(l) < x)
        return cons(head(l), insert(x, tail(l)));
    else if (isEmpty(tail(l)))
        return cons(x, cons(head(l), null()));
    else
        return cons(x, cons(head(l), insert(head(tail(l)), tail(l))));
    // Para que siga copiando en “if (Head(l) < x)”
}

// cons(1, cons(2, cons(3, cons(4, cons(5, cons(6, NULL)))))))

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

bool isSorted(lista l) {
    // Retorna true si l está ordenada de menor a mayor, false en caso
    // contrario.

    // 1,2,3,4
    if (isEmpty(l)) {
        return true;
    }
    if (isEmpty(tail(l))) {
        // sino tira violación del segmento cuando llega al
        // ultimo numero porque no se puede hacer un head(null)
        return true;
    }
    if (head(l) > head(tail(l))) {  // el primero es mayor al siguiente?
        return false;
    }

    return isSorted(tail(l));  // llamada recursiva
}

lista change(int x, int y, lista l) {
    // Retorna una nueva lista fruto de cambiar x por y en l.
    // l no comparte memoria con la lista resultado.

    if (isEmpty(l)) {  // si está vacía no insertamos nada.
        return null();
    }

    if (head(l) != x) {
        // si el elemento actual no es igual a 'x', seguimos construyendo la
        // nueva lista para que no comparta memoria
        return cons(head(l), change(x, y, tail(l)));
    }

    if (head(l) == x) {
        // se sigue construyendo la lista pero en lugar de poner el head(l)
        // ponemos a 'y'
        return cons(y, change(x, y, tail(l)));
    }
}

lista insBefore(int x, int y, lista l) {
    // Retorna una nueva lista fruto de insertar x antes de y en l.
    // l no comparte memoria con la lista resultado.

    if (isEmpty(l)) {  // si está vacía no insertamos naa.
        return null();
    }

    if (head(l) == y) {
        // si encontramos el elemento 'y', insertaremos 'x' al
        // principio de la lista que tenemos.
        return cons(x, cons(y, insBefore(x, y, tail(l))));
    }

    if (head(l) != y) {
        // si no es el elemento 'y', seguimos construyendo la
        // lista para que no comparta memoria.
        return cons(head(l), insBefore(x, y, tail(l)));
    }
}

lista insAround(int x, int y, lista l) {
    // Retorna una nueva lista fruto de insertar x antes y después de y en l.
    // l no comparte memoria con la lista resultado.

    if (isEmpty(l)) {  // si está vacía no insertamos naa.
        return null();
    }

    if (head(l) == y) {
        // si encontramos el elemento 'y', insertaremos 'x' luego 'y' y luego 'x' de nuevo.
        return cons(x, cons(y, cons(x, insBefore(x, y, tail(l)))));
    }

    if (head(l) != y) {
        // si no es el elemento 'y', seguimos construyendo la
        // lista para que no comparta memoria.
        return cons(head(l), insBefore(x, y, tail(l)));
    }
}

bool equals(lista l, lista p) {
    // Retorna true si las listas l y p son iguales (mismos elementos en el mismo orden)
    // false en caso contrario.

    if (isEmpty(l) && isEmpty(p)) {  // paso base (tenemos que llegar aca para que sea true)
        return true;                 // son las dos vacias y por tanto iguales
    }

    if (isEmpty(l)) {
        return false;
    }

    if (isEmpty(p)) {
        return false;
    }

    if (head(l) == head(p)) {
        return equals(tail(l), tail(p));  // mientras sigan siendo iguales, eventualmente llegaremos al paso base.
    }
}

void show(lista l) {
    // Muestra los elementos de la lista l separados por comas.

    if (!isEmpty(l)) {
        // si hay un elemento lo imprimimos.
        cout << head(l);
        if (!isEmpty(tail(l))) {
            // si hay un elemento siguiente imprimiremos una coma.
            cout << ", ";
            show(tail(l));  // vamos a imprimir el siguiente elemento
        }
    }
}