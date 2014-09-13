#include <iostream>
#include <set>
using namespace std;
typedef set<int> si;
void f(int *a, int n, int sum){
  si s;
  s.insert(a[0]);
  for(int i=1; i<n; i++){
    s.insert(a[i]);
    if(s.find(sum-a[i])!=s.end()){
      cout<<a[i]<<'\t'<<sum-a[i]<<endl;
    }
  }
}
int main(){
  int n;
  cin>>n;
  int sum;
  cin>>sum;
  int a[n];
  for(int i=0; i<n; i++){
    a[i]=i+1;
  }
  f(a,n,sum);
}
