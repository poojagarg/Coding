#include<iostream>
#include<stdio.h>
using namespace std;
int increementEven(int *A,int i){
	while(A[i]%2==0) i++;
	return i-1;
}
int decreementOdd(int *A, int i){
	while(A[i]%2==1) i--;
	return i+1;
}
void print(int* A, int n){
	for(int i=0; i<n ; i++)
		cout<<A[i]<<'\t';
}
void swap(int *A, int index, int minIndex){
	int temp=A[index];
	A[index]=A[minIndex];
	A[minIndex]=temp;
}
void dutchNationalFlag(int A[], int n){
	int o, e;
	int i=0;
	while(A[i]%2==0) i++;
	e=i-1;
	i=n-1;
	while(A[i]%2==1) i--;
	o=i+1;
	for(int i=0; i<o; i++){
		if(A[i]%2==0)
			e++;
		else{
			swap(A,i,o-1); //o-1 is an even
			e=increementEven(A,i+1);
			o=decreementOdd(A,o-2);
			i=e;						
		}
	}
	print(A,n);
}
#define arraySize 10
int main(){
int A[arraySize];
	FILE* fp=fopen("sort.txt","r");
	int i=0;
	while(i<arraySize){
		int d;
		char c;
		fscanf(fp,"%d%c",&d,&c);
		A[i]=d;
		i++;
	}
	dutchNationalFlag(A, arraySize);
	}
