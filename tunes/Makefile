compile: playlist.h linkedlist.h node.h
	gcc -c linkedlist.c
	gcc -c playlist.c
	gcc main.c linkedlist.o playlist.o -o tunes
run: tunes
	./tunes
clean:
	rm tunes *.o
