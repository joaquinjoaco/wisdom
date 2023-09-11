#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <iostream>

#include "lista.h"

using namespace std;

void imprimir_lista(lista l) {
    // Imprime l en la salida estandar.
    while (!isEmpty(l)) {
        cout << head(l);
        if (!isEmpty(tail(l)))
            cout << " - ";
        l = tail(l);
    }
    cout << endl;
}

int main() {
    bool salir = false;
    bool creado = false;
    //     bool creado2 = false;
    lista l;
    //     lista p;
    int opcion;

    do {
        cout << "\n\n 1 - crear lista\n";
        cout << " 2 - head\n";
        cout << " 3 - tail\n";
        cout << " 4 - cons\n";
        cout << " 5 - IsElement\n";
        cout << " 6 - Remove\n";
        cout << " 7 - Length\n";
        cout << " 9 - Imprimir lista\n";
        cout << " 0 - Salir\n";
        cout << "> ";

        cin >> opcion;

        if (opcion == 1) {
            if (!creado) {
                l = null();
                creado = true;
                cout << " - lista creada.\n";
            } else
                cout << " - La lista ya está creada.\n";
        } else if (opcion == 2) {
            if (creado)
                if (isEmpty(l))
                    cout << " - La lista NO puede ser vacia.\n";
                else
                    cout << " - " << head(l) << "\n";
            else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 3) {
            if (creado) {
                if (isEmpty(l))
                    cout << " - La lista NO puede ser vacia.\n";
                else {
                    cout << "\t-> ";
                    if (!isEmpty(tail(l)))
                        imprimir_lista(tail(l));
                    cout << endl;
                }
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 4) {
            if (creado) {
                cout << " - Valor a ingresar: ";
                cin >> opcion;
                l = cons(opcion, l);
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 5) {
            if (creado) {
                cout << " - Valor a buscar: ";
                cin >> opcion;
                if (IsElement(opcion, l)) {
                    cout << opcion << " pertenece a la lista";
                } else {
                    cout << opcion << " NO pertenece a la lista";
                }
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 6) {
            if (creado) {
                cout << " - Valor a remover: ";
                cin >> opcion;
                if (IsElement(opcion, l)) {
                    imprimir_lista(Remove(opcion, l));
                } else {
                    cout << opcion << " NO pertenece a la lista";
                }
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 7) {
            if (creado) {
                cout << "Largo de la lista: " << Length(l);
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 9) {
            if (creado) {
                cout << "\t-> ";
                imprimir_lista(l);
                cout << endl;
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 0) {
            salir = true;
        } else
            cout << " - comando incorrecto.\n";
    } while (!salir);

    cout << "\n\n\tCHAUUU!!!!\n";
    l = destruir(l);
}
