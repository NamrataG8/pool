que: main.c queue.c
	gcc -g -Wall -o que main.c queue.c pool.c -I. -lpthread

clean:
	rm que 
