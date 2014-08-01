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
  if(!r||!r->next)
    return r;
  node *prev=NULL, *cur=r;
  while(cur){
    node* f=cur->next;
    cur->next=prev;
    prev=cur;
    cur=f;
  }
  return prev;
}
node* f_rec(node* r){
  if(!r||!r->next){
    return r;
  }
  node* h=f_rec(r->next);
  r->next->next=r;
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
  h=f_rec(h);
  t=h;
  while(t){
    cout<<t->d<<'\t';
    t=t->next;
  }
}
