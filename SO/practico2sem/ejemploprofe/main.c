#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>
#include <sys/ipc.h>

int main()
{	// Demostracion de una condicion de carrera.
	// Se colocan esperas activas grandes para forzar la cond. de carra
	// NO SE DEBE HACER EN PRODUCCION
	// es una BURRADA ENORME. solo se justifica para generar errores.
	const int SIZE = 4096;
	const int TOPE = 900000;
	const int CANT = 1000;

	int shm_fd,pid,i,a,j;
	int *ptr;
	
	srand(time(NULL));

	//Crear Memoria Compartida
	shm_fd = shm_open("shm1", O_CREAT | O_RDWR, 0666);

	//Configurar el tamaño de la memoria compartida
	ftruncate(shm_fd,SIZE);

	// Mapear la memoria compartida a la memoria del proceso
	ptr = (int*) mmap(0,SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
	if (ptr == MAP_FAILED) {
		printf("Falla al mapear\n");
		exit(-1);
	}
	*ptr=10;

	pid=fork();
	if(pid==0){   // Proceso Hijo - Suma 1 CANT veces
		for(i=0;i<CANT;i++){
			a=*ptr;
			printf("   Hijo lee : %d\n",a);
			a++;
			for(j=0;j<rand()%TOPE;j++); // Espera activa
			*ptr=a;
			printf("   Hijo graba: %d\n",a); // Espera activa
			for(j=0;j<rand()%TOPE;j++);
		}
		exit(0);
	} else { // Padre - Resta 1 CANT  veces
		for(i=0;i<CANT;i++){
			a=*ptr;
			printf("Padre lee: %d\n",a);
			a--;
			for(j=0;j<rand()%TOPE;j++); // Espera activa
			*ptr=a;
			printf("Padre graba: %d\n",a); // Espera activa
 			for(j=0;j<rand()%TOPE;j++);
		}
	}
	i=wait(NULL);
	printf("FIN: %d\n",*ptr);
	shm_unlink("shm1");
}
	

