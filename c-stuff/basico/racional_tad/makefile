prog: main.o racional.o
	g++ -Wall -o prog main.o racional.o
main.o: main.cpp
	g++ -Wall -c main.cpp
racional.o: racional.h racional.cpp
	g++ -Wall -c racional.cpp
clean:
	rm -f *.o
	rm -f prog
