// Defina los siguientes programas en las dos formas: iterativa y recursiva. Calcule el orden
// de sus tiempos de ejecuci´on en el peor caso. Se asume los arrays son de enteros.
// 1. Escribir una funci´on que verifique si dos arrays del mismo tama˜no son iguales

// ITERATIVO
#include <iostream>
using namespace std;

// chequea si los arrays son iguales
void iguales(int a1[5], int a2[5]) {
    bool igualdad = true;

    for (int i = 0; i < 5; i++) {
        if (a1[i] != a2[i]) {
            // el elemento de indice 'i' no es igual
            igualdad = false;
        }
    }

    if (igualdad) {
        cout << "son iguales";
        cout << endl;
    } else {
        cout << "NO son iguales";
        cout << endl;
    }
};

int main() {
    int a1[5] = {1, 2, 3, 4, 5};
    int a2[5] = {1, 2, 3, 4, 5};
    iguales(a1, a2);

    return 0;
}