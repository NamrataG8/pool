SRC = main.c queue.c pool.c
CFLAGS = -g -Wall -I. -lpthread 
BIN = que 
que: ${SRC}
	gcc -o ${BIN} ${SRC}  ${CFLAGS}
clean:
	- rm -f  ${BIN} 
