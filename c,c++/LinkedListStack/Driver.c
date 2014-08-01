#ifndef _LINKEDLISTSTACK_H
	#include"linkedlistStack.h"
#endif
#ifndef _STDIO_H
	#include<stdio.h>
#endif
linkedlistStack* create();
void push(int value,linkedlistStack* s);
int pop(linkedlistStack* s);
void deleteStack(linkedlistStack* s);
int main(){
	linkedlistStack* s=create();
	int i,size=5;
	for( i=0; i<size; i++)
		push(i,s);
	for( i=0; i<size; i++)
		printf("%d",pop(s));
	deleteStack(s);
	return 0;
}

