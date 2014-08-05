#include <iostream>
#include <algorithm>
using namespace std;

void print(int *a, int n){
  for(int i=0; i<n; i++)
    cout<<a[i]<<'\t';
}
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  f(a, 0, n-1);
  print(a,n);
}
