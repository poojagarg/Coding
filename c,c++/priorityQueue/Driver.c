#ifndef STDIO_H_
	#define STDIO_H_
	#include<stdio.h>
#endif
#ifndef HEAP_H_
	#define HEAP_H_
	#include"heap.h"
#endif

int main(){
	heap* h=NULL;
	h=createHeap(15,-1);
	int A[]={3,5,1,8,19,10,6,2,11,53};
	//printf("%d, %d",h->capacity, h->type);
	//buildHeap(h,A,10);
	insert(h,24);
	insert(h,111);
	insert(h,32);
	insert(h,511);
	//printf("max: %d",deleteType(h));
	//printf("max: %d",deleteType(h));
	printf("after sorting");
	heapSort(h);
	int i; scanf("%d",&i);
return 0;
}
