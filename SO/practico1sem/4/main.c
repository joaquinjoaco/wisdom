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

// Escribir un programa que define un int en memoria compartida (igualado
// a 0) y dos semaforos (inicializados según corresponda) y luego crea un
// proceso hijo. El hijo espera un tiempo aleatorio, coloca su pid en la
// memoria compartida y le avisa al padre. El padre duerme hasta que el
// hijo le avisa que ya coloco su pid en la memoria compartida. Al despertar
// el padre imprime el pid del hijo desde la memoria compartida. 

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
    // ------------------------------------

    // ---------- Semaphore 1 & 2 ----------
    sem_t *sem, *sem2;
    sem = sem_open("sem.txt", O_CREAT, 0644, 0);   // inicilizado en 1
    sem2 = sem_open("sem2.txt", O_CREAT, 0644, 1); // inicilizado en 1
    // -------------------------------------

    // ---------- Procesos -----------------
    int proceso = fork();
    if (proceso < 0) {
        printf("Error al crear el proceso");
    }
    if (proceso == 0) // proceso hijo
    {
        printf("[Proceso hijo] pid: %d | ppid: %d \n", getpid(), getppid());
        srand(time(NULL));
        int random_sleep = rand() % 5;
        sleep(random_sleep); // espera un tiempo aleatorio
        sem_wait(sem2); // 0
        *shm = getpid();
        sem_post(sem2); // 1
        sem_post(sem); // 1
    } 
    if (proceso > 0) { // proceso padre
        sem_wait(sem); // 0
        printf("[Proceso padre] pid: %d | ppid: %d \n", getpid(), getppid());
        printf("[Proceso padre] pid del hijo: %d \n", *shm);
    }
    // -------------------------------------

    // se cierra la memoria compartida
    close(shm_fd);
    shm_unlink("memoriacompartida");
}