#include<iostream>
#include<stdio.h>
using namespace std;
long int domino(int n){
	//Dn= 4*Dn-2- Dn-4
	long int t[n];
	if(n%2) return 0;
	switch(n){
		case 0: return 1;
		case 2: return 3;
		case 4: return 11;
		default:{
			t[2]=3;
			t[4]=11;
			for(int i=6; i<=n; i=i+2){
				t[i]=4*t[i-2]-t[i-4];
			}
			return t[n];
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	while(n!=-1){
		printf("%lu\n",domino(n));
		scanf("%d",&n);
	}
}
