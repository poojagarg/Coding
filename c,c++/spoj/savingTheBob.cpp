#include<iostream>
#include<stdio.h>
#define div (1000000007)
using namespace std;
long save (long nod, int k){
	if(k==0){
		return 9;
	}
	long L[10][nod+1];	
	for(int i=0; i<10; i++){
		L[i][0]=0;
		L[i][1]=1;
	}
	for(int nd=2; nd<=nod; nd++){
		for(int j=0; j<=9; j++){
			L[j][nd]=0;
			for(int a=j+k; a<=9; a++){
				L[j][nd]+=L[a][nd-1];
				L[j][nd]=L[j][nd]%div;
			}
			for(int a=j-k; a>=0; a--){
				L[j][nd]+=L[a][nd-1];
				L[j][nd]=L[j][nd]%div;
			}
		}
	}
	long r=0;
	for(int i=1; i<=9; i++)	{
		r+=L[i][nod];
		r=r%div;
	}
	return r;	
}
int main(){
	int n;
	scanf("%d",&n);
	while(n){
		n--;
		long m;
		int k;
		scanf("%lu %d", &m,&k);
		printf("%lu\n",save(m,k));
	}
}
