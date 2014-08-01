#include<iostream>
#include<stdio.h>
using namespace std;
long int domino(int n){
	//Dn= 4*Dn-2- Dn-4
	long int t[n];
	switch(n){
		case 0: return 1;
		case 1: return 1;
		case 2: return 5;
		default:{
			t[1]=1;
			t[2]=5;
			for(int i=3; i<=n; i++){
				t[i]=t[i-1]+5*t[i-2];
				for(int j=i-3; j>0; j=j-2){
					t[i]+=2*t[i-3];
				}
				for(int j=i-4; j>0; j=j-2){
					t[i]+=3*t[i-3];
				}
			}
			}
			return t[n];
		}
	}
int main(){
	int n,a;
	scanf("%d",&n);
	int i=0;
	while(i<n){
		i++;
		scanf("%d",&a);
		printf("%d: %lu\n",a,domino(a));
	}
}
