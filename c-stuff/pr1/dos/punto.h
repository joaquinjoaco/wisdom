#ifndef PUNTO_H
#define PUNTO_H

// tipo opaco
typedef struct nodo_punto *punto;

// Crea un punto
punto crear();

// Setea la componente horizontal del punto
punto setAbscisa(punto pto, int x);

// Setea la componente horizontal del punto
punto setOrdenada(punto pto, int y);

// Suma vectorial de dos puntos
punto sumaV(punto pto1, punto pto2);

// Diferencia entre dos puntos
punto diferenciaV(punto pto1, punto pto2);

// Largo del segmento
float largo_segmento(punto pto1, punto pto2);

// Imprime un punto
void imprimir(punto pto);

// Libera la memoria donde se encuentra guardado un punto
void destruir(punto &pto);


#endif