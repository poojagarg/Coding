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
node* quickSort(node* h){
  if(!h||!h->next)
    return h;
  int p=h->d;
  node* j=h->next;
  node* prev=h;
  node* i=h;
  while(j){
    if(j->d>p){
      prev=j;
      j=j->next;
    }
    else{
      node* t=i->next;
      if(t==j){
        i=j;
        prev=j;
        j=j->next;
        continue;
      }
      i->next=j;
      j=j->next;
      prev->next=j;
      i->next->next=t;
      i=i->next;
    }
  }
  if(i==h){
    h->next=quickSort(h->next);
    return h;
  }
  else{
    node* hg=quickSort(i->next);
    i->next=NULL;
    node* hs=quickSort(h->next);
    node* tmp=end(hs);
    tmp->next=h;
    h->next=hg;
    return hs;
  }
}
int main(){
  int n;
  cin>>n;
  node* h, *t;
  h=t=new node(n,NULL);
  for(int i=1; i<n; i++){
    t->next=new node(rand()%(3*n),NULL);
    t=t->next;
  }
  h=quickSort(h);
  t=h;
  while(t){
    cout<<t->d<<'\t';
    node* f=t;
    t=t->next;
    delete(f);
  }
}
