CFLAGS=-Wall -pedantic -std=c11 -I. -g

all: testOpen testPut testClose testGet testSearch testApply testCat

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

testCat: testCat.o queue.o
	gcc ${CFLAGS} queue.o testCat.o -o $@

testApply: testApply.o queue.o
	gcc ${CFLAGS} queue.o testApply.o -o $@

testhOpen: testhOpen.o queue.o hash.o
	gcc ${CFLAGS} hash.o testhOpen.o queue.o -o $@



clean:
	rm -f *.o testOpen testPut testClose testGet testSearch
