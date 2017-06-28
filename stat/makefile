all: stat.o
	gcc -o stat.out stat.o

stat.o: stat.c
	gcc -c stat.c

run: stat.out
	./stat.out

clean:
	make -i cleanH

cleanH:
	rm *~
	rm *.out
	rm *.o
