#include<iostream>
#include<stdio.h>
using namespace std;
long price(long p[],long n){
	long L[n];// l[i] represents maximum that can be saved from p[i,n-1], to find L[0]
	if(n>=1)
		L[n-1]=p[n-1];
	if(n>=2)		
		L[n-2]=p[n-1]+p[n-2];
	if(n>=3)		
		L[n-3]=p[n-1]+p[n-2]+p[n-3];
	
	switch(n){
		case 1: return L[n-1];
		case 2: return L[n-2];
		case 3: return L[n-3];
		default://n>3
		for(int i=4; i<=n; i++){
			L[n-i]=p[n-i]+L[n-i+2];
			L[n-i]=(p[n-i]+p[n-i+1]+((n-i+4)<n?L[n-i+4]:0))>L[n-i]?(p[n-i]+p[n-i+1]+((n-i+4)<n?L[n-i+4]:0)):L[n-i];
			L[n-i]=(p[n-i]+p[n-i+1]+p[n-i+2]+((n-i+6)<n?L[n-i+6]:0))>L[n-i]?(p[n-i]+p[n-i+1]+p[n-i+2]+((n-i+6)<n?L[n-i+6]:0)):L[n-i];
		}
		return L[0];
	}
}
int main(){
	int test;
	scanf("%d",&test);
	while(test){
		test--;
		long n;
		scanf("%lu",&n);
		long p[n];
		for(long i=0; i<n; i++){
			scanf("%lu",&p[i]);
			}
		printf("%lu\n",price(p,n));
	}
}
