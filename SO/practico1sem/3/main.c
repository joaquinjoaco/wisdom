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

// Escribir un programa que define un int en memoria compartida (igualado
// a 0) y dos semaforos (inicializados en uno y en cero respectivamente) y
// luego crea un proceso hijo.
// gcc -o main main.c -lpthread -lrt

int main()
{
    // ---------- Semaphore 1 & 2 ----------
    sem_t *sem, *sem2;
    sem = sem_open("sem.txt", O_CREAT, 0644, 1);   // inicilizado en 1
    sem2 = sem_open("sem2.txt", O_CREAT, 0644, 0); // inicilizado en 0
    // --------------------------------------

    // -------W---- Shared memory ------------
    int shm_fd;
    int *ptr;
    // crear memoria compartida
    shm_fd = shm_open("memoriacompartida", O_CREAT | O_RDWR, 0666);
    // configurar el tamaño de la memoria compartida 4096 bytes
    int SIZE = 4096;
    ftruncate(shm_fd, 4096);
    ptr = (int *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    // usar la memoria compartida
    *ptr = 0;
    // ---------------------
    close(shm_fd);
    shm_unlink("memoriacompartida");
    // -----------------------------------

    // ---------- Proceso hijo -----------
    int proceso = fork();
    if (proceso > 0)
    {
        printf("[Proceso creado] pid: %d | ppid: %d \n", getpid(), getppid());
    }
    // -----------------------------------
}