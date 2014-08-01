#include<iostream>
using namespace std;
void merge(int a[], int b[], int m, int n){
  int i=m-1, j=n-1, c=m+n-1;
  while(i>=0&&j>=0){
    if(a[i]>b[j]){
      a[c--]=a[i--];
    }
    else
      a[c--]=b[j--];
  }
  while(j>=0){
      a[c--]=b[j--];
  }
}
void print(int *a, int n){
  for(int i=0; i<n; i++)
    cout<<a[i]<<'\t';
}
int main(){
  int m,n;
  cin>>m>>n;
  int a[m+n];
  int b[n];
  for(int i=0; i<m; i++){
    cin>>a[i];
  }
  for(int i=0; i<n; i++){
    cin>>b[i];
  }
  merge(a,b,m,n);
  print(a, m+n);
}
