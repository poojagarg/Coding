#include  <iostream>
#include <algorithm>
using namespace std;
void bubbleSort(int *a, int n){
  while(n>1){
  for(int i=0; i<n-1; i++){
    if(a[i]>a[i+1]){
      swap(a[i],a[i+1]);
    }
  }
  n--;
  }
}
void print(int *a, int n){
  for(int i=0; i<n; i++){
    cout<<a[i]<<'\t';
  }
  
}
int main(){
  int a[10];
  int n;
  cin>>n; 
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  bubbleSort(a, n);
  print(a,n);
}
