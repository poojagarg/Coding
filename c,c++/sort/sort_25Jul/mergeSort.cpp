#include  <iostream>
#include <algorithm>
using namespace std;
void merge(int *m, int s1, int e1, int s2, int e2);
void mergeSort(int *a, int i, int j){
  if(i>=j){
    return;
  }
  int mid=(i+j)/2;
  mergeSort(a, i, mid);
  mergeSort(a, mid+1, j);
  merge(a, i, mid,mid+1,j);
}
void merge(int *m, int s1, int e1, int s2, int e2){
  int a[e1-s1+1], b[e2-s2+1];
  for(int i=s1; i<=e1; i++){
    a[i-s1]=m[i];
  }
  for(int i=s2; i<=e2; i++){
    b[i-s2]=m[i];
  }

  int c=s1;
  e1=e1-s1;
  s1=0;
  e2=e2-s2;
  s2=0;
  while(s1<=e1&&s2<=e2){
    if(a[s1]<b[s2])
      m[c++]=a[s1++];
    else{
      m[c++]=b[s2++];
    }
  }
  while(s1<=e1){
    m[c++]=a[s1++];
  }
  while(s2<=e2){
    m[c++]=b[s2++];
  }
}
void print(int *a, int n){
  cout<<endl;
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
  mergeSort(a,0, n-1);
  print(a,n);
}
