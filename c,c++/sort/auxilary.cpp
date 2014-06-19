#ifndef IOSTREAM
	#define IOSTREAM
	#include<iostream>
#endif
#ifndef STDIO
	#define STDIO
	#include<stdio.h>
#endif
using namespace std;
void print(int* A, int n){
	for(int i=0; i<n ; i++)
		cout<<A[i]<<'\t';
	cout<<'\n';
}
void swap(int *A, int index, int minIndex){
	if(index==minIndex) return;
	int temp=A[index];
	A[index]=A[minIndex];
	A[minIndex]=temp;
}
int binarySearch(int *A,int element, int i, int j){//A is sorted
	int size=(j-i+1);
	if(size<1)
		return -1;
	int mid=size/2;
	if(A[mid]==element)
		return mid;
	else if(A[mid]<element){
		binarySearch(A, element, mid+1, j);
	}
	else
		binarySearch(A, element, i,mid-1);
}
int linearSearch(int *A,int element, int i, int j){
	for(int a=i; a<=j; a++){
		if(element==A[a])
			return a;
	}
	return -1;
}
void insertionSort(int *A, int size){
	for(int i=1; i<size; i++){//i: index which is not yet sorted
		int temp=A[i];
		int j;
		for(j=i-1; j>=0; j--){
			if(temp<A[j]){
				A[j+1]=A[j];
			}
			else
				break;
		}
			A[j+1]=temp;
	}
}
void read(int *A, FILE *fp, int size){
	int i=0;
	while(i<size){
		int d;
		char c;
		fscanf(fp,"%d%c",&d,&c);
		A[i]=d;
		i++;
	}
	}
int maxIndex(int *A, int i, int j){
	if(A[i]>=A[j])
		return i;
	return j;
}
int minIndex(int *A, int i, int j){
	if(A[i]<=A[j])
		return i;
	return j;
}	
