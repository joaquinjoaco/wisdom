#include <stdio.h>

#define SIZE 100
/* Información sobre la celda */
struct informacion_celda {
    char nombre[SIZE];                         /* Nombre de la celda */
    unsigned int identificador;                /* Número identificador */
    float calidad_senal;                       /* Calidad de la señal (entre 0 y 100) */
    struct informacion_operador *ptr_operador; /* Puntero a una segunda estructura */
};
/* Información sobre el operador */
struct informacion_operador {
    char nombre[SIZE];           /* Cadena de texto con el nombre */
    unsigned int prioridad;      /* Prioridad de conexión */
    unsigned int ultima_comprob; /* Fecha de la última comprobación */
};

typedef struct informacion_celda *c_ptr; /* tipo de puntero */

/* main */
void main() {
    struct informacion_celda celda;
    c_ptr celda_ptr = &celda;

    // printf("%d", celda_ptr); /* print */
    struct informacion_celda c;
    printf("%d", &c.ptr_operador); /* print */
}

// Ejercicio 8
// ¿Qué cambios debes hacer en las definiciones de la parte izquierda para que sean equivalentes a las descripciones de la parte derecha?

// a) struct informacion_celda c; ----- variable de tipo estructura informacion_celda
// b) struct informacion_celda **c_ptr; -----  puntero a estructura informacion_celda
// el 'a' está perfecto, el 'b' debe tener:
// typedef struct informacion_celda *c_ptr;
// void main() {
//     struct informacion_celda celda;
//     c_ptr celda_ptr = &celda;

//     printf(celda_ptr);
// }