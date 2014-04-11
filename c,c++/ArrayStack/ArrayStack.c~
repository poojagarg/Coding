#ifndef _Stdio_h
	#include<stdio.h>
#endif
#ifndef _Stdlib_h
	#include<stdlib.h>
#endif
#ifndef _ArrayStackDef_H
	#include"ArrayStackDef.h"
#endif
#include<malloc.h>
ArrayStack* CreateStack(int StackSize){
	ArrayStack* a=(ArrayStack* )malloc(sizeof(ArrayStack));
	if(!a) return NULL;
	a->top=-1; a->capacity=StackSize;
	a->Array=(int*)malloc(a->capacity*sizeof(int));
	return a;
}
int IsEmpty(ArrayStack* s){if (s->top==-1) return 1; return 0;}
int IsFullStack(ArrayStack* s){if(s->top==s->capacity-1) return 1; return 0;}
void Push(int data, ArrayStack* s){if(!IsFullStack(s)) s->Array[++s->top]=data; else DoubleStack(s);}
int pop(ArrayStack* s){if(IsEmpty(s)) return -1; return s->Array[s->top--];}
int top(ArrayStack* s){return s->Array[s->top];}
void DeleteStack(ArrayStack* s){
	if(!s){if(!s->Array) free(s->Array);
		free(s);
	}
}
void DoubleStack(ArrayStack* a){a->capacity*=2; a->array=realloc(a->array, a->capacity);}
