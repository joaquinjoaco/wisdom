#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

// Modelar un juego de cartas donde participan 10 jugadores. Los jugadores
// deberán primero pensar la jugada y luego jugar, pero solo podrán hacerlo
// cuando les toque su turno (por orden de ubicación en la ronda).
// Se dispone del tipo carta y los siguientes procedimientos y funciones:
// typedef carta{
// int num; // valor numerico
// char palo; // o=oro, e=espada, b=basto, c=copa
// • carta pensar() : que ejecutada por el jugador piensa cual será la
// próxima jugada y retorna una carta (elegida aleatoriamente).
// Se debe implementar el tipo jugador y el árbitro usando semáforos. La
// jugada se muestra por pantalla.

// gcc -o main main.c -lpthread -lrt

// typedef struct carta {
//     int num;    // valor numerico
//     char palo;  // o=oro, e=espada, b=basto, c=copa
// };

// void pensar() {
//     srand(time(NULL));
//     int jugada = rand() % 10;
//     printf("pienso en %d \n", jugada);
// };

// int main() {
//     srand(time(NULL));

//     for (int i = 0; i < 5; i++)
//     // creamos 10 jugadores
//     {
//         int p = fork();
//         if (p == 0) {  // estamos en el hijo (jugador)
//             printf("mozo pid: %d | ppid: %d \n", getpid(), getppid());
//             int jugada = rand() % 10;
//             printf("pienso en %d \n", jugada);
//             exit(-1);
//         }
//         if (p > 0) {
//             // padre (no hacer nada)
//         }
//     }
//     return 0;
// }

int main() {
    for (int i = 1; i < 3; i++) {
        fork();
        fork();
    }
    printf("pelado\n");

    return 0;
}