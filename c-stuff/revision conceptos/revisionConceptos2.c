#include <stdio.h>

// estructura 1
struct estr1 {
    int campo1;
    char campo2, campo3;
    int campo4[10];
};

// estructura 2
struct estr2 {
    struct estr1 camp1;
    int camp2;
};

void main() {
    struct estr2 e, arrE[20];
    struct estr1 e1;
};

// decir el tipo de las expresiones que se dan a continuación
// i. arrE[5] ------> struct estr2
// ii. e[0].camp1 ------>  struct estr1
// iii. arrE[1].camp1.campo1 ------> int
// iv. e[5].camp2 ------> int
// v. arrE[0].camp1.campo4 ------> int
// vi. arrE[0].camp1.campo4[8] ------>int en la posición 8
// vii. e1.campo4 ------> array de int
// viii. e1.campo3 ------> char