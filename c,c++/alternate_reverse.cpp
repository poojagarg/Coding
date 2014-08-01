#include <iostream>
#include <stack>
using namespace std;
class node{
  public:
    int d;
    node* next;
    node(int de,node* ne){
      d=de;
      next=ne;
    }
};
node* f(node* r){
  node* h=r;
  if(!r)
    return NULL;
  stack<node*> s;
  while(r){
    if(!r->next){
      break;
    }
    s.push(r->next);
    if(!r->next->next){
      break;
    }
    r->next=r->next->next;
    r=r->next;
  }
  while(!s.empty()){
    r->next=s.top();
    r=r->next;
    s.pop();
    }
  r->next=NULL;
  return h;
}
int main(){
  int n;
  cin>>n;
  node* h, *t;
  h=t=new node(0,NULL);
  for(int i=1; i<n; i++){
    t->next=new node(i,NULL);
    t=t->next;
  }
  f(h);
  t=h;
  while(t){
    cout<<t->d<<'\t';
    t=t->next;
  }
}
