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
node* mergeAlt(node* h1, node* h2){
  while(h1&&h2){
    node* n1=h1->next;
    h1->next=h2;
    h2=h2->next;
    h1->next->next=n1;
    h1=n1;
  }
  return h2;
}
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
  node* h2=t=new node(n,NULL);
  cin>>n;
  for(int i=1; i<n; i++){
    t->next=new node(i+20,NULL);
    t=t->next;
  }
  h2=mergeAlt(h,h2);
  t=h;
  while(t){
    cout<<t->d<<'\t';
    t=t->next;
  }
  cout<<endl; 
  t=h2;
  while(t){
    cout<<t->d<<'\t';
    t=t->next;
  }
}
