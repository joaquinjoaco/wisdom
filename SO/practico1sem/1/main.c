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

// Escribir un programa que define un int en memoria compartida y un
// semaforo inicializado en 1. 
// gcc -o main main.c -lpthread -lrt
int main()
{

    // ---------- Semaphore ----------
    sem_t *sem;
    sem = sem_open("sem.txt", O_CREAT, 0644, 1); // inicilizado en 1
    // --------------------
    sem_wait(sem);
    // sección crítica
    sem_post(sem);
    // --------------------
    sem_close(sem);
    sem_unlink("sem.txt");
    // -------------------------------

    // ---------- Shared memory ----------
    int shm_fd;
    int *ptr;
    // crear memoria compartida
    shm_fd = shm_open("memoriacompartida", O_CREAT | O_RDWR, 0666);
    // configurar el tamaño de la memoria compartida 4096 bytes
    int SIZE = 4096;
    ftruncate(shm_fd, 4096);
    ptr = (int *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    // usar la memoria compartida
    *ptr = 5;
    // ---------------------
    close(shm_fd);
    shm_unlink("memoriacompartida");
    // -----------------------------------
}