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
// a 0) y luego crea un proceso hijo. Se deben definir los semaforos
// necesarios. El hijo espera un tiempo aleatorio, coloca su pid en la
// memoria compartida, le avisa al padre y se duerme. El padre duerme
// hasta que el hijo le avisa que ya coloco su pid en la memoria compartida.
// Al despertar el padre imprime el pid del hijo desde la memoria
// compartida, escribe su pid en m.c. y le avisa al hijo. Éste se despierta e
// imprime el pid del padre desde la mc.

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

    // ---------- Semaphore sc & p & h ----------
    sem_t *sem_sc, *sem_p, *sem_h;
    sem_sc = sem_open("sem.txt", O_CREAT, 0644, 1); // sem shm inicilizado en 1
    sem_p = sem_open("sem1.txt", O_CREAT, 0644, 1); // sem padre inicilizado en 1
    sem_h = sem_open("sem2.txt", O_CREAT, 0644, 1); // sem hijo inicilizado en 1
    // -------------------------------------

    // ---------- Procesos -----------------
    int proceso = fork();
    if (proceso < 0)
    {
        printf("Error al crear el proceso");
    }
    if (proceso == 0) // proceso hijo
    {
        printf("[Proceso hijo] pid: %d | ppid: %d \n", getpid(), getppid());

        srand(time(NULL));
        int random_sleep = rand() % 5;
        sleep(random_sleep); // espera un tiempo aleatorio

        sem_wait(sem_sc); // 0 mc
        *shm = getpid();  // se guarda el pid del hijo en mc
        sem_post(sem_sc); // 1 mc
        
        sem_post(sem_p); // se despierta al padre

        printf("[Proceso hijo] pid del padre: %d \n", *shm);
    }
    if (proceso > 0)
    { // proceso padre
        sem_wait(sem_p); // se duerme inicialmente
        printf("[Proceso padre] pid: %d | ppid: %d \n", getpid(), getppid());
        printf("[Proceso padre] pid del hijo: %d \n", *shm);

        // se guarda el pid del padre en mc
        sem_wait(sem_sc); // 0 mc
        *shm = getpid();
        sem_post(sem_sc); // 1 mc

        sem_post(sem_h); // despierta el hijo
        sem_wait(sem_p); // se duerme al padre
    }
    // -------------------------------------

    // se cierra la memoria compartida
    close(shm_fd);
    shm_unlink("memoriacompartida");

    return 0;
}