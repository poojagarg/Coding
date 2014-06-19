#include<iostream>
#include<cmath>
using namespace std;
double power(double a, int n) {
double ret = 1;
while(n) {
if(n%2 == 1) ret *= a;
a *= a; n /= 2;
}
return ret;
}

int power(int a, int n){
	if(n==0) return 1;
	if(n==1) return a;
	int v=a;
	int f=1; double m=sqrt(a);
	while(n>1){
		v=v*v;
		m=m*m;
		if(n%2==1){
			f=f*m;
		}
		n=n/2;
	}
	return v*f;
}
int main(){
	while(1){
		double a; int n;
		cin>>a>>n;
		if(a==-1)
			return 0;
		else
			cout<<power(a,n);
	}
}
