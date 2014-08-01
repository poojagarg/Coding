#include<iostream>
using namespace std;
void print(int *a, int n){
  for(int i=0; i<n; i++){
    cout<<a[i]<<'\t';
  }
}
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  for(int i=0, j=n-1; i<j; i++, j--){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
  }
  print(a,n);
}

