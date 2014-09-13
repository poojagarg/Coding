#include <iostream>
#include <cstring>
using namespace std;
void print(int *a, int n){
  for(int i=0; i<n-1; i++)
    cout<<a[i]<<'\t';
  cout<<a[n-1]<<endl;
}
void f(int n){
  int a[n];
  memset(a,0, sizeof(a));
  int k=0, t=1;
  for(int i=0; i<n; i++){
    if(k==t){
      while(a[i]!=0){
        i++;
        if(i==n)
          i=0;
      }
      a[i]=t;
      k=0;
      t++;
    if(t>n)
      break;
    }
    else if(a[i]==0)
          k++;
    if(i==n-1)
      i=-1;
  }
  print(a,n);
}
int main(){
  int n,t;
  cin>>t;
  while(t--){
    cin>>n;
    f(n);
  }
}
