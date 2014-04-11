#include<stdio.h>
#ifndef _ArrayStack_H
	#include"ArrayStack.h"
#endif

int main(){
	int i,size=5;
	ArrayStack* s=CreateStack(size);
	for(i=0; i<size; i++){
		Push(i*size,s);
	}
	for(i=0; i<size; i++){
		printf("%d \t",pop(s));
		}
	DeleteStack(s);
	}
