CFLAGS=-Wall -pedantic -std=c11 -I. -g

all: testOpen

%.o: %.c %.h
	gcc ${CFLAGS} -c $<

testOpen: testOpen.o queue.o
	gcc ${CFLAGS} queue.o testOpen.o -o $@

clean:
	rm -f *.o testOpen
