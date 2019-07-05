que: enqthread.c main1.c queue.c
	gcc -g  -o que main1.c queue.c -I. -lpthread

clean:
	rm que 
