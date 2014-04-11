#ifndef _STDIO_H
	#include<stdio.h>
#endif
#ifndef _STDLIB_H
	#include<stdlib.h>
#endif
#ifndef  _LINKEDLISTSTACKDEF_H
	#include"linkedlistStackDef.h"
#endif
#ifndef BSTDEF_H_
	#define BSTDEF_H_
	#include"bstDef.h"
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
void push(binarySearchNode* value,linkedlistStack* s){
	node* n=(node*)malloc(sizeof(node));
	n->value=value;
	n->next=s->top;
	s->top=n;
}
node* findMiddle(node* s){//send parent of middle(for 7 and 6, it will send 3rd element)
	if(s==NULL) return s; //0 elements
	if(s->next==NULL) return s; //1 element
	node* t=s;
	int count=0;
	while(t!=NULL) {t=t->next; count++;}
	int tmp=count/2;
	while(tmp>1){s=s->next; tmp--;}
return s;
}
binarySearchNode* pop(linkedlistStack* s){
	if(s->top==NULL) return -1;
	else{
		binarySearchNode* temp=s->top->value;
		node* tmp=s->top;
		s->top=s->top->next;
		free(tmp);
		return temp;		
	}
}
void display(node* n){
	printf("linkedList:");
	while(n){
		if(n->value!=NULL){
		printf("<%d>",n->value->data);}
		n=n->next;}
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
