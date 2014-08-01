#include <iostream>
using namespace std;
int *treeF;
int maxVal;
int readS(int idx){
  int sum=treeF[idx];
  int z=idx-(idx&-idx);
  idx--;
  while(z!=idx){
    sum-=treeF[idx];
    idx=idx-(idx&-idx);
  }
  return sum;
}
void update(int idx, int val){
  while(idx<=maxVal){
    treeF[idx]+=val;
    idx=idx+(idx&-idx);
  }
}
int read(int idx){
  int sum=0;
  while(idx>0){
    sum+=treeF[idx];
    idx-=idx&-idx;
  }
  return sum;
}
int main(){
  int n;
  cin>>n;
  treeF=new int[n+1];
  treeF[0]=0;
  maxVal=n;
  for(int i=0; i<n; i++){
    int t;
    cin>>t;
    update(i+1,t);
  }
  for(int i=1; i<=n; i++){
    cout<<"Read for"<<i<<read(i);
  }
}
