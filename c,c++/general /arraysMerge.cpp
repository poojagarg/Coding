#include<iostream>
#include<stdio.h>
#define arraySize 10
using namespace std;
void print(int* A, int n){
	for(int i=0; i<n ; i++)
		cout<<-1*A[i]<<'\t';
	cout<<'\n';
}
void f(int* A, int arraysize){
	print(A,arraysize);
	int n=arraysize/2;
	//int b[arraySize]={0};
	int i=1;
	int t=A[i];
	int t2;
	int count=0;
	while(count<arraySize-2){
		count++;
		/*if(b[i]==1){
			continue;
		}
		b[i]=1;*/
		if(t<0) continue;
		if(i<n){
			t2=A[2*i];
			A[2*i]=-1*t;
			i=2*i;
			t=t2;
		}
		else{
			t2=A[2*(i-n)+1];
			A[2*(i-n)+1]=-1*t;
			i=2*(i-n)+1;
			t=t2;
		}
	}
	//for i=(2n-1)/3, won't have been called, so call swap(A, i, 2i);
	print(A,arraysize);
	
}
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
	f(A, arraySize);
	}
