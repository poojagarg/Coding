#include  <iostream>
#include <algorithm>
using namespace std;
void quickSort(int *a, int i, int j){
  if(i>=j){
    return;
  }
  int p=a[i];
  int e=i;
  int s=i-1;
  for(int z=i+1; z<=j ;z++){
    if(a[z]<p){
      swap(a[z],a[s+1]);
      s++;
      swap(a[z],a[e+1]);
      e++;
    }
    else if(a[z]==p){
      swap(a[z],a[e+1]);
      e++;
  
    }}
    if(s>i){
      quickSort(a,i,s);
    }
    if(j-e>1){
      quickSort(a,e+1,j);
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
  quickSort(a,0, n-1);
  print(a,n);
}
