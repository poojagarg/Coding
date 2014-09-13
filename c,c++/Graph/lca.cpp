#include <iostream>
#include <algorithm>
using namespace std;
class node{
  public:
    int d;
    node *left, *right;
};
int contains(node* r, node* p){
 if(!r&&!p)
   return 1;
 else
   if(!r||!p)
     return 0;
   else
     if(r==p)
       return 1;
     else
       return contains(r->left,p)||contains(r->right,p);
}
int contains(node* r, node *p, node *q){
  return contains(r,p)&&contains(r,q);
}
node* lca(node *r, node* p, node* q){
  if(!r)
    return NULL;
  if(!p)
    return q;
  if(!q)
    return p;
  if(contains(r->left,p,q))
    return lca(r->left,p,q);
  if(contains(r->right,p,q))
    return lca(r->right,p,q);
  else
    return r;
}
int main(){
  
  }
