#ifndef ARTICULO_H
#define ARTICULO_H

struct articulo_boutique{
	int codigo;
	int talle;
	char color[20];
	float precio;
	int cantidad;
};


// crea un articulo
struct articulo_boutique crearArticulo(int codigo, int talle, char color[20], float precio, int cantidad);

// modifica la cantidad del articulo
void modificarCantidad(struct articulo_boutique *articulo_ptr, int nueva_cantidad);

// imprimir el articulo
void imprimirArticulo(struct articulo_boutique articulo);

#endif
