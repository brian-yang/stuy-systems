GCC = gcc -g

all: main.o
	$(GCC) main.o -o pid

main.o: main.c
	$(GCC) -c main.c

clean:
	rm pid pid.log
	rm *.o
	rm *~

run: all
	./pid
