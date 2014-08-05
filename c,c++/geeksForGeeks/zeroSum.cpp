#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
void f(int *a, int n){
  map<int, int> m;
  int sum=a[0];
  m[sum]=0;
  m[0]=-1;
  for(int i=1; i<n; i++){
   sum+=a[i];
   if(m.find(sum)!=m.end()){
     cout<<m[sum]<<"<>";
     break;
   }
   else{
    m[sum]=i;
   }
  }
}
void print(int *a, int n){
  for(int i=0; i<n; i++)
    cout<<a[i]<<'\t';
}
int main(){
  int n;
  int t;
  do{
    cin>>n;
    cin>>t;
  int a[n];
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  f(a,n);
  cout<<'\t';
  }while(t!=-1);
}
