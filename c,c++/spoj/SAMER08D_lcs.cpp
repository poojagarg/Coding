#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
int  maximum(int a, int b){
	return a>b? a:b;
}
int lcs(string x,string y, int k){
	int m=x.length();
	int n=y.length();
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
			int d=k;
			int f=0;
			if(x.substr(i-(d-1)-1,d).compare(y.substr(j-(d-1)-1,d))==0){
				f=1;
				while(x[i-(d-1)-1]==y[j-(d-1)-1]){
				d++;
				if(i<d||j<d)
					break;
					}
					}
				d--;
				if(f)
				{
				int max=0; int temp;
				for(int z=k; z<=d; z++){
					temp=L[i-z][j-z]+z;
					if(temp>max)
						max=temp;}
				L[i][j]=max;
					}
			else{
				L[i][j]=L[i-1][j]>L[i][j-1]?L[i-1][j]:L[i][j-1];
			}
		}
	}
	return L[m][n];
	
}
int main(){
	int k;
	string x,y;
	scanf("%d",&k);
	while(k!=0){
		cin>>x>>y;
		printf("%d\n",lcs(x,y,k));
		scanf("%d",&k);
	}
}
