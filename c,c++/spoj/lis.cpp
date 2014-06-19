#include<iostream>
#include<stdio.h>
using namespace std;
int findIndex(long int e,long int *b, int l){
	for(int i=l; i>=0; i--){
		if(b[i]==e)
			return i;
	}
	return -1;
}
int lis(long int* a,long int *b, int l){
	int max=0;
	int L[l][l];
	for(int i=0; i<l; i++){
		for(int j=0; j<l;j++){
			if(a[i]==b[j]){
				int temp=0;
				for(int x=i-1;x>=0; x--){
					if(a[x]<a[i]){
						int r=findIndex(a[x],b, j-1);
						if(r>-1){
							temp=temp<L[x][r]?L[x][r]:temp;
							}	
					}
				}
				for(int x=j-1;x>=0; x--){
					if(b[x]<b[j]){
						int r=findIndex(b[x],a, i-1);
						if(r>-1){
							temp=temp<L[r][x]?L[r][x]:temp;
							}	
					}
				}
				L[i][j]=temp+1;
			}
			else {
				L[i][j]=0;
				}
			max=L[i][j]>max?L[i][j]:max;
		}
	}
	return max;
}
int main(){
	int k;
	scanf("%d",&k);
	long int A[k], B[k];
	for(int i=0; i<k ; i++){
		scanf("%lu %lu",&A[i],&B[i]);
	}
	printf("%d",lis(A,B,k));
}
