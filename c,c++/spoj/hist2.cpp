#include<iostream>
#include<stdio.h>
using namespace std;
//pre-condition: array a is in ascending order, n= size of the array
int abs(int a) {
	return (a)<0?-1*(a):(a);}
int hist2(int *a, int n){
	int p=0;
	if(n==1)
		return 2*(a[0]);
	if(n==2)
		return (a[0]+a[1]+abs(a[1]-a[0])	);
	if(n==3){
		return 2*(a[1]+a[2]-a[0]);
		}
	int i, count;
	for(i=0, count=0; count<(n)/4; i=i+2, count++){
		p+=(a[n-i-1]+a[n-i-2])+(a[n-i-1]+a[n-i-2]-2*a[i]-2*a[i+1]);//(A[n-i-3]+A[n-i-4]-A[i]-A[i+1])
	}
	switch(n%4){
		case 0:p+=a[i-2]+a[i-1]+abs(a[i-1]-a[i-2]); break;
		case 1:p+=2*a[i]; break;
		case 2:p+=a[i]+a[i+1]+abs(a[i+1]-a[i]); break;
		case 3:p+=a[i+2]+a[i+1]+(a[i+1]-a[i]+a[i+2]-a[i]); break;
	}
	return p;
}
int pow(int a, int n){
	int ret=1;
	if(n==1) return a;
	if(n==0) return 1;
	while(n>=1){
		if(n%2) ret*=a;
		a*=a;
		n=n/2;
	}
	return ret;
}
void print(int *a, int n){
	for(int i=0; i<n; i++){
		printf("%d\t",a[i]);
	}
}
int main(){
	int n;
	int a[15];
	scanf("%d",&n);
	while(n!=0){
		scanf("%d",&a[0]);
		int temp;
		for(int i=1; i<n; i++){
			//insertion sort in ascending order
			scanf("%d",&temp);
			//cout<<temp<<",";
			int j;
			for(j=i-1; j>=0; j--){
				if(a[j]>temp){
					a[j+1]=a[j];
				}
				else break;
			}
				a[j+1]=temp;
		}
		//print(a,n);
		printf("%d %d\n",hist2(a,n)+2*n,pow(2,n/2)*(n%4?1:2));
		scanf("%d",&n);
	}
}
