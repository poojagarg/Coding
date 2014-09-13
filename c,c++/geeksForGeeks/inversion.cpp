#include <iostream>
using namespace std;
int tree[20];
int read(int idx){
  int sum=0;
  while(idx>0){
    sum+=tree[idx];
    idx-=(idx&-idx);
  }
  return sum;
}
int maxVal;
void update(int idx, int val){
  while(idx<=maxVal){
    tree[idx]+=val;
    idx+=(idx&-idx);
  }
}
int readSingle(int idx){
  int sum=tree[idx];
  int z=idx-(idx&-idx);
  idx--;
  while(idx>z){
    sum-=tree[idx];
  }
  return sum;
}
void inversion(int* a, int n){
  update(a[n-1],1);
  int count=0;
  for(int i=n-2; i>=0; i--){
    count+=read(a[i]-1);
    update(a[i],1);
  }
  cout<<count<<'\t';
}
int main(){
  int n;
  cin>>n;
  int a[n];
  maxVal=INT_MIN;
  for(int i=0; i<n; i++){
    cin>>a[i];
    maxVal=maxVal>a[i]?maxVal:a[i];
  }
  inversion(a,n);
}
