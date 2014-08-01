#include <iostream>
using namespace std;
void print(int* l, int n){
 for(int i=0; i<n; i++){
  cout<<l[i]<<'\t';
 }
}
void find(int sum, int k, int s, int n, int *a, int *list){
  if(k==1){
    for(int i=s; i<n; i++){
      if(a[i]==sum){
        list[k-1]=a[i];
        print(list,n);
        return;
      }
    }
  }
  else{
    for(int i=s; i<n; i++){
      list[k-1]=a[i];
      find(sum-a[i],k-1,i+1,n,a,list);
    
    }
  }
}
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int k;
  int list[n];
  cin>>k;
  int sum;
  cin>>sum;
  find(sum,k,0,n,a,list);
}
