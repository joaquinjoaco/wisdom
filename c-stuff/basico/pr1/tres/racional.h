#ifndef RACIONAL_H
#define RACIONAL_H

// tipo opaco
typedef struct nodo_racional *racional;

// Crea un racional (pide memoria).
racional crear();

// Setea el nominador del racional
racional setNumerador(racional r, int a);

// Setea el denominador
// Pre: d no puede ser 0.
racional setDenominador(racional r, int b);

// Retorna el numerador de r.
int getNumerador(racional r);

// Retorna el denominador de r.
int getDenominador(racional r);

// Suma de dos racionales
racional suma(racional r1, racional r2);

// Diferencia de dos racionales
racional diferencia(racional r1, racional r2);

// Producto de dos racionales
racional producto(racional r1, racional r2);

// Cociente de dos racionales
racional cociente(racional r1, racional r2);

// Igualdad de dos racionales
void igualdad(racional r1, racional r2);

// MCD del numerador y el denominador
racional mcd(racional r);

// Forma normal del racional
racional formaNormal(racional r);

// Imprime el racional
void imprimir(racional r);

// Destruye un racional y libera la memoria asociada.
void destruir(racional &r);

#endif