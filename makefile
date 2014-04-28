LinkedList: LinkedList.o
	gcc -g -m32 -Wall -o LinkedList LinkedList.o
	
LinkedList.o: LinkedList.c LinkedList.h
	gcc -c -m32 -Wall -g -o LinkedList.o LinkedList.c
	
.PHONY: clean

clean:
	rm *.o
