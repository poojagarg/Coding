#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n;
	int count=0;
	long v;
	scanf("%d",&n);
	scanf("%lu",&v);
	int j,t;
	int A[n];
	for(j=0; j<n; j++){
		A[j]=0;
	}	
	for(int j=0; j<n; j++){
		scanf("%d",&t);
		long temp;
		int i;
		for(i=0; i<t; i++){
			scanf("%lu",&temp);
			if(temp<v){
				A[j]=1;
				count++;
				i++;
				while(i<t){
					i++;
					scanf("%lu",&temp);
					}
				break;
			}
		}
	}
	printf("%d\n",count);	
	for(int i=0; i<n; i++){
		if(A[i]==1){
			printf("%d ",i+1);
		}
	}
}
