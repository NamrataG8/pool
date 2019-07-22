CC =gcc
CFLAGS= -c -Wall
SOURCES = queue.c pool.c
OBJECTS =$(SOURCES:.c=.o)
OUT = libmypool.a
EXECUTABLE = staticlib

.c.o: $(SOURCES)
	$(CC) $(CFLAGS) -c $< -o $@

all:$(EXECUTABLE)

$(OUT): $(OBJECTS)
	ar rcs $(OUT) $(OBJECTS)

$(EXECUTABLE): main.c $(OUT)
	$(CC)  main.c $(OUT) -lpthread -o $(EXECUTABLE)

clean:$(EXECUTABLE)
	rm -rf $(EXECUTABLE) *.o $(OUT) 

