// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// racional.h
// Modulo Definición/Especificación Racional.

#ifndef RACIONAL_H
#define RACIONAL_H

struct racional{
	int num;
	int den;
};


racional setNumerador(racional r, int num);
// Setea el numerador de r con num.

racional setDenominador(racional r, int den);
// Setea el denominador de r con den.
// Pre: den != 0.

int getNumerador(racional r);
// Retorna el numerador de r.

int getDenominador(racional r);
// Retorna el denominador de r.

racional suma(racional r1, racional r2);
// Retorna la suma de r1 y r2.

racional mult(racional r1, racional r2);
// Retorna el producto de r1 y r2.

racional div(racional r1, racional r2);
// Retorna el cociente de r1 y r2.
// Pre: r2 != 0.

#endif





















