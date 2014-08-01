#include<iostream>
#include<cstdio>
#include<malloc.h>
#include<vector>
#include<cmath>
using namespace std;
#define For(i,n) for(int i=0; i<n; i++)
#define arraySize 20
#define range 30
typedef vector<int> vi;
typedef vector< vi > vvi;
void read(FILE* fp, int *A){
	int i=0;
	while(i<arraySize){
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
void init(vvi &bucket, int* A){
	For(i,arraySize){
		int n=A[i];
		bucket[n%10].push_back(A[i]);
	}
}
void print(vvi bucket){
	For(i, bucket.size()){
		For(j, bucket[i].size()){
			cout<<bucket[i][j]<<'\t';
		}
	}
}
int maximum(int *A){
	int max=A[arraySize-1];
	For(i,arraySize-1){
		if(A[i]>max)
			max=A[i];
	}
	return max;
}
int main(){
	int A[arraySize];
	FILE* fp=fopen("sort.txt","r");
	read(fp,A);
	vvi bucket(10);
	vvi bucket2(10);	
	init(bucket, A);
	int k=1;
	int max=maximum(A);
	int maxDigit=0;
	while(max!=0){max/=10; maxDigit++;}
	while(k<maxDigit){
	For(i,10){
		For(j, bucket[i].size()){
			int n=bucket[i][j];
			n=n/pow(10,k);
			bucket2[n%10].push_back(bucket[i][j]);
		}
	}
	bucket.clear();
	bucket=bucket2;
	bucket2.clear();
	bucket2.resize(10);
	k++;
	}
	print(bucket);
}
