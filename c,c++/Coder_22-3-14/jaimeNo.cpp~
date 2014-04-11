#include<cstdio>
#include<cmath>
using namespace std;
int jaime(int n){
	if(n==1) return 1;
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
	FILE* fp=fopen("jaime.txt","w");
	int t;
	scanf("%d",&t);	
	int i; int n;
	for(i=1; i<=t; i++){
		//scanf("%d",&i);
		fprintf(fp,"%d\n",jaime(i));
	}
	return 0;	
}
