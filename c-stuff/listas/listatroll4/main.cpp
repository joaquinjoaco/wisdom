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
        if (!isEmpty(tail(l))) cout << " - ";
        l = tail(l);
    }
    cout << endl;
}

int main() {
    bool salir = false;
    bool creado = false;
    bool creado2 = false;
    lista l, p;
    int opcion, opcion2;

    do {
        cout << "\n\n 1 - crear lista\n";
        cout << " 2 - head\n";
        cout << " 3 - tail\n";
        cout << " 4 - cons\n";
        cout << " 5 - isElement\n";
        cout << " 6 - remove\n";
        cout << " 7 - length\n";
        cout << " 8 - snoc\n";
        cout << " 9 - imprimir lista\n";
        cout << " 10 - crear lista 2\n";
        cout << " 14 - cons 2\n";
        cout << " 15 - append 2 to 1\n";
        cout << " 16 - last\n";
        cout << " 17 - how many\n";
        cout << " 18 - isSorted\n";
        cout << " 19 - imprimir lista 2\n";
        cout << " 20 - insert\n";
        cout << " 21 - change\n";
        cout << " 22 - insBefore\n";
        cout << " 23 - insAround\n";
        cout << " 24 - equals\n";
        cout << " 25 - show\n";
        cout << " 0 - salir\n";
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
                    if (!isEmpty(tail(l))) imprimir_lista(tail(l));
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
                if (isElement(opcion, l)) {
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
                if (isElement(opcion, l)) {
                    imprimir_lista(remove(opcion, l));
                } else {
                    cout << opcion << " NO pertenece a la lista";
                }
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 7) {
            if (creado) {
                cout << "Largo de la lista: " << length(l);
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 8) {
            if (creado) {
                cout << " - Valor a ingresar: ";
                cin >> opcion;
                imprimir_lista(snoc(opcion, l));
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
            if (!creado2) {
                p = null();
                creado2 = true;
                cout << " - Lista 2 creada.\n";
            } else
                cout << " - La lista 2 ya está creada.\n";
        } else if (opcion == 14) {
            if (creado2) {
                cout << " - Valor a ingresar: ";
                cin >> opcion;
                p = cons(opcion, p);
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 15) {
            if (creado && creado2) {
                imprimir_lista(append(l, p));
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 16) {
            if (creado && !isEmpty(l)) {
                cout << "Last de l: " << last(l);
            } else
                cout << " - No se puede realizar.\n";
        } else if (opcion == 17) {
            if (creado) {
                cout << "Valor a contar: ";
                cin >> opcion;
                cout << opcion << " aparece " << howMany(opcion, l)
                     << " veces.";
            } else
                cout << " - No se puede realizar.\n";
        } else if (opcion == 18) {
            if (creado) {
                if (isSorted(l)) {
                    cout << "La lista está ordenada.";
                } else {
                    cout << "La lista NO está ordenada.";
                }
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 19) {
            if (creado2) {
                cout << "\t-> ";
                imprimir_lista(p);
                cout << endl;
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 20) {
            if (creado) {
                if (isSorted(l)) {
                    cout << " - Valor a ingresar ordenadamente: ";
                    cin >> opcion;
                    l = insert(opcion, l);
                } else {
                    cout << "La lista NO está ordenada.";
                }
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 21) {
            if (creado) {
                cout << " - Valor a reemplazar: ";
                cin >> opcion;
                cout << " - Valor nuevo: ";
                cin >> opcion2;
                imprimir_lista(change(opcion, opcion2, l));
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 22) {
            if (creado) {
                cout << " - Valor a insertar: ";
                cin >> opcion;
                cout << " - Antes de: ";
                cin >> opcion2;
                imprimir_lista(insBefore(opcion, opcion2, l));
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 23) {
            if (creado) {
                cout << " - Valor a insertar: ";
                cin >> opcion;
                cout << " - Alrededor de: ";
                cin >> opcion2;
                imprimir_lista(insAround(opcion, opcion2, l));
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 24) {
            if (creado && creado2) {
                if (equals(l, p)) {
                    cout << "La lista 'l' y la lista 'p' son iguales";
                } else {
                    cout << "La lista 'l' y la lista 'p' NO son iguales";
                }
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 25) {
            if (creado) {
                show(l);
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
