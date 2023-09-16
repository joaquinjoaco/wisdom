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

int main()
{
    // ---------- Shared memory ----------
    int shm_fd;
    int *shm = 0;
    // crear memoria compartida
    shm_fd = shm_open("memoriacompartida", O_CREAT | O_RDWR, 0666);
    // configurar el tamaño de la memoria compartida 4096 bytes
    int SIZE = 4096;
    ftruncate(shm_fd, 4096);

    shm = (int *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    *shm = 10;

    // ------------------------------------

    // proceso
    int p = fork();
    if (p == 0)
    {
        // hijo (resta)
        int a = *shm;
        a--;
        for (int i = 1; i < 100000000; i++)
        {
            *shm = a;
        }
        printf("%d soy el hijo \n", *shm);
    }
    else
    {
        // ṕadre (suma)
        int b = *shm;
        b++;
        for (int i = 1; i < 100000000; i++)
        {
            *shm = b;
        }
        printf("%d soy el padre \n", *shm);
    }

    printf("%d soy el de afuera jeje \n", *shm);
    return 0;
}