all: stage1exe

stage1exe: Driver.o AVL.o 
	gcc Driver.o AVL.o -o stage1exe

Driver.o: Driver.c
	gcc -c -w Driver.c
AVL.o: AVL.c
	gcc -c -w AVL.c

clean:
	rm -rf *o stage1exe
