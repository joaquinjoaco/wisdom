// Estructuras de Datos y Algoritmos - Curso 2021
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// main.c
// Programa de Prueba Lista Simple de Enteros

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
    bool creado2 = false;
    lista l;
    lista p;
    int opcion;

    do {
        cout << "\n\n 1 - crear lista\n";
        cout << " 2 - head\n";
        cout << " 3 - tail\n";
        cout << " 4 - cons\n";
        cout << " 5 - snoc\n";
        cout << " 6 - vacia\n";
        cout << " 7 - pertenece\n";
        cout << " 8 - cantidad\n";
        cout << " 9 - imprimir\n";
        cout << "10 - eliminar\n";
        cout << "11 - destruir\n";
        cout << "12 - maximo\n";
        cout << "13 - promedio\n";
        cout << "14 - crear 2\n";
        cout << "15 - imprimir 2\n";
        cout << "16 - cons 2\n";
        cout << "17 - snoc 2\n";
        cout << "18 - Equals\n";
        cout << "19 - Take\n";
        cout << "20 - Drop\n";
        cout << "21 - Merge 1 & 2\n";
        cout << "22 - Append 2 to 1\n";
        cout << " 0 - salir\n\n";
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
                if (isEmpty(l))
                    cout << " - La lista es vacia.\n";
                else
                    cout << " - La lista es NO vacia.\n";
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 7) {
            if (creado) {
                cout << " - Valor: ";
                cin >> opcion;
                if (pertenece(l, opcion))
                    cout << " - " << opcion << " pertenece a la lista.\n";
                else
                    cout << " - " << opcion << " NO pertenece a la lista.\n";
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 8) {
            if (creado)
                cout << " - La lista tiene " << cant(l) << " elementos.\n";
            else
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
                l = elim(l, opcion);
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 11) {
            if (creado) {
                l = destruir(l);
                cout << " - lista destruida.\n";
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 12) {
            if (creado)
                cout << " - El maximo elemento es " << Max(l) << "\n";
            else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 13) {
            if (creado)
                cout << " - El promedio de los elementos es " << Average(l) << "\n";
            else
                cout << " - Debe crear la lista para usar el comando.\n";
        }
        // lista 2
        else if (opcion == 14) {
            if (!creado2) {
                p = crear();
                creado2 = true;
                cout << " - lista 2 creada.\n";
            } else
                cout << " - La lista 2 ya esta creada.\n";
        } else if (opcion == 15) {
            if (creado2) {
                cout << "\t-> ";
                imprimir_lista(p);
                cout << endl;
            } else
                cout << " - Debe crear la lista 2 para usar el comando.\n";
        } else if (opcion == 16) {
            if (creado2) {
                cout << " - Valor a ingresar: ";
                cin >> opcion;
                p = cons(p, opcion);
            } else
                cout << " - Debe crear la lista 2 para usar el comando.\n";
        } else if (opcion == 17) {
            if (creado2) {
                cout << " - Valor a ingresar: ";
                cin >> opcion;
                p = snoc(p, opcion);
            } else
                cout << " - Debe crear la lista 2 para usar el comando.\n";
        } else if (opcion == 18) {
            if (creado && creado2) {
                cout << Equals(l, p);
            } else
                cout << " - Debe crear las dos listas para usar el comando.\n";
        } else if (opcion == 19) {
            if (creado) {
                cout << " - Cuantos elementos tomar de la primer lista: ";
                cin >> opcion;
                imprimir_lista(Take(opcion, l));
            } else
                cout << " - Debe crear la lista 1 para usar el comando.\n";
        } else if (opcion == 20) {
            if (creado) {
                cout << " - Cuantos elementos no tomar tomar de la primer lista: ";
                cin >> opcion;
                imprimir_lista(Drop(opcion, l));
            } else
                cout << " - Debe crear la lista 1 para usar el comando.\n";
        } else if (opcion == 21) {
            if (creado && creado2) {
                imprimir_lista(Merge(l, p));
            } else
                cout << " - Debe crear las dos listas para usar el comando.\n";
        } else if (opcion == 22) {
            if (creado && creado2) {
                imprimir_lista(Append(l, p));
            } else
                cout << " - Debe crear las dos listas para usar el comando.\n";
        } else if (opcion == 23) {
            if (creado) {
                cout << " - Cuantos elementos tomar de la primer lista: ";
                cin >> opcion;
                imprimir_lista(Take(opcion, l));
            } else
                cout << " - Debe crear la lista 1 para usar el comando.\n";
        }

        else if (opcion == 0) {
            salir = true;
        } else
            cout << " - comando incorrecto.\n";
    } while (!salir);

    cout << "\n\n\tCHAUUU!!!!\n";
    l = destruir(l);
}
