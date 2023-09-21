todo: main.o listade.o
	g++ -Wall -o main main.o listade.o
main.o: main.cpp
	g++ -Wall -c main.cpp
listade.o: listade.cpp listade.h
	g++ -Wall -c listade.cpp
clean:
	rm -f *.o
	rm -f main
