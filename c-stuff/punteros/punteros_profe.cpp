// Estructuras de Datos y Algoritmos - Curso 2021
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// main.c
// Ejemplo Punteros

#include <iostream>

#define MAX_ARR 5

using namespace std;

int main() {
    int* a;  // Dinámica
    a = new (int);
    *a = 3;
    int* b = a;  // alias
    cout << "a=" << a << " -> " << *a << "\n";
    cout << "b=" << b << " -> " << *b << endl;
    *b = 7;
    cout << "a=" << a << " -> " << *a << "\n";
    cout << "b=" << b << " -> " << *b << endl;
    a = new (int);
    *a = 30;
    cout << "a=" << a << " -> " << *a << "\n";
    cout << "b=" << b << " -> " << *b << endl;

    int* arr = new (int[MAX_ARR]);

    for (int i = 0; i < 100000; i++) {
        cout << "arr[" << i << "]=" << &arr[i] << " -> " << arr[i] << "\n";
    }

    /*	int * a;   // Dinámica
    a = new(int);
    *a = 3;
    int * b = a; // alias

    int * c = new(int);
    *c = 9;

    b = c;

    delete a;

    int * arr = new(int[MAX_ARR]);
    arr[0] = 4;
    ....
    int * aux = new(int[2*MAX_ARR]);
    // copiar datos de arr a aux
    delete [] arr;
    arr = aux;

    */
}