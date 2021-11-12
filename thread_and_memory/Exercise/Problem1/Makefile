main: main.o ex1.o
	gcc main.o ex1.o -o main
main.o: main.c
	gcc -c main.c
ex1.o: ex1.h ex1.c
	gcc -c ex1.c
clean:
	rm -f *.o main
