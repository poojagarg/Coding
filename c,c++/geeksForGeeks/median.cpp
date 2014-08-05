#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef priority_queue<int, vi, greater<int> > minH;
typedef priority_queue<int > maxH;
int insert(int e, minH& n, maxH &x){
  if(n.empty()){
    n.push(e);
    return e;
  }
  if(x.empty()){
    x.push(e);
    return(n.top()+e)/2;
  }
  if(n.size()==x.size()){
    if(e<x.top()){
      int m=x.top();
      x.pop();
      x.push(e);
      e=m;
    }
    n.push(e);
    return n.top();
  }
  else{
    if(n.top()<e){
      int m=n.top();
      n.pop();
      n.push(e);
      e=m;
    }
    x.push(e);
    return (n.top()+x.top())/2;
  }
}
int main(){
  int t;
  minH n; maxH x;
  do{
    cin>>t; 
    cout<<insert(t,n,x)<<'\t';
  }while(t!=-1);
}
