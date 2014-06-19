#include<stdio.h>

typedef struct listNode{int data; struct listNode* next;}listNode;

int listLength(listNode* head);
void deleteList(listNode **head);
void insertInLinkedList(listNode **head, int data, int position);
void deleteInLinkedList(listNode **head, int postion);
void deleteList(listNode **head);
listNode* quickSortList(listNode* head);
listNode* insertionSortList(listNode* head);
listNode* mergeSortList(listNode* head);
listNode* mergeLists(listNode* head1, listNode* head2);
int listLength(listNode* head);
int containsLoop(listNode* head);
listNode* reverseItr(listNode* head);
listNode* reverseRec(listNode* head);
listNode* middleList(listNode* head);
listNode* mergeLists(listNode* head1, listNode* head2);

listNode* mergeSortList(listNode* head){
	if(!head) return NULL;
	if(!head->next) return head;
	listNode* m=middleList(listNode* head);
	listNode* newL=m->next;
	m->next=NULL;
	mergeSortList(newL);
	mergeSortList(head);	
	mergeLists(head, newL);
	return head;
}
listNode* quickSortList(listNode* head){
	listNode* equal=head;
	listNode* small=NULL;
	listNode* smallHead, *bigHead;
	listNode* big=NULL;
	listNode* temp=head->next;
	while(temp!=NULL){
		listNode* tempNext=temp->next;
		if(temp->data<head->data){
			temp->next=small;
			smallHead=temp;
		}
		if(temp->data==head->data){
			temp->next=equal;
			equalHead=temp;
		}
		else{
			temp->next=big;
			bigHead=temp;
		}
		temp=tempNext;
	}
	smallHead=quickSortList(smallHead);
	bigHead=quickSortList(bigHead);
	if(!smallHead){
		equal=equalHead;
		while(equal->next){
			equal=equal->next;
		}
		equal->next=bigHead;
		return equal;
	}
	small=smallHead;
	while(small->next){
		small=small->next;
	}
	small->next=equalHead;
	equal=equalHead;
	while(equal->next){
		equal=equal->next;
	}
	equal->next=bigHead;
	return smallHead;
}
listNode* reverseList(listNode* head,listNode* end){
	listNode *temp=head;
	listNode *prev=NULL;
	listNode* cur,*f;
	while(temp->next!=end){
		
	}
	
	return prev;
}
listNode* reverseK(listNode* head, int k){
	if(!head) return head;
	listNode* temp=head;
	listNode* tempHead=head;
	int count=1;
	while(count<k){
		count++;
		temp=temp->next;
		if(!temp)
			return head;
	}
	listNode* newHead=temp->next;
	head=reverseList(tempHead,temp);
	listNode* tail=tempHead;
while(newHead){
	count=1;
	tempHead=temp=newHead;
	while(count<k){
		count++;
		temp=temp->next;
		if(!temp)
			return head;
	}
	newHead=temp->next;
	tail->next=reverseList(tempHead, temp);
	tail=tempHead;
	}
	return head;
}
int listLength(listNode* head){
	int count=0;
	while(head!=NULL){
		head=head->next;
		count++;
	}
	return count;
}
int containsLoop(listNode* head){
	listNode *slow,*fast,
	slow=head; 
	if(head!=NULL)
		fast=head->next;
	else return 0;
	while(true){
	if(fast==NULL)
		return 0;
	if(fast->next==NULL)
		return 0;
	else{
		if(fast->next==slow||fast->next->next==slow) return 1;
		fast=fast->next->next;
		slow=slow->next;
		}
		}
}
listNode* reverseItr(listNode* head){
	listNode *t, *curr, *prev;
	prev=NULL;
	t=head;
	curr=head->next;
	while(curr){
		curr=t->next;
		t->next=prev;
		prev=t;
		t=curr;
	}
	t->next=prev;
	return t;
}
listNode* reverseRec(listNode* head){
	if(head==NULL)
		return NULL;
	if(head->next==NULL)
		return head;
	listNode* end=reverseRec(head->next);
	head->next->next=head;
	return end;
}
listNode* middleList(listNode* head){
	listNode *slow, *fast;
	slow=head;
	fast=head->next;
	while(true){
		if(fast==NULL){
			return slow;
		}
		if(fast->next==NULL){
			return slow;
		}
		else{
			fast=fast->next->next;
			slow=slow->next;
		}
	}
}
void displayListFromEndRec(listNode* head){
	if(head==NULL) return;
	displayListFromEndRec(head->next);
	printf("<%d>",head->data);
}
int isEven(listNode* head){
	while(head){
		if(head->next==NULL)
			return 0; //odd
		head=head->next->next;
	}
	return 1;
}
//pre-condition: list1 and list2 are sorted, in ascending order.
listNode* mergeLists(listNode* head1, listNode* head2){
	listNode* head;
	if(head1->data<head->data){
		head=head1;
		head1=head1->next;
	}
	else{
		head=head2;
		head2=head2->next;
		}
	listNode* temp=head;
	while(head1&&head2){
		if(head1->data<head2->data){
			temp->next=head1;
			temp=temp->next;
			head1=head1->next;
			}
		else{
			temp->next=head2;
			temp=temp->next;
			head2=head2->next;
		}
	}
	if(head1){
		temp->next=head1;
	}
	if(head2){
		temp->next=head2;
	}
	return head;
	}
