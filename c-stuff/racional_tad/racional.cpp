// Estructuras de Datos y Algoritmos - Curso 2021
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// racional.c
// Modulo Implementacion Numeros Racionales.

#include "racional.h"
#include <iostream>

using namespace std;

struct nodo_racional{
	int num;
	int den;
};

racional crear(){
// Crea un racional (pide memoria).
	racional aux = new(nodo_racional);
	return aux;
}

void imprimir(racional r){
// Imprime el racional r de la forma num/den.
	cout << r->num << "/" << r->den;
}

racional setNumerador(racional r, int n){
// void setNumerador(racional & r, int n){ // Se puede usar un retorno o pasar r como referencia (&)
// Setea el numerador de r.
	r->num = n;
	return r;
}

racional setDenominador(racional r, int d){
// void setDenominador(racional & r, int d){ // Se puede usar un retorno o pasar r como referencia (&)
// Setea el denominador de r.
	r->den = d;
	return r;
}

int getNumerador(racional r){
// Retorna el numerador de r.	
	return r->num;
}

int getDenominador(racional r){
// Retorna el denominador de r.	
	return r->den;
}

racional suma(racional r1, racional r2){
// Retorna la suma de r1 y r2.
	racional aux = crear();
	aux->num = r1->num*r2->den + r2->num*r1->den;
	aux->den = r1->den*r2->den;
	return aux;
}

racional multiplicacion(racional r1, racional r2){
// Retorna el producto de r1 y r2.
	racional aux = crear();
	aux->num = r1->num*r2->num;
	aux->den = r1->den*r2->den;
	return aux;
}

racional division(racional r1, racional r2){
// Retorna el cociente de r1 y r2.
	racional aux = crear();
	aux->num = r1->num*r2->den;
	aux->den = r1->den*r2->num;
	return aux;
}

void destruir(racional & r){
// Destruye un racional y libera la memoria asociada.
	delete r;
}
