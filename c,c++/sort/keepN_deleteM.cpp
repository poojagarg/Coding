#include <iostream>
#include <cstdlib>
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
node* end(node* r){
  if(!r||!r->next)
    return r;
  while(r->next){
    r=r->next;
  }
  return r;
}
node* fm(node* h, int m){//find mth node from h, including h
  while(h){
    if(m==1){
      return h;
    }
    else{
      m--;
      h=h->next;
    }
  }
  if(m==1){
    return h;
  }
  else{
    return NULL;
  }
}
int fn(node* h, int n){//delete n nodes, from h->next
  if(!h)
    return 0;
  node* t=h->next;
  while(t){
    node* b=t;
    t=t->next;
    delete(b);
    n--;
    if(n==0)
      break;
  }
  if(n==0){
    h->next=t;
    return 1;
  }
  else h->next=NULL;
  return 0;
}
void f(node* h, int m, int n){
  int r;
  do{
   node* t=fm(h,m);
   if(!t)
     return;
   r=fn(t,n);
   if(!t->next){
    return;
   }
   h=t->next;
  }while(r);
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
  f(h,3,2);
  t=h;
  while(t){
    cout<<t->d<<'\t';
    node* f=t;
    t=t->next;
    delete(f);
  }
}
