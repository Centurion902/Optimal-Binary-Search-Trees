CFLAGS = -g -ggdb3 -Wall -std=c11 -pedantic -Iinclude

all: A4q1 A4q2

A4q1: A4q1.o A4.o
	gcc ${CFLAGS} A4q1.o A4.o -o A4q1

A4q2: A4q2.o A4.o
	gcc ${CFLAGS} A4q2.o A4.o -o A4q2



A4q1.o: A4q1.c
	gcc ${CFLAGS} A4q1.c -o A4q1.o -c

A4q2.o: A4q2.c
	gcc ${CFLAGS} A4q2.c -o A4q2.o -c
	


A4.o: A4.c
	gcc ${CFLAGS} A4.c -o A4.o -c
	


clean:
	rm *.o *.so core