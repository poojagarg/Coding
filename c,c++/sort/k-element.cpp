#ifndef IOSTREAM
	#define IOSTREAM
	#include<iostream>
#endif
#ifndef STDIO
	#define STDIO
	#include<stdio.h>
#endif
#include"auxilary.h"
#define arraySize 15
using namespace std;
int median(int *A,int a,int j){
	int B[5];
	int i;
	for(i=a; i<(a+5); i++){
		if(i>j) break;
		B[i-a]=A[i];
	}
	int n=i-a; 
	insertionSort(B,n);
	return B[n/2];
}
int pivot_MedianOfMedians(int* A, int i, int j);
int quickSelect(int* A, int i, int j,int k){
	if(k>j) return -1;
	if(j-i<1)
		return -1;
	int pivot_index=pivot_MedianOfMedians(A,i,j);
	swap(A,i, pivot_index);
	int pivot=A[i];
	int m=i-1;
	int e=i;
	int n=i+1;
	while(n<=j){
		if(A[n]<pivot){
			m++; e++;
			swap(A,m,n);
			swap(A,e,n);
		}
		else if(A[n]==pivot){
			e++;
			swap(A,e,n);
		}
		n++;
	}
	if(m!=i-1){
		swap(A,i,m);
		if(k>=m&&k<=e){
			return k;
		}
		else{
			if(k<m){
				quickSelect(A,i, m-1,k);
				}
			
			if(k>e){
				quickSelect(A,e+1,j,k);
				}
			}
			}
	else{
		if(k<=e){
			return k;
		}
		else{
			quickSelect(A,e+1,j,k);			
		}
	}
	}
int pivot_MedianOfMedians(int* A, int i, int j)	{
	int size=j-i+1;
	if(size<=5){
		int pivot=median(A,i,j);
		return linearSearch(A,pivot,i,j);
	}
	else{
		int B[size/5+size%5];
		int a;
		for(a=i; a<=j; a=a+5){
			B[(a-i)/5]=median(A,a,j);
		}
		int pivot=quickSelect(B, 0,(a-i-5)/5, (a-i-5)/10);
		return linearSearch(A,B[pivot],i,j);
	}
}
int main(){
	int A[arraySize];
	FILE* fp=fopen("sort.txt","r");
	read(A,fp, arraySize);
	int k;
	do{
	cout<<"k?";
	cin>>k;
	if(k==-1) break;
	print(A,arraySize);
	k=quickSelect(A, 0, arraySize-1,k);
	print(A,arraySize);
	cout<<"\tKth elt:"<<A[k]<<'\t';
	insertionSort(A,arraySize);
	print(A,arraySize);
	}while(1);
	}
