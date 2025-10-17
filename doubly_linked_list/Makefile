all: run

list: Animal.o PairsLL.o test.o
	g++ Animal.o PairsLL.o test.o -o test

Animal.o: Animal.h Animal.cpp
	g++ -Wall -Wextra -c Animal.cpp

PairsLL.o: PairsLL.h PairsLL.cpp
	g++ -Wall -Wextra -c PairsLL.cpp

test.o: test.cpp
	g++ -Wall -Wextra -c test.cpp

run: list
	./test

clean:
	rm -f *.o test