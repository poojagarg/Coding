#ifndef HEAPDEF_H_
	#define HEAPDEF_H_
	#include"heapDef.h"
#endif
#ifndef STDIO_H_
	#define STDIO_H_
	#include<stdio.h>
#endif
int max(int A[], int a,int b, int max_ind){
	int max;
	if(a<=max_ind)
		max=a;
	if(b<=max_ind){
		if(A[max]<A[b])
			max=b;}//end of if
	return max;
}
heap* createHeap(int capacity, int type){
	heap* h=(heap*)malloc(sizeof(heap));
	h->array=(int*)malloc(capacity*sizeof(int));
	h->capacity=capacity;	
	h->count=0;
	h->type=type;  //type=1 (max), type=-1(min)
	return h;
}
void insert(heap* h, int data){//bubble up 
	int i=h->count;	
	h->array[i]=data;
	h->count++;
	while((i-1)/2>=0){
		if(((h->type)*h->array[(i-1)/2])<((h->type)*h->array[i])){//swap
			int temp=h->array[i];
			h->array[i]=h->array[(i-1)/2];
			h->array[(i-1)/2]=temp;	
			i=(i-1)/2;	
		}//end of swapping if
		else break;
}// end of while
}
void heapSort(heap* h){	
	while(h->count>0){
	printf("<%d>",deleteType(h));
}
}
int deleteType(heap* h){//bubble down
	if(h->count<1) return -1;	
	int ret=h->array[0];
	h->count--;
	h->array[0]=h->array[h->count];
	int i=0;
	while(h->count>2*i+1){
		int t=max(h->array, 2*i+1,2*i+2, h->count-1);
		if((h->array[i]*h->type)<(h->array[t]*h->type)){
			int temp=h->array[i];
			h->array[i]=h->array[t];
			h->array[t]=temp;
			i=t;
		}// end of if
		else break;
}//end of while	
	return ret;
}
int getType(heap* h){
	if(h->count<1) return -1;	
	return h->array[0];
}
void bubbleDown(heap* h, int i){
	while(h->count>2*i+1){//has atleast 1 child
		int t=max(h->array, 2*i+1,2*i+2, h->count-1);
		
		if((h->array[i]*(h->type))<(h->array[t]*(h->type))){
			//printf("swapping");
			int temp=h->array[i];
			h->array[i]=h->array[t];
			h->array[t]=temp;
			i=t;
		}// end of if
		else break;
	}//end of while
}//end of function
void buildHeap(heap* h, int A[], int n){
	if(h==NULL) return;
	if(h->capacity<n) return;
	int i;
	h->count=n;
	for(i=0; i<n; i++)
		h->array[i]=A[i];
	for(i=(n-1)/2; i>=0; i--){
		
		bubbleDown(h,i);
		
	}
}
void display(heap* h){
	int i;
	for(i=0; i<h->count; i++)
		printf("<%d>",h->array[i]);
}
void delHeap(heap* h){
	if(h==NULL) return;
	free(h->array);
	free(h);
}
