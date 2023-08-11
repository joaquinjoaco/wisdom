#include <stdio.h>
#include "articulo.h"

int main()
{
    // creamos un nuevo articulo
    struct articulo_boutique articulo = crearArticulo(123456, 42, "Negro", 699.99, 50);

    modificarCantidad(&articulo, 55);

    // imprimimos en consola el articulo
    imprimirArticulo(articulo);

    return 0;
};
