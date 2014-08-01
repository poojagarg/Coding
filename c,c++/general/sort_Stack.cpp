#include<iostream>
#include<stack>
using namespace std;
void f(stack<int>& m, stack<int>& r){
  if(m.empty())
    return;
  r.push(m.top());
  m.pop();
  while(!m.empty()){
    int t=m.top();
    m.pop();
    while(!r.empty()&&t>r.top()){
      m.push(r.top());
      r.pop();
    }
    r.push(t);
  }
  while(!r.empty()){
    cout<<r.top();
    r.pop();
  }
}
int main(){
  int n;
  cin>>n;
  stack<int> m,r;
  for(int i=0; i<n; i++){
    cin>>n;
    m.push(n);
  }
f(m,r);
}

