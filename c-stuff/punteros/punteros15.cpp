#include <stdio.h>

#define SIZE 100
/* Información sobre la celda */
struct info_celda {
    char nombre[SIZE];                  /* Nombre de la celda */
    unsigned int identificador;         /* Número identificador */
    float calidad_senal;                /* Calidad de la señal (entre 0 y 100) */
    struct info_operador *ptr_operador; /* Puntero a una segunda estructura */
};
/* Información sobre el operador */
struct info_operador {
    char nombre[SIZE];           /* Cadena de texto con el nombre */
    unsigned int prioridad;      /* Prioridad de conexión */
    unsigned int ultima_comprob; /* Fecha de la última comprobación */
};

typedef struct info_celda *info_celda_ptr;       /* tipo de puntero */
typedef struct info_operador *info_operador_ptr; /* tipo de puntero */

int main() {
    info_celda c;                    // estructura de tipo info_celda
    info_celda_ptr c_ptr = &c;       // pointer de tipo info_celda
    info_operador op;                // estructura de tipo info_operador
    info_operador_ptr op_ptr = &op;  // pointer de tipo info_operador

    // testing purposes
    c.identificador = 69;
    op.prioridad = 99;

    //  1ra forma de guardar información de estructura op en estructura c
    // c.ptr_operador = &op;

    //  2da forma de guardar información de estructura op en estructura c
    // c_ptr->ptr_operador = op_ptr;

    //  3ra forma de guardar información de estructura op en estructura c
    // c.ptr_operador = op_ptr;

    //  4ta forma de guardar información de estructura op en estructura c
    // c_ptr->ptr_operador = &op;

    printf("%d", c.ptr_operador->prioridad);

    return 0;
}