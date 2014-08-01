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
int main(){
  int n;
  cin>>n;
  node* h, *t;
  h=t=new node(0,NULL);
  for(int i=1; i<n; i++){
    t->next=new node(i,NULL);
    t=t->next;
  }
  
  t=h;
  while(t){
    cout<<t->d<<'\t';
    t=t->next;
  }
}
