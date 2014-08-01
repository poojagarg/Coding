#include <iostream>
#include <algorithm>
using namespace std;
void f(int *a, int n){
  if(n==1)
   return;
  if(n==2){
    swap(a[1],a[2]);
    swap(a[2],a[4]);
    swap(a[3],a[4]);
    return;
  }

  int s=n%3;
  int t1,t2,a1,a2,b1,b2,b3,b4;
  switch(s){
    case 1:t1=a[n-1];
           for(int i=n; i<2*n-1; i++){
            a[i-1]=a[i];
           }
           t2=a[2*n-1];
           for(int i=2*n; i<3*n-1; i++){
            a[i-2]=a[i];
           }
           a[3*n-3]=t1;
           a[3*n-2]=t2;
           //f(a,n-1);
           break;

    case 2:a1=a[n-2];
           a2=a[n-1];
           for(int i=n; i<2*n-2; i++){
            a[i-2]=a[i];
           }
           b1=a[2*n-2]; b2=a[2*n-1];
           for(int i=2*n; i<3*n-6; i++){
            a[i-5]=a[i];
           }
           a[3*n-6]=a1;
           a[3*n-5]=b1;
           a[3*n-4]=a2;
           a[3*n-3]=b2;
           f(a,n-2);
           break;
    case 0:for(int i=n/3; i<2*n/3; i++){
            swap(a[i],a[i+2*n/3]);
            swap(a[i+n/3],a[i+5*n/3]);
           }
           b3=5*n/3; b4=7*n/3;
           for(int i=0; i<n/3; i++){
            swap(a[i+b3],a[i+b4]);
           }
           f(a,n/3);
           f(a+n,n/3);
           f(a+2*n,n/3);
  }
}
void print(int *a, int n){

  for(int i=0; i<n; i++){
    cout<<a[i]<<'\t';
  }
}
int main(){
  int n;
  cin>>n;
  int a[3*n];
  for(int i=1; i<=n;i++){
    a[i-1]=i;
    a[n+i-1]=10*i;
    a[2*n+i-1]=100*i;
  }
  f(a,n);
  print(a,3*n);
}
