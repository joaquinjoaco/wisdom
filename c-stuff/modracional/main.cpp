#include <iostream>
#include "racional.h"

using namespace std;


void imprimir(racional r){
	cout << getNumerador(r) << "/" << getDenominador(r);
}	



int main(){
 
	racional r1, r2, sum, multi, cociente;
	
	r1 = setNumerador(r1, 1);
	r1 = setDenominador(r1, 2);

	r2 = setNumerador(r2, 1);
	r2 = setDenominador(r2, 2);

	sum = suma (r1, r2);
	multi = mult (r1, r2);
	cociente = div (r1, r2);
	
	imprimir(r1);
	cout << " + ";
	imprimir(r2);
	cout << " = ";
	imprimir(sum);
	cout << endl;

	
	imprimir(r1);
	cout << " * ";
	imprimir(r2);
	cout << " = ";
	imprimir(multi);
	cout << endl;

	
	imprimir(r1);
	cout << " / ";
	imprimir(r2);
	cout << " = ";
	imprimir(cociente);
	cout << endl;


	return 1;
}





















