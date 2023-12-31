#ifndef LISTA_H
#define LISTA_H

// Estructuras de Datos y Algoritmos - Curso 2021
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// lista.h
// Lista Simple de Enteros

typedef struct nodo_lista* lista;

lista crear();
// Crea la lista vacia.

lista cons(lista l, int n);
// Inserta n al inicio de l.

lista snoc(lista l, int n);
// Inserta n al final de l.

lista Insert(int x, lista l);
// Inserta ordenadamente el elemento x en la lista ordenada l.

lista sort(lista l);
// Ordena la lista.

int head(lista l);
// Retorna el primer elemento de la lista.
// Pre: l no vacia.

lista tail(lista l);
// Retorna el "resto" de la lista.
// Pre: l no vacia.

bool isEmpty(lista l);
// Retorna true si l es vacia, false en caso contrario.

int cant(lista l);
// Retorna la cantidad de elementos de l.

bool pertenece(lista l, int n);
// Retorna true si n pertenece a l, false en caso contrario.

lista elim(lista l, int elem);
// En caso de que elem pertenezca a l, retorna l sin ese elemento.

lista destruir(lista l);
// Destruye l y libera la memoria asociada.

int Max(lista l);
// Retorna el máximo elemento de l.
// Pre: l no es vacía.

float Average(lista l);
// Retorna si la lista no es vacía el promedio de sus elementos.
// Pre: l no es vacía.

bool Equals(lista l, lista l2);
// Verifica si las listas l y p son iguales (mismos elementos en el mismo orden).

lista Take(int i, lista l);
// Retorna la lista resultado de tomar los primeros i elementos.
// l no comparte memoria con la lista resultado.

lista Drop(int u, lista l);
// Retorna la lista resultado de no tomar los primeros u elementos.
// l no comparte memoria con la lista resultado.

lista Merge(lista l, lista p);
// Genera una lista fruto de intercalar ordenadamente las listas.
// l y p que vienen ordenadas.
// l y p no comparten memoria con la lista resultado.

lista Append(lista l, lista p);
// Agrega la lista p al final de la lista l.
// l y p no comparten memoria con la lista resultado.

lista TakeRecursivo(int i, lista l);
// Retorna la lista resultado de tomar los primeros i elementos.
// l no comparte memoria con la lista resultado.

lista DropRecursivo(int u, lista l);
// Retorna la lista resultado de no tomar los primeros u elementos.
// l no comparte memoria con la lista resultado.

lista MergeRecursivo(lista l, lista p);
// Genera una lista fruto de intercalar ordenadamente las listas.
// l y p que vienen ordenadas.
// l y p no comparten memoria con la lista resultado.

lista AppendRecursivo(lista l, lista p);
// Agrega la lista p al final de la lista l.
// l y p no comparten memoria con la lista resultado.

#endif
