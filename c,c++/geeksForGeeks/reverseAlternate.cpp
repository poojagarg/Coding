#include <iostream>
#include <stack>
using namespace std;
class node{
  public:
    int d;
    node* next;
    node(int de, node* nexte=NULL){
      d=de;
      next=nexte;
    }
};
void f(node* h){
  if(!h||!h->next)
    return ;
  node *t=h;
  stack<node*> s;
  while(t){
    if(t->next){
      s.push(t->next);
      if(t->next->next){
        t->next=t->next->next;
        t=t->next;
      }
      else{
        break;
      }
  
  }
    else
      break;
}
  while(!s.empty()){
    t->next=s.top();
    s.pop();
    t=t->next;
  
  }
  t->next=NULL;
  }
node* pairSwap(node* h){
  if(!h||!h->next)
    return h;
  node* t;
  t=h->next;
  h->next=pairSwap(t->next);
  t->next=h;
  return t;
}
node* merge(node* l1, node* l2){
  if(!l1||!l2)
    return l2;
  node* l2r=merge(l1->next, l2->next);
  node* s=l1->next;
  l1->next=l2;
  l2->next=s;
  return l2r;
}
int main(){
  int s;
  node *n;
  cin>>s;
  n=new node(0);
  for(int i=1; i<s; i++){
    n= new node(i,n);
  }
  cin>>n;
  node* n2=new node();
  n=pairSwap(n);
  node* t=n;
  while(t){
    cout<<t->d<<'\t';
    n=t;
    t=t->next;
    delete(n);
  }
}
