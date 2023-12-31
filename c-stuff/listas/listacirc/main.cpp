#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <iostream>

#include "listacirc.h"

using namespace std;

void imprimir_lista(listacirc l) {
    // Imprime el valor del nodo actual.

    // imprimimos el primero e iteraremos con el resto de la lista
    listacirc current = tail(l);
    cout << head(l);
    cout << " -> ";

    // hasta llegar al primero
    while (current != l) {
        cout << head(current);
        cout << " -> ";
        current = tail(current);
    }

    cout << endl;
}

int main() {
    bool salir = false;
    bool creado = false;
    bool creado2 = false;
    listacirc l, p;
    int opcion, opcion2;

    do {
        cout << "\n\n 1 - crear lista circular\n";
        cout << " 2 - head\n";
        cout << " 3 - tail\n";
        cout << " 4 - cons\n";
        cout << " 5 - snoc\n";
        cout << " 6 - cantidad\n";
        cout << " 7 - isEmpty\n";
        cout << " 8 - pertenece\n";
        cout << " 9 - imprimir lista\n";
        cout << " 10 - eliminar\n";
        cout << " 99 - destruir\n";
        cout << " 0 - salir\n";
        cout << "> ";

        cin >> opcion;

        if (opcion == 1) {
            if (!creado) {
                l = crear();
                creado = true;
                cout << " - lista creada.\n";
            } else
                cout << " - La lista ya está creada.\n";
        } else if (opcion == 2) {
            if (creado)
                if (isEmpty(l))
                    cout << " - La lista NO puede ser vacia.\n";
                else
                    cout << " -> " << head(l) << "\n";
            else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 3) {
            if (creado) {
                if (isEmpty(l))
                    cout << " - La lista NO puede ser vacia.\n";
                else {
                    cout << "\t-> ";
                    imprimir_lista(tail(l));
                    cout << endl;
                }
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 4) {
            if (creado) {
                cout << " - Valor a ingresar: ";
                cin >> opcion;
                l = cons(l, opcion);
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 5) {
            if (creado) {
                cout << " - Valor a ingresar: ";
                cin >> opcion;
                l = snoc(l, opcion);
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 6) {
            if (creado) {
                cout << "La lista tiene " << cant(l) << " elementos.";
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 7) {
            if (creado) {
                if (isEmpty(l)) {
                    cout << "La es vacía.";
                } else {
                    cout << "La NO es vacía.";
                }
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 8) {
            if (creado) {
                cout << " - Valor a buscar: ";
                cin >> opcion;
                if (pertenece(l, opcion)) {
                    cout << opcion << " pertenece a la lista.";
                } else {
                    cout << opcion << " NO pertenece a la lista.";
                }
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 9) {
            if (creado) {
                cout << "\t-> ";
                imprimir_lista(l);
                cout << endl;
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 10) {
            if (creado) {
                cout << " - Valor a eliminar: ";
                cin >> opcion;
                if (pertenece(l, opcion)) {
                    imprimir_lista(elim(l, opcion));
                } else {
                    cout << "El elemento no pertenece a la lista";
                }
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 99) {
            l = destruir(l);
        } else if (opcion == 0) {
            salir = true;
        } else
            cout << " - comando incorrecto.\n";
    } while (!salir);

    cout << "\n\n\tCHAUUU!!!!\n";
    l = destruir(l);
}
