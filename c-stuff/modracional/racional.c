// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// racional.c
// Modulo Implementacion Racional.

#include "racional.h"

racional setNumerador(racional r, int num){
// Setea el numerador de r con num.
	r.num = num;
	return r;
}

racional setDenominador(racional r, int den){
// Setea el denominador de r con den.
// Pre: den != 0.
	r.den = den;
	return r;
}

int getNumerador(racional r){
// Retorna el numerador de r.
	return r.num;
}

int getDenominador(racional r){
// Retorna el denominador de r.
	return r.den;
}

racional suma(racional r1, racional r2){
// Retorna la suma de r1 y r2.
	racional sum;
	sum.num = r1.num * r2.den + r2.num*r1.den;
	sum.den = r1.den * r2.den;
	return sum;
} 

racional mult(racional r1, racional r2){
// Retorna el producto de r1 y r2.
	racional prod;
	prod.num = r1.num * r2.num;
	prod.den = r1.den * r2.den;
	return prod;
}

racional div(racional r1, racional r2){
// Retorna el cociente de r1 y r2.
// Pre: r2 != 0.
	racional coc;
	coc.num = r1.den * r2.num;
	coc.den = r1.num * r2.den;
	return coc;
}

