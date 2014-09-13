#include <iostream>
#include <queue>
using namespace std;
typedef queue<int> qi;
void push(qi& q, int i){
  q.push(i);
}
int top(qi &q1, qi &q2){
  int t=-1;
  while(!q1.empty()){
    t=q1.front();
    q2.push(t);
    q1.pop();
  }
  return t;
}
void pop(qi &q1, qi &q2){
  int t;
  if(q1.empty())
    return;
  while(true){
  t=q1.front();
  q1.pop();
  if(!q1.empty())
    q2.push(t);
  else 
    break;
}
}
enum operation{PUSH, POP, TOP};
int main(){
  qi q1,q2;
  int c;
  while(true){
  cin>>c;
  switch(c){
    case PUSH:int i;
              cin>>i;
              if(q1.empty()){
                push(q2,i);
              }
              else{
                push(q1,i);
              }
              break;
    case POP:if(q1.empty()){
              pop(q2,q1);
             }
             else{
              pop(q1,q2);
             }
             break;
    case TOP:if(q1.empty()){
              cout<<top(q2,q1)<<'\t';
             }
             else{
              cout<<top(q1,q2)<<'\t';
  }
             break;
    default: return 0;
  }
  }
}
