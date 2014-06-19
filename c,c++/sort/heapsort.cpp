#include<iostream>
#include<cstdio>
#define heapSize 10
using namespace std;
int min(int *A,int i,int j, int size){
	if(j>=size||i>=size) return i;
	if(A[i]<=A[j])
		return i;
	return j;
}
void swap(int *A, int index, int minIndex){
	int temp=A[index];
	A[index]=A[minIndex];
	A[minIndex]=temp;
}
void bubbleDown(int *A, int index, int &size){
	while(true){
	if(index>(size-1)/2) return;
	int minIndex=min(A, 2*index+1, 2*index+2, size);
	if(A[minIndex]<A[index]){
		swap(A, index, minIndex);
		index=minIndex;
	}
	else return;
	}
}
void heapify(int *A, int size){
	for(int index=(size-1)/2; index>=0; index--){
		bubbleDown(A,index, size);
	}
}
void bubbleUp(int *A, int index){
while(true){
	if(index==0)	return;
	int parent=(index+1)/2-1;
	if(A[parent]>A[index]){
		swap(A,parent,index);
		index=parent;
		}
	else break;
	}
}
void insert(int *A, int element, int &size){
	A[size]=element;
	bubbleUp(A,size);	
	size++;
}
void deleteElement(int *A, int &size){
	size--;
	A[0]=A[size];
	bubbleDown(A, 0, size);
}
void heapSort(int *A, int size){
	while(size>1){
		cout<<A[0]<<'\t';
		deleteElement(A, size);
	}
	cout<<A[0]<<'\t';
}
int main(){
	int A[heapSize];
	FILE* fp=fopen("sort.txt","r");
	int i=0;
	while(i<heapSize){
		int d;
		char c;
		fscanf(fp,"%d%c",&d,&c);
		A[i]=d;
		i++;
	}
	heapify(A, heapSize);
	heapSort(A, heapSize);
}
