GCC = gcc -g

compile: pipe_networking.o server.o client.o
	$(GCC) pipe_networking.o server.o -o server
	$(GCC) pipe_networking.o client.o -o client
server.o:
	$(GCC) -c server.c
client.o:
	$(GCC) -c client.c
pipe_networking.o:
	$(GCC) -c pipe_networking.c

clean:
	rm -f server client
	rm -f private wkp
	rm -f *.out *.o
