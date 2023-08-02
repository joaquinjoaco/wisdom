#include <stdio.h>   // libreria
#include <string.h>  // libreria

// %d --> int
// %c --> char
// %f --> float
// %s --> strings

struct fecha {
    int dia;
    char mes[12]; // arreglo de caracteres tamaño 12
    int anio;
    char bisiesto;
};

main() {  // falta int main porque hay un return 0; al final
    struct fecha f1, f2; // admite no utilizar struct, es opcional

    f1.dia = 30;
    // f1.mes[0] = 'enero'; // no son las comillas correctas y no se puede
    // reasignar la memoria
    f1.dia = 48;
    f1.anio = 2000;
    // f1.bisiesto = si; // faltan comillas y bisiesto es un char

    f2.anio = f1.dia;
    f2.bisiesto = 'n';
    printf("%d", f1.mes);

    if (f2.anio < f1.anio) printf("%c", f2.mes);

    return 0;
};