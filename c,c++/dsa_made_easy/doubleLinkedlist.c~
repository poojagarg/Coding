#include<stdio.h>

typedef struct doubleListNode{
	int data; 
	struct doubleListNode* next;
	struct doubleListNode* prev;
	}doubleListNode;

int doubleListLength(doubleListNode* head);
void deleteDoubleList(doubleListNode **head);
void insertInDoubleLinkedList(doubleListNode **head, int data, int position);
void deleteInDoubleLinkedList(doubleListNode **head, int postion);
void deleteDoubleList(doubleListNode **head);

int doubleListLength(doubleListNode* head){
	int count=0;
	while(head!=NULL){
		head=head->next;
		count++;
	}
	return count;
}
void insertInDoubleLinkedList(doubleListNode **head, int data, int position){
	if(position<1) 
		return;
	doubleListNode* temp=(doubleListNode*)malloc(sizeof(doubleListNode));
	temp->data=data;
	if(postion==1){
		temp->prev=NULL;
		temp->next=*head;
		*head=temp;
		return;
	}
	doubleListNode t=*head;
	while(position>2){
		t=t->next;
		position--;
	}
	temp->next=t->next;
	temp->prev=t->prev;
	t->next=temp;
}
void deleteInDoubleLinkedList(doubleListNode **head, int postion){
	doubleListNode *p;
	p=*head;
	if(postion==1){
		*head=*head->next;
		if(*head!=NULL)
			*head->prev=NULL;
		free(p);
		return;
	}
	doubleListNode t=*head;
	while(position>2){
		t=t->next;
		position--;
	}
	p=t->next;
	t->next=p->next;
	t->next->prev=t;
	free(p);
}
void deleteDoubleList(doubleListNode **head){
	doubleListNode *t=*head,*d;
	while(t){
		d=t;
		t=t->next;
		free(d);
	}
	*head=NULL;		
}
