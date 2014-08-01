all: stage1exe

stage1exe: Driver.o bst.o linkedlistStack.o
	gcc Driver.o bst.o linkedlistStack.o -o stage1exe

Driver.o: Driver.c
	gcc -c -w Driver.c
bst.o: bst.c
	gcc -c -w bst.c
linkedlistStack.o: linkedlistStack.c
	gcc -c -w linkedlistStack.c
clean:
	rm -rf *o stage1exe
