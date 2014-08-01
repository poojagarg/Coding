#include <iostream>
#include <algorithm>
using namespace std;
int *m,*a;
int f(int node, int b, int e){
  if(b==e){
    m[node]=a[b];
    return m[node];
  }
  if(b>e)
    return -1;
  int m1=f(2*node+1,b,(b+e)/2);
  int m2=f(2*node+2,(b+e)/2+1,e);
    m[node]=max(m1,m2);
    return m[node];
  }
int rmq(int i, int j, int b, int e, int node){
  if(b>e)
    return -1;
  if(b>=i&&e<=j)
    return m[node];
  else{
    if(b>j||e<i)
      return -1;
    else{
      int m1=rmq(i,j,b,(b+e)/2,node*2+1);
      int m2=rmq(i,j,(b+e)/2+1,e,node*2+2);
      return max(m1,m2);
    }
  }

}
int main(){
  int n;
  cin>>n;
  a=new int[n];
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  m=new int[2*n-1];
  int max=f(0,0,n-1);
  cout<<"max :"<<max;
  while(true){
    int i, j;
    cin>>i>>j;
    if(i==-1)
      break;
    cout<<rmq(i,j,0,n-1,0);
    
  }
}
