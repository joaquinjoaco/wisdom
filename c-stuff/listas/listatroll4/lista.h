#ifndef LISTA_H
#define LISTA_H

typedef struct nodo_lista* lista;

lista null();
// Crea la lista vacía.
lista cons(int x, lista l);
// Inserta el elemento x al principio de la lista l.
bool isEmpty(lista l);
// Retorna true si l es vacía, false en caso contrario.
int head(lista l);
// Retorna el primer elemento de la lista.
// Pre: l no vacía.
lista tail(lista l);
// Retorna la lista sin su primer elemento.
// Pre: l no vacía.

// --------------------------------------------------------------

lista destruir(lista l);

bool isElement(int x, lista l);
// Retorna true si x pertenece a l, false en caso contrario.

lista remove(int x, lista l);
// Retorna la lista fruto de eliminarx en l.
// l no comparte memoria con la lista resultado.

int length(lista l);
// Retorna la cantidad de elementos de la lista.

lista snoc(int x, lista l);
// Retorna la lista fruto de insertar el elemento x al final de la lista l.
// l no comparte memoria con la lista resultado.

lista append(lista l, lista p);
// Retorna la lista fruto de agregar la lista p al final de la lista l.
// l y p no comparten memoria con la lista resultado.


lista insert(int x, lista l);
// Retorna la lista fruto de insertar ordenadamente el elemento x en la lista ordenada l.
// l no comparte memoria con la lista resultado.

int last(lista l);
// Retorna el último elemento.
// Pre: l no vacía.

int howMany(int x, lista l);
// Cuenta las ocurrencias del natural x en la lista l

int max(lista l);
// Retorna el máximo elemento de l.
// Pre: l no vacía.

bool isSorted(lista l);
// Retorna true si l está ordenada, false en caso contrario.

lista change(int x, int y, lista l);
// Retorna una nueva lista fruto de cambiar x por y en l.
// l no comparte memoria con la lista resultado.

lista insBefore(int x, int y, lista l);
// Retorna una nueva lista fruto de insertar x antes de y en l.
// l no comparte memoria con la lista resultado.

lista insAround(int x, int y, lista l);
// Retorna una nueva lista fruto de insertar x antes y después de y en l.
// l no comparte memoria con la lista resultado.

bool equals(lista l, lista p);
// Retorna true si las listas l y p son iguales (mismos elementos en el mismo orden)
// false en caso contrario.

void show(lista l);
// Muestra los elementos de la lista l separados por comas.

#endif