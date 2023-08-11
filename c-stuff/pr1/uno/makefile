todo: main.o articulo.o
	g++ -Wall -o prog main.o articulo.o
main.o: main.c
	g++ -Wall -c main.c
articulo.o: articulo.h articulo.c
	g++ -Wall -c articulo.c
limpiar:
	rm -f *.o
	rm prog
