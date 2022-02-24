CC = gcc
CFLAGS = -g -Wall

OBJS = search.o delete.o edit.o main.o


main:$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf *.o
