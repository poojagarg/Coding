#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
int main(){
	int n, m, k;
	scanf("%d",&m);
	scanf("%d",&n);
	scanf("%d",&k);
	int i;
	for(i=0; i<k-1; i++){
		printf(" %d %d %d",1,(i/n+1),i%n+1);
	}
	int x=i/n+1; 
	int y=i%n+1;
		printf("%d",m*n-k+1);
	while(x<=n){
		if(y!=n){
		for(int i=y; i<=n; i++){
			printf("%d %d ",x,i);
			}
			y=n;
			x++;
		}
		else{
			for(int i=n; i>0; i--){
				printf("%d %d ",x,i);
			}
			x++;
		}
		}
	}