#include <iostream>
#include <stack>
using namespace std;
class node{
  public:
    int d;
    node *left, *right;
    node(int de, node* l=NULL, node* r=NULL){
      d=de;
      left=l;
      right=r;
    }
};
typedef stack<node*> sn;
void in(node* r){
  if(!r)
    return;
  sn s;
  while(true){
  while(r){
    s.push(r);
    r=r->left;
  }
  do{
  if(s.empty())
    return;
  r=s.top();
  s.pop();
  cout<<r->d<<'\t';
  }while(!r->right);
    r=r->right;
}
}
void pre(node *r){
  if(!r)
    return;
  sn s;
  while(true){
    while(r){
      cout<<r->d<<'\t';
      s.push(r);
      r=r->left;
    }
    if(s.empty())
      return;
    do{
      r=s.top();
      s.pop();
      if(r->right){
        break;
      }
    }while(!s.empty());
    if(r->right)
      r=r->right;
    else break;
  }

}
void post(node* r){
  if(!r)
    return;
  sn s;
  node* prev=NULL;
  while(true){
    while(r){
      s.push(r);
      r=r->left;
      }
    while(true){
      if(s.empty())
        return;
    node* t=s.top();
    if(t->right&&t->right!=prev){
       r=t->right;
       break;
    }
    else{
      cout<<t->d<<'\t';
      prev=t;
      s.pop();
    }
    }
  }
}
int max(int a, int b){
  return a>b?a:b;
}
int height(node* r){
  if(!r)
    return 0;
  else
    return max(height(r->left),height(r->right))+1;
}
node* insert(node* r, int d){
  if(!r)
    return new node(d);
  node* root=r;
  while(true){
    if(r->d<d){
    if(r->right)
      r=r->right;
    else{
      r->right=new node(d);
      return root;
  }
    }
  else{
    if(r->left)
      r=r->left;
    else{
      r->left=new node(d);
      return root;
    }
  }
  }
}
node*  max(node* r){
  if(!r)
    return NULL;
  while(r->right){
    r=r->right;
  }
  return r;
}
node* pred(node* r, int d){
  if(!r)
    return NULL;
  node* pred=NULL;
  while(r){
    if(r->d==d){
      node* t= max(r->left);
      if(t)
        return t;
      else
        return pred;
    }
  if(r->d>d){
    r=r->left;
  }
  else{
    pred=r;
    r=r->right;
  }
  }
  return pred;
}

node* dllToBST(node* head){
  if(!head)
    return NULL;
  int count=0;
  node* t=head;
  while(t){
    t=t->right;
    count++;
  }
  t=head;
  prev=NULL;
  count=count/2;
  while(count){
    count--;
    prev=t;
    t=t->right;
  }
  if(prev)
}
int main(){
  int n;

  node *r;
  cin>>n;
  r=NULL;
  for(int i=0; i<n; i++){
    int t;
    cin>>t;
    r=insert(r,t);
  }
/*  in(r);
  cout<<endl;
  pre(r);
  cout<<endl;
  post(r);*/
  //cout<<height(r);
  while(n!=-1){
    cin>>n;
    node* res=pred(r,n);
    if(res){
      cout<<res->d;
    }
    else{
      cout<<"No";
    }
  }
}
