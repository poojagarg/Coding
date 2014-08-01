#include<iostream>
#include<cstdio>
#include<malloc.h>
#define size 45
#define range 30
#define For(i,n) for(int i=0; i<n; i++)
using namespace std;
void read(FILE* fp, int *A){
	int i=0;
	while(i<size){
		int d;
		char c;
		fscanf(fp,"%d%c",&d,&c);
		A[i]=d;
		i++;
	}
}
void print(int *a, int n){
	for(int i=0; i<n; i++){
		cout<<*(a+i)<<'\t';
	}
	cout<<"print\n";
}
int main(){
	int A[size];
	FILE* fp=fopen("sort.txt","r");
	read(fp,A);
	int S[range]={0};
	For(i, size){
		S[A[i]]++;
	}
	For(i, range){
		if(S[i]!=0)
			cout<<i<<":"<<S[i]<<'\t';
	}
}
