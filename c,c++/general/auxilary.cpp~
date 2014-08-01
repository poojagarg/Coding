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
