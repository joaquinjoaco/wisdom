#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include <fcntl.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <time.h>

// Un restaurante sirve solo un plato, sopa de cebolla. En el restaurante
// trabajan 2 cocineros y 3 mozos. Entre el salón comedor y la cocina hay
// un mostrador, donde los cocineros van colocando los platos de sopa a
// medida que los van sirviendo y de donde los mozos retiran dichos platos
// para llevarlos a las mesas. En el mostrador caben exactamente 12
// platos. Modelar el comportamiento de los cocineros y de los mozos,
// considerando que el mostrador es compartido entre ambos.

// Sugerencias:
// • Identificar cual es el recurso compartido.
// • Identificar las posibles condiciones de error en el acceso a dicho
// recurso.
// • Identificar los procesos correspondientes a los distintos actores.

// gcc -o main main.c -lpthread -lrt
int main()
{
    // ---------- Shared memory ----------
    int shm_fd;
    int *mostrador = 0;
    // crear memoria compartida
    shm_fd = shm_open("memoriacompartida", O_CREAT | O_RDWR, 0666);
    // configurar el tamaño de la memoria compartida 4096 bytes
    int SIZE = 4096;
    ftruncate(shm_fd, 4096);

    mostrador = (int *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    *mostrador = 12;
    // ------------------------------------

    // 2 cocineros y 3 mozos, creamos 5 procesos
    for (int i = 0; i < 3; i++)
    //creamos 3 mozos
    {
        int p = fork();

        if (p == 0)
        { // estamos en el hijo (mozo)
        // mozo();
		printf("mozo pid: %d | ppid: %d \n", getpid(), getppid());
        exit(-1);
        }
        if (p > 0) {

        }

    }

    return 0;
}