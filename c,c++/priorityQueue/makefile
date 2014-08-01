all: stage1exe

stage1exe: Driver.o heap.o 
	gcc Driver.o heap.o -o stage1exe

Driver.o: Driver.c
	gcc -c -w Driver.c
heap.o: heap.c
	gcc -c -w heap.c

clean:
	rm -rf *o stage1exe
