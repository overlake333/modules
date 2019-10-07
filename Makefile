CFLAGS=-Wall -pedantic -std=c11 -I. -g

all: testOpen testPut testClose

%.o: %.c %.h
	gcc ${CFLAGS} -c $<

testOpen: testOpen.o queue.o
	gcc ${CFLAGS} queue.o testOpen.o -o $@

testPut: testPut.o queue.o
	gcc ${CFLAGS} queue.o testOpen.o -o $@

testClose: testClose.o queue.o
	gcc ${CFLAGS} queue.o testClose.o -o $@

clean:
	rm -f *.o testOpen testPut testClose
