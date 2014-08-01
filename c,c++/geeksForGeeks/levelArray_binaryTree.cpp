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
int f(node* r, node* p, node* q){
  queue<node*> q;
  if(!r||!p||!q){
    return 0;
  }
  node* dummy=new node(NULL, NULL, -1);
  q.push(r);
  q.push(dummy);
  int found=0;
  while(!q.empty()){
    node* t=q.top();
    q.pop();
    if(t!=dummy){
      int flag=0;
      if(t->l){
        if(t->l==p||t->l==q){
          found++;
          flag=1;
        }
        q.push(t->l);
      }
      if(t->r){
        if(t->r==p||t->r==q){
          found++;
          if(flag==1)
            return 0;
        }
        q.push(t->r);
        }

      if(found==2)
        return 1;
    }
    else{
      found=0;
      q.push(dummy);
    }
  }
  return 0;
}
node* lca(node* r, node* p,node* q){
  if(!r||!p||!q)
    return NULL;
  node* res;
  if((r->l==p&&r->r==q)||(r->l==q||r->r==p))
    return r;
  if(!(res=lca(r->l,p,q)))
    return res;
  else if(!(res=lca(r->r,p,q))){
    return res;
  }
  else return r;
