#include<iostream>
#include<stdio.h>
using namespace std;
int elis(int *a, int k){
	int L[k];
	L[0]=1;
	int max=L[0];
	for(int i=1; i<k; i++){
		int temp=0;
		for(int j=i-1; j>=0; j--){
			if(a[j]<a[i])
				temp=temp>L[j]?temp:L[j];
		}
		L[i]=1+temp;
		max=max>L[i]?max:L[i];
	}
	return max;
}
int main(){
	int k;
	scanf("%d",&k);
	int A[k];
	for(int i=0; i<k ; i++){
		scanf("%d",&A[i]);
	}
	printf("%d",elis(A,k));
}
