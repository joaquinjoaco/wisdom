// Estructuras de Datos y Algoritmos - Curso 2021
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// main.c
// Modulo Prueba Numeros Racionales

#include <iostream>
#include "racional.h"

using namespace std;


int main(){
	racional r1, r2, sum, mult, div;
	r1 = crear();
	r2 = crear();
	
	r1 = setNumerador(r1, 1); // setNumerador(r1, 1); si se usa el pasaje por referencia
	
	r1 = setDenominador(r1, 2); // setDenominador(r1, 2); si se usa el pasaje por referencia

	r2 = setNumerador(r2, 1); // setNumerador(r2, 1); si se usa el pasaje por referencia
	r2 = setDenominador(r2, 2); // setDenominador(r2, 1); si se usa el pasaje por referencia
	
	sum = suma(r1, r2);
	mult = multiplicacion(r1, r2);
	div = division(r1, r2);

	cout << "La suma de ";
	imprimir(r1);
	cout << " y ";
	imprimir(r2);
	cout << " es ";
	imprimir(sum);
	cout << endl;

	cout << "El producto de ";
	imprimir(r1);
	cout << " y ";
	imprimir(r2);
	cout << " es ";
	imprimir(mult);
	cout << endl;

	cout << "El cociente de ";
	imprimir(r1);
	cout << " y ";
	imprimir(r2);
	cout << " es ";
	imprimir(div);
	cout << endl;
	
	destruir(r1);
	destruir(r2);
	destruir(sum);
	destruir(mult);
	destruir(div);
	
	return 0;
}







