#include<iostream>
#include<cmath>
using namespace std;
long jaime(long n){
	do{
	double d1=sqrt(n+1);
	double d2=(-1+sqrt(1+4*(n+1)))/2;
	
		if(fmod(d1,1)==0) return 2*d1-2;
		if(fmod(d2,1)==0) return 2*d2-1;
		else n++;
	}while(1);
	return 0;
}
int main(){
	int t;
	scanf("%d",&t);	
	int i; long n;
	for(i=0; i<t; i++){
		scanf("%ld",&n);
		printf("%ld\n",jaime(n));
	}	
}
