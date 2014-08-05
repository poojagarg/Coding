#include <iostream>
using namespace std;

void merge(int *a, int sa, int ea, int sb, int eb){
  int l=eb-sb+1;
 int b[l];
 for(int i=sb; i<=eb; i++)
   b[i-sb]=a[i];
 l--;
 while(ea>=sa&&l>=0){
  if(a[ea]>b[l]){
    a[eb--]=a[ea--];
  }
  else{
    a[eb--]=b[l--];
    }
 }
 while(ea>=sa){
  a[eb--]=a[ea--];
 }
 while(l>=0){
  a[eb--]=b[l--];
 }

}
void merge(int *a, int sa, int ea, int *b, int sb, int eb){
  int r[ea-sa+eb-sb+2];
  int c=0;
  int start=sa;
  while(sa<=ea&&sb<=eb){
    if(a[sa]<b[sb]){
      r[c++]=a[sa++];
    }
    else{
      r[c++]=b[sb++];
    }
  }
  while(sa<=ea){
    r[c++]=a[sa++];
  }
  while(sb<=eb){
    r[c++]=b[sb++];
    }
  for(int i=0; i<c; i++){
    a[start+i]=r[i];
  }
}
void mergeSort(int *a, int s, int e){
  if(s>=e)
    return;
  int mid=(s+e)/2;
  mergeSort(a,s,mid);
  mergeSort(a,mid+1,e);
  merge(a,s,mid,mid+1,e);
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
  mergeSort(a,0,n-1);
  print(a,n);
}

