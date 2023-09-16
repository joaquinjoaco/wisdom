// Estructuras de Datos y Algoritmos - Curso 2021
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// racional.h
// Modulo Definicion/Especificacion Numeros Racionales.

#ifndef RACIONAL_H
#define RACIONAL_H


typedef struct nodo_racional * racional;
// Tipo Opaco

racional crear();
// Crea un racional (pide memoria).

void imprimir(racional r);
// Imprime el racional r de la forma num/den.

racional setNumerador(racional r, int n);
// Setea el numerador de r.

racional setDenominador(racional r, int d);
// Setea el denominador de r.
// Pre: d no puede ser 0.

int getNumerador(racional r);
// Retorna el numerador de r.

int getDenominador(racional r);
// Retorna el denominador de r.

racional suma(racional r1, racional r2);
// Retorna la suma de r1 y r2.

racional multiplicacion(racional r1, racional r2);
// Retorna el producto de r1 y r2.

racional division(racional r1, racional r2);
// Retorna el cociente de r1 y r2.
// Pre: r2 no puede ser 0.

void destruir(racional & r);
// Destruye un racional y libera la memoria asociada.

#endif
