#include  <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
void insertionSort(int *a, int n){
  for(int i=1; i<n; i++){
    int e=a[i];
    int j;
    for(j=i-1; j>=0; j--){
      if(a[j]>e){
        a[j+1]=a[j];
        }
      else break;
    }
    a[j+1]=e;
  }
}
void print(int *a, int n){
  for(int i=0; i<n; i++){
    cout<<a[i]<<'\t';
  }
  
}
int main(){
  int n;
  FILE* fp=fopen("../sort.txt","r");
  if(!fp) return 0;
  fscanf(fp,"%d",&n);
  int a[n];
  for(int i=0; i<n; i++){
    fscanf(fp,"%d",&a[i]);
  }

  insertionSort(a, n);
  print(a,n);
}