listNode* reversePairItr(listNode* head){
	prev=NULL;
	listNode *t,*c,*N;
	listNode* newHead=head->next;
	t=head;
	while(t){
		c=t->next;
		if(t-next==NULL)
			return newHead;
		N=c->next;
		t->next->next=t;
		t->next=prev;
		prev=c;
		t=N;
	} 
	return newHead;
}
listNode* reversePairRec(listNode* head){
	if(!head) return NULL;
	if(head->next==NULL){
		return head;
	}
	listNode* newHead=head->next;
	listNode* n=head->next->next;
	listNode* nH=reversePairRec(n);
	head->next=nH;
	newHead->next=head;	
	return newHead;
}
int lengthLoop(listNode* head){
	listNode* slow, *fast;
	slow=head;
	if(head!=NULL)
		fast=head->next;
	else
		return NULL;
	while(true){
	if(fast==NULL)
		return NULL;
	if(fast->next==NULL)
		return NULL;
	else{
		if(fast->next==slow){
			fast=fast->next; 
			break;
		}
		if(fast->next->next==slow) {
			fast=fast->next->next;
			break;
		}
		fast=fast->next->next;
		slow=slow->next;
		}
		}
	slow=slow->next;
	int count=1;
	while(slow!=fast){
		count++;
		slow=slow->next;
	}
	return count;	
		}
listNode* beginLoop(listNode* head){
	listNode* slow, *fast;
	slow=head;
	if(head!=NULL)
		fast=head->next;
	else
		return NULL;
	while(true){
	if(fast==NULL)
		return NULL;
	if(fast->next==NULL)
		return NULL;
	else{
		if(fast->next==slow){
			fast=fast->next; 
			break;
		}
		if(fast->next->next==slow) {
			fast=fast->next->next;
			break;
		}
		fast=fast->next->next;
		slow=slow->next;
		}
		}
	slow=head;
	while(slow!=fast){
		slow=slow->next;
		fast=fast->next;
	}
	return slow;	
}
void insertInLinkedList(listNode **head, int data, int position){
	listNode* t=(listNode*)malloc(sizeof(listNode));
	t->data=data;
	if(position==1){
		t->next=*head;
		*head=t;
		return;
		}
	listNode *p=*head; 	
	while(position>2){
		position--;
		if(p==NULL){
			printf("not possible to insert at position %d because no. of elements are less",position);
			return;
		}
		p=p->next;
	}
	t->next=p->next;
	p->next=t;	
}
void deleteInLinkedList(listNode **head, int postion){
	if(*head==NULL) return;
	listNode *p=*head;
	if(position==1){
		*head=p->next;
		free(p);
	}
	while(position>2){
		if(p==NULL){
			printf("not possible to delete at position %d because no. of elements are less",position);
			return;
		}
		p=p->next;
		position--;
	}
	listNode* del=p->next;
	p->next=del->next;
	free(del);
}
void deleteList(listNode **head){
	listNode *p,*q;
	p=*head;
	while(p!=NULL){
		q=p;
		p=p->next;
		free(q);
	}
	*head=NULL;
}
