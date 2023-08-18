// Defina los siguientes programas en las dos formas: iterativa y recursiva. Calcule el orden
// de sus tiempos de ejecuci´on en el peor caso. Se asume los arrays son de enteros.
// 1. Escribir una funci´on que verifique si dos arrays del mismo tama˜no son iguales

// RECURSIVO
#include <iostream>
using namespace std;

// chequea si los arrays son iguales
void iguales(int a1[5], int a2[5], int largo) {
    if (largo >= 0) {  // paso base
        if (a1[largo] == a2[largo]) {
            iguales(a1, a2, largo - 1);
        } else {
            cout << "NO son iguales";
            cout << endl;
        }
    } else {
        cout << "Son iguales";
        cout << endl;
    }
};

int main() {
    int a1[5] = {1, 2, 2, 4, 5};
    int a2[5] = {1, 2, 3, 4, 5};
    int largo = 4;
    iguales(a1, a2, largo);

    return 0;
}