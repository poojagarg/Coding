#ifndef _STDIO_H
	#include<stdio.h>
#endif
#ifndef _STDLIB_H
	#include<stdlib.h>
#endif
#ifndef  _LINKEDLISTSTACKDEF_H
	#include"linkedlistStackDef.h"
#endif
linkedlistStack* create(){
	linkedlistStack* s=(linkedlistStack*)malloc(sizeof(linkedlistStack));
	if(!s) return NULL;
	s->count=0;
	s->top=NULL;
	return s;
}
int isEmptyStack(linkedlistStack* s){
	if(s->top==NULL) return 1;
	else return 0;
}
void push(int value,linkedlistStack* s){
	node* n=(node*)malloc(sizeof(node));
	n->value=value;
	n->next=s->top;
	s->top=n;
}
int pop(linkedlistStack* s){
	if(s->top==NULL) return -1;
	else{
		int temp=s->top->value;
		node* tmp=s->top;
		s->top=s->top->next;
		free(tmp);
		return temp;		
	}
}
void deleteStack(linkedlistStack* s){
	if(s){
		node* tmp;
		tmp=s->top;
		while(tmp!=NULL){
			tmp=s->top;	
			s->top=s->top->next;
			free(tmp);
			}//end of while
		free(s);
		}//end of if
}
