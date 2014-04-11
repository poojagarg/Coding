#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	if(n==0)
		{printf("1"); return 0;}
	if(n%2==1)
		printf("4");
	int i;
	for(i=0; i<n/2; i++)
		printf("8");
	return 0;
}	
