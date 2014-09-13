#include <iostream>
#include <algorithm>
using namespace std;
int max_;
int tree[1000000+1];
int read(int x){
 int sum=0;
  while(x>0){
    sum+=tree[x];
    x-=(x&-x);
  }
  return sum;
}

void update(int x, int val){
  while(x<=max_){
    tree[x]+=val;
    x+=(x&-x);
  }
}
int main(){
  int k;
    int n;
  scanf("%d%d",&max_,&k);
  for(int i=0; i<k; i++){
    cin>>n;
    update(n,1);
    cin>>n;
    update(n+1,-1);}
    int a[max_];
  for(int i=1; i<max_+1; i++){
    a[i-1]=read(i);
  }
  sort(a,a+max_);
  for(int i=0; i<max_; i++){
    cout<<a[i]<<'\t';
  }
  cout<<a[max_/2];
}
