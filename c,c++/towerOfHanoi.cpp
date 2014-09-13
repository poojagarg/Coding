#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
typedef stack<int> si;
void f(int n,si &m,si &a, si&r){
  if(n==1){
    r.push(m.top());
    m.pop();
    return;
  }
  f(n-1,m,r,a);
  r.push(m.top());
  m.pop();
  f(n-1,a,m,r);
}
void print(si &m){
  while(!m.empty()){
    cout<<m.top()<<'\t';
    m.pop();
  }
}
int main(){
  si m;
  int n;
  cin>>n;
  for(int i=0; i<n; i++){
    m.push(n-i);
  }
  si a,r;
  f(n,m,a,r);
  print(r);
  }
