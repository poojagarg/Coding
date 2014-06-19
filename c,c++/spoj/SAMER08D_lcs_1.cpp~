#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
int  maximum(int a, int b){
	return a>b? a:b;
}
int length(char* s){
	int i=0;
	char* p=s;
	while(*s!='\0') {
		i++;
		s++;
	}
	//printf("<Length of %s: %d>",p,i);
	return i;
}
int compareString(char* x, char *y, int i, int j){
	int count=0;
	while(x[i]==y[j]){
		count++;
		i--; j--;
		if(i<0|j<0)
			break;
	}
	return count;
}
int lcs(char* x,char* y, int k){
	int m=length(x);
	int n=length(y);
	//cout<<m<<':'<<n;
	if(m<k||n<k)
		return 0;
	int L[m+1][n+1];
	//initialize
	for(int i=0; i<k; i++){
		for(int j=0; j<=n; j++)
			L[i][j]=0;
			}
	for(int i=k; i<=m; i++){
		for(int j=0; j<k; j++)
			L[i][j]=0;
			}
	//end of initialize 		
	/*for(int i=k; i<=m; i++){
		if(x.substr(i-(k-1),k).compare(y.substr(1,k))==0)
			L[i][k]=k;
			}
	for(int i=k;i<=n; i++){			
		if(x.substr(1,k).compare(y.substr(i-(k-1),k))==0)
			L[k][i]=k;			
	}*/
	for(int i=k; i<=m; i++){
		for(int j=k; j<=n; j++){
			int d=compareString(x,y,i-1,j-1);
			L[i][j]=L[i-1][j]>L[i][j-1]?L[i-1][j]:L[i][j-1]; 
			int temp;
			for(int z=k; z<=d; z++){
				L[i][j]= (L[i-z][j-z]+z)>L[i][j]?(L[i-z][j-z]+z):L[i][j];
				}
			}
		}
	return L[m][n];
}
int main(){
	int k;
	char x[1000],y[1000];
	scanf("%d",&k);
	while(k!=0){
		scanf("%s",x);
		scanf("%s",y);		
		printf("%d\n",lcs(x,y,k));
		scanf("%d",&k);
	}
}
