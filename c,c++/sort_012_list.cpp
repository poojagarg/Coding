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
node* f(node* h){
  if(!h||!h->next)
    return h;
  node* h_[3],*l[3];//head and last
  h_[0]=h_[1]=h_[2]=l[0]=l[1]=l[2]=NULL;
  int flag[3]={0};
  while(h){
    switch(h->d){
      case 0:if(!h_[0]){
              h_[0]=l[0]=h;
              flag[0]=1;
             }
             else{
              l[0]->next=h;
              l[0]=h;
              l[0]->next=NULL;
             }
             break;
             
      case 1:if(!h_[1]){
              h_[1]=l[1]=h;
              flag[1]=1;
             }
             else{
              l[1]->next=h;
              l[1]=h;
              l[1]->next=NULL;
             }
             break;
      case 2:if(!h_[2]){
              h_[2]=l[2]=h;
              flag[2]=0;
             }
             else{
              l[2]->next=h;
              l[2]=h;
              l[2]->next=NULL;
             }
             break;
    }
    h=h->next;
  }
  if(l[0]){
    if(h_[1]){
      l[0]->next=h_[1];
      if(h_[2]){
        l[1]->next=h_[2];
      }
    }
    else if(h_[2]){
      l[0]->next=h_[2];
    }
      return h_[0];
  }
  else{
    if(h_[1]){
      l[1]->next=h_[2];
      return h_[1];
    }
    else{
      return h_[2];
    }
  }
}
int main(){
  int n;
  cin>>n;
  node* h, *t;
  h=t=new node(0,NULL);
  for(int i=1; i<n; i++){
    t->next=new node(i%3,NULL);
    t=t->next;
  }
  h=f(h);  
  t=h;
  while(t){
    cout<<t->d<<'\t';
    t=t->next;
  }
}
