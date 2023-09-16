prog: main.o punto.o
	g++ -Wall -o prog main.o punto.o
main.o: main.cpp
	g++ -Wall -c main.cpp
punto.o: punto.h punto.cpp
	g++ -Wall -c punto.cpp
clean:
	rm -f *.o
	rm -f prog
