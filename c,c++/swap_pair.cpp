
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
node* f(node* r);
int main(){
  int n;
  cin>>n;
  node* h, *t;
  h=t=new node(0,NULL);
  for(int i=1; i<n; i++){
    t->next=new node(i,NULL);
    t=t->next;
  }
  h=f(h);
  t=h;
  while(t){
    cout<<t->d<<'\t';
    t=t->next;
  }
}
node* f(node* r){
  if(!r) return NULL;
  node* h,*prev, *cur;
  if(!r->next)
    return r;
  else{
    h=r->next;
    r->next=h->next;
    h->next=r;
    prev=r;
    cur=r->next;
  }
  if(!cur)
    return h;
  while(cur->next){
    node* tmp=cur->next;
    cur->next=tmp->next;
    tmp->next=cur;
    prev->next=tmp;
    prev=cur;
    cur=prev->next;
    if(!cur)
      return h;
  }
  return h;
}
  

