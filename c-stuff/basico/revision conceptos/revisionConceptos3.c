#include <stdio.h>

struct fecha {
    int dia;
    int mes;
    int anio;
};

struct paciente {
    char nombre[16];  // hasta 15 letras, por alguna razon siempre tiene que sobrar un byte
    int cedula[8];
    int edad;
    struct fecha fechaNac;
};

void main(){

};