all: forkin.o
	gcc -o test forkin.o

forkin.o: forkin.c
	gcc -c forkin.c

clean:
	rm *.o
	rm test

run:
	./test
