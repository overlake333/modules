CFLAGS=-Wall -pedantic -std=c11 -I. -g

all: testOpen testPut testClose testGet testSearch

%.o: %.c %.h
	gcc ${CFLAGS} -c $<

testOpen: testOpen.o queue.o
	gcc ${CFLAGS} queue.o testOpen.o -o $@

testPut: testPut.o queue.o
	gcc ${CFLAGS} queue.o testPut.o -o $@

testClose: testClose.o queue.o
	gcc ${CFLAGS} queue.o testClose.o -o $@

testGet: testGet.o queue.o
	gcc ${CFLAGS} queue.o testGet.o -o $@

testSearch: testSearch.o queue.o
	gcc ${CFLAGS} queue.o testSearch.o -o $@

testhOpen: testhOpen.o hash.o
	gcc ${CFLAGS} hash.o testhOpen.o -o $@

clean:
	rm -f *.o testOpen testPut testClose testGet testSearch
