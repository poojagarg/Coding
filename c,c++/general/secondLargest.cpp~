#include"auxilary.h"
#ifndef IOSTREAM
	#define IOSTREAM
	#include<iostream>
#endif
#ifndef STDIO
	#define STDIO
	#include<stdio.h>
#endif	
#define arraySize 8
using namespace std;
void secondLargest(int *A, int n){
for(int inc=2; inc<=n/2; inc*=2){
	for(int i=0; i<n; i+=inc){
		if((i+inc/2)<n){
		int r=maxIndex(A, i, i+inc/2);
		A[i]=A[r];
		}
		else break;		
	}
	/*cout<<"for inc:"<<inc<<'\n';
	print(A,n);*/
	}
	int r=minIndex(A, 0,n/2);
	cout<<A[r]<<": 2nd largest\n";
	//print(A,n);
}
int main(){
	int A[arraySize];
	FILE* fp=fopen("sort.txt","r");
	read(A, fp, arraySize);
	secondLargest(A, arraySize);
}
