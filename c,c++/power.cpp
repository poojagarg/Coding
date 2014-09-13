#include <iostream>
using namespace std;
int f(int a, int n){
  int ret=1;
  while(n){
    if(n&1)
      ret*=a;
    a=a*a;
    n=n>>1;
  }
  return ret;
}
int main(){
  int p, n;
  cin>>p>>n;
  while(n!=0){
    cout<<f(p,n)<<'\t';
    cin>>p>>n;
  }
}
