#ifndef LISTA_H
#define LISTA_H

// listacirc.h
// Lista circular simple de enteros

typedef struct nodo_listacirc* listacirc;

listacirc crear();
// Crea la lista circular vacia.

listacirc copy(listacirc l);
// Crea una nueva lista a partir de la que recibe.

listacirc cons(listacirc l, int n);
// Inserta n al inicio de l.

listacirc snoc(listacirc l, int n);
// Inserta n al final de l.

int head(listacirc l);
// Retorna el primer elemento de la lista circular.
// Pre: l no vacia.

listacirc tail(listacirc l);
// Retorna el "resto" de la lista circular.
// Pre: l no vacia.

bool isEmpty(listacirc l);
// Retorna true si l es vacia, false en caso contrario.

int cant(listacirc l);
// Retorna la cantidad de elementos de l.

bool pertenece(listacirc l, int n);
// Retorna true si n pertenece a l, false en caso contrario.

listacirc elim(listacirc l, int elem);
// En caso de que elem pertenezca a l, retorna l sin ese elemento.

listacirc destruir(listacirc l);
// Destruye l y libera la memoria asociada.

#endif
