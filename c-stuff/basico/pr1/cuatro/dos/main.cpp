// Idem a 1) donde las calificaciones se pasan en un array.

#include <iostream>

using namespace std;

int promedio(int cal[]) {
    int i, aux = 0;

    for (int i = 0; i < 5; i++) {
        aux += cal[i];
    }

    return aux / 5;
};

int main() {
    int calificaciones[5] = {10, 10, 6, 6, 6};
    int prom;

    prom = promedio(calificaciones);

    cout << "Promedio: " << prom;
    cout << endl;

    return 0;
}