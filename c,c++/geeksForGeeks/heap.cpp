#include <iostream>
#include <algorithm>
using namespace std;
int minIndex(int i, int j, int A[]){
  return A[i]<A[j]?i:j;
}
void percolateDown(int *h,int n, int i){
  int k1=2*i+1;
  int k2=2*i+2;
  if(k1>n-1)
    return;
  int minI=k1;
  if(k1!=n-1){
    minI=minIndex(k1, k2, h);
  }
  if(h[minI]<h[i]){
    swap(h[minI],h[i]);
    percolateDown(h,n,minI);
  }
}
void heapify(int *h, int n){
  int s=(n-2)/2;
  for(; s>=0; s--){
    percolateDown(h,n,s);
  }
}
int deleteMin(int *h, int n){
  int d=h[0];
  h[0]=h[n-1];
  percolateDown(h,n-1,0);
  return d;
}
void percolateUp(int *h, int n, int e){
  h[n]=e;
  int p=(n-1)/2;
  while(p>=0&&h[p]>h[n]){
   swap(h[n],h[p]);
   n=p;
   p=(n-1)/2;
  }
}
int top(int *h){
  return h[0];
}
int main(){
  int n;
  cin>>n;
  int h[n];
  for(int i=0; i<n/2; i++){
    cin>>h[i];
    
  }
  n=n/2;
  heapify(h,n);
  int t;
  do{
    cin>>t;
    percolateUp(h,n,t );
    n++;
  }while(t!=-1);
  while(n!=0){
    cout<<deleteMin(h,n)<<endl;
    n--;
  }
}

