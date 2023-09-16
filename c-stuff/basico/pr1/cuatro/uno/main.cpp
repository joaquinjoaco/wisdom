// A ciertos estudiantes se les dice que su calificaci´on final ser´a el
// promedio de las cuatro calificaciones m´as altas de entre las cinco que hayan
// obtenido en el curso. Escriba un procedimiento con cinco parametros de
// entrada (las calificaciones obtenidas) y un par´ametro de salida (el
// promedio) que lleve adelante el c´alculo.

#include <iostream>

using namespace std;

struct calificaciones {
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;
};

int promedio(calificaciones c) {
    return (c.a1 + c.a2 + c.a3 + c.a4 + c.a5) / 5;
};

int main() {
    calificaciones c1;
    int prom;

    c1.a1 = 10;
    c1.a2 = 6;
    c1.a3 = 6;
    c1.a4 = 10;
    c1.a5 = 6;

    prom = promedio(c1);

    cout << "Promedio: " << prom;
    cout << endl;

    return 0;
}