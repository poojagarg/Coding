#include <iostream>
#include <queue>
using namespace std;
class node{
  public:
    int d;
    node* parent;
    int level;
    node* l, *r;
    node(node* lf, node* rf, int data){
      d=data;
      l=lf;
      r=rf;
    }
};
node* lca(node* r, node *p, node* q){
  if(!r)
    return NULL;
  if(r==p||r==q)
    return r;
  node* lh=lca(r->l,p,q);
  node* rh=lca(r->r,p,q);
  if(lh&&rh)
    return r;
  else{
    if(!lh)
      return lh;
    else
      return rh;
  }
}

