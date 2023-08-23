todo: main.o lista.o
	g++ -Wall -o main main.o lista.o
main.o: main.cpp
	g++ -Wall -c main.cpp
lista.o: lista.cpp lista.h
	g++ -Wall -c lista.cpp
clean:
	rm -f *.o
	rm -f main