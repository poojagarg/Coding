#include <iostream>
#include <stack>
using namespace std;
typedef stack<int> si;
void push(si &s, int i){
  s.push(i);
}
void pop(si &s1, si &s2){
  if(!s2.empty()){
    s2.pop();
    return;
  }
  if(s1.empty())
    return;
  while(true){
  int i=s1.top();
  s1.pop();
  if(s1.empty())
    return;
  s2.push(i);
  }
}
int top(si &s1, si& s2){
  if(!s2.empty())
    return s2.top();
  if(s1.empty())
    return -1;
  while(!s1.empty()){
    s2.push(s1.top());
    s1.pop();

  }
  return s2.top();
}
int main(){
  
}
