GCC = gcc -g

all: execute.o
	$(GCC) execute.o -o command

execute.o: execute.c
	$(GCC) -c execute.c

run: all
	./command

clean:
	rm -f command *.o *~

valgrind:
	valgrind ./command --leak-check=full
