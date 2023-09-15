todo: main.o listacirc.o
	g++ -Wall -o main main.o listacirc.o
main.o: main.cpp
	g++ -Wall -c main.cpp
listacirc.o: listacirc.cpp listacirc.h
	g++ -Wall -c listacirc.cpp
clean:
	rm -f *.o
	rm -f main