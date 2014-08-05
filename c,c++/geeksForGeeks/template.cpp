#include <iostream>
#include <algorithm>
using namespace std;
void f(int *a, int n){
  int x=a[0];
  int prev=a[0];
  int cur;
  for(int i=1; i<n; i++){
    cur=a[i]+max(prev, 0);
    if(x<cur){
      x=cur;
      }
    prev=cur;
  }
  cout<<x;
}
void print(int *a, int n){
  for(int i=0; i<n; i++)
    cout<<a[i]<<'\t';
}
int main(){
  int n;
  int t;
  do{
    cin>>n;
    cin>>t;
  int a[n];
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  f(a,n);
  cout<<'\t';
  }while(t!=-1);
}
