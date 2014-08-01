#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
void cw(int *a, int k, int n){
	int i=0;
	int prev, cur;
	prev=a[i];
	bool done[n];
	memset (done, 0, n);
	int count=0;
	while(count<k){
	if(!done[i]){
		count++;
		int l=(n-i)/k;
		int j;
		for(j=1; j<=l; j++){
			if(i+j*k==n) break;
			cur=a[i+j*k];
			a[i+j*k]=prev;
			prev=cur;
		}
		done[i]=1;
		if(i!=(i+j*k)%n){
			i=(i+j*k)%n;	
			cur=a[i];
			a[i]=prev;
			prev=cur;
			}
		else{
			a[(i+j*k)%n]=prev;
			i=0; 
			while(done[i]) i++;
			prev=a[i];
		}
	}
	}
}
void print(int *a, int n){
	for(int i=0; i<n; i++){
		cout<<a[i]<<'\t';
	}
}
void read(FILE* fp,int* a,int *n,int *k){
	fscanf(fp,"%d %d",n,k);	
	for(int i=0; i<*n; i++){
		fscanf(fp,"%d",&a[i]);
		}
}
int main(){
	int a[100];
	FILE* fp=fopen("numbers.txt","r");
	int n,k;
	read(fp,a,&n, &k);
	cw(a,k,n);
	print(a,n);
}
