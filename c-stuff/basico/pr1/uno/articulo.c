#include <stdio.h>
#include <string.h>
#include "articulo.h"

// crea un articulo
struct articulo_boutique crearArticulo(int codigo, int talle, char color[20], float precio, int cantidad)
{
    struct articulo_boutique nuevoArticulo;
    nuevoArticulo.codigo = codigo;
    nuevoArticulo.talle = talle;
    strcpy(nuevoArticulo.color, color); // strcpy(destination, source)
    nuevoArticulo.precio = precio;
    nuevoArticulo.cantidad = cantidad;

    return nuevoArticulo;
};

// modifica la cantidad del articulo
void modificarCantidad(struct articulo_boutique *articulo_ptr, int nueva_cantidad)
{
    articulo_ptr->cantidad = nueva_cantidad;
};

// imprimie el articulo linea por linea
void imprimirArticulo(struct articulo_boutique articulo)
{
    printf("Código: %d\n", articulo.codigo);
    printf("Talle: %d\n", articulo.talle);
    printf("Color: %s\n", articulo.color);
    printf("Precio: %.2f\n", articulo.precio);
    printf("Cantidad: %d\n", articulo.cantidad);
};
