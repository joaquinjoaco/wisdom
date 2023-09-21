
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <iostream>

#include "listade.h"

using namespace std;

void imprimir(listade l) {
    // Imprime l de principio a fin.

    if (!isEmpty(l)) {
        // vamos al inicio
        while (ant(l) != NULL) {
            l = ant(l);
        }

        while (l != NULL) {
            // imprimimos el dato recorriendo hacia adelante
            cout << actual(l);
            if (sig(l) != NULL) {
                // si hay mas datos imprimimos otro separador
                cout << " <-> ";
            }
            l = sig(l);
        }
    }

    cout << endl;
}

void imprimir_inv(listade l) {
    // Imprime l del fin al principio.

    if (!isEmpty(l)) {
        // vamos al final
        while (sig(l) != NULL) {
            l = sig(l);
        }

        while (l != NULL) {
            // imprimimos el dato recorriendo hacia atrás
            cout << actual(l);
            if (ant(l) != NULL) {
                // si hay mas datos imprimimos otro separador
                cout << " <-> ";
            }
            l = ant(l);
        }
    }

    cout << endl;
}

void imprimir_ant(listade l) {
    // Imprime los "anteriores" a l (actual).

    while (!isEmpty(l)) {
        cout << actual(l);
        if (ant(l) != NULL) {
            cout << " <-> ";
        }
        l = ant(l);
    }

    cout << endl;
}

void imprimir_sig(listade l) {
    // Imprime los "siguientes" a l (actual).

    while (!isEmpty(l)) {
        cout << actual(l);
        if (sig(l) != NULL) {
            cout << " <-> ";
        }
        l = sig(l);
    }

    cout << endl;
}

int main() {
    bool salir = false;
    bool creado = false;
    listade l;
    int opcion;

    do {
        cout << "\n\n 1 - crear lista\n";
        cout << " 2 - cons\n";
        cout << " 3 - snoc\n";
        cout << " 4 - pertenece\n";
        cout << " 5 - cantidad\n";
        cout << " 6 - eliminar\n";
        cout << " 9 - imprimir\n";
        cout << " 10 - imprimir inv\n";
        cout << " 11 - imprimir anteriores\n";
        cout << " 12 - imprimir siguientes\n";
        cout << " 13 - imprimir actual\n";
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
            if (creado) {
                cout << " - Valor a ingresar: ";
                cin >> opcion;
                l = cons(l, opcion);
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 3) {
            if (creado) {
                cout << " - Valor a ingresar: ";
                cin >> opcion;
                l = snoc(l, opcion);
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 4) {
            if (creado) {
                cout << " - Valor a buscar:";
                cin >> opcion;
                if (pertenece(l, opcion)) {
                    cout << opcion << " Si pertenece a la lista.";
                } else {
                    cout << opcion << " No pertenece a la lista.";
                }
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 5) {
            if (creado) {
                cout << " - La lista tiene " << cant(l) << " elementos.";
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 6) {
            if (creado) {
                cout << " - Valor a ingresar: ";
                cin >> opcion;
                imprimir(elim(l,opcion));
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 9) {
            if (creado) {
                imprimir(l);
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 10) {
            if (creado) {
                imprimir_inv(l);
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 11) {
            if (creado) {
                imprimir_ant(l);
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 12) {
            if (creado) {
                imprimir_sig(l);
            } else
                cout << " - Debe crear la lista para usar el comando.\n";
        } else if (opcion == 13) {
            if (creado) {
                cout << " - Actual: " << actual(l);
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
