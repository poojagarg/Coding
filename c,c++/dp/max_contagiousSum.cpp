#include <iostream>
#include <utility>
using namespace std;
typedef pair<int, int> ii;
ii m[100];
ii f(int a[], int n,int &ind){
  m[0]=ii(a[0],0);
  ii max=m[0];
  ind=0;
  for(int i=1; i<n; i++){
    if(m[i-1].first>0){
      m[i]=ii(m[i-1].first+a[i],m[i-1].second);
    }
    else
      m[i]=ii(a[i],i);
    if(m[i].first>max.first){
      max=m[i];
      ind=i;
    }
  }
  return max;
}
int main(){
  int a[100];
  int n;
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  int ind;
  ii p=f(a,n,ind);
  cout<<p.first<<","<<p.second<<","<<ind;
}    
   

