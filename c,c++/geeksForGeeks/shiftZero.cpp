#include <iostream>
#include <algorithm>
using namespace std;
void f(int* a, int n){
  for(int k=0; k<n; k++){
    if(a[k]==0){
      int j;
      for( j=k+1; j<n; j++){
        if(a[j]!=0)
          break;
      }
      if(j==n)
        return;
      else{
        swap(a[k],a[j]);
      }
    }
    }
}
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
  f(a,n);
  print(a,n);
}

