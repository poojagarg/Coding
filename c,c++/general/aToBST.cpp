#include<iostream>
using namespace std;
class node{
  public:
    int data;
    node *l,*r;
    node(int data){
      this->data=data;
      this->l=this->r=NULL;
    }
};
node* aToBST(int a[], int i, int j){
  if(j<i) return NULL;
  else{
    node* n=new node(a[(i+j)/2]);
    n->l=aToBST(a,i, (i+j)/2-1);
    n->r=aToBST(a, (i+j)/2+1,j);
    return n;
  }
}
void inorder(node* r){
  if(!r) return;
  inorder(r->l);
  cout<<r->data<<'\t';
  inorder(r->r);
}
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++){
    a[i]=i;
  }
node* nt=aToBST(a,0,n-1);
inorder(nt);
}
