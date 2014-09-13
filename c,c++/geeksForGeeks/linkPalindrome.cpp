#include <iostream>
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
int count(node* l){
  int count=0;
  while(l){
    count++;
    l=l->next;
  }
  return count;
  
}
bool f(node* l){
  if(!l||!l->next)
    return true;
  else{
  if(!l->next->next)
    return l->d==l->next->data;
  }
  int n=count(l);
  /*int a[n];
  for(int i=0; i<n; i++){
    a[i]=l->d;
    l=l->next;
  }
  return isPalindrome(a,n);
*/
  node* h=l;
  int t=n/2-1;
  while(t){
    h=h->next;
    t--;
  }
  node* h2;
  if(n/2){
    h2=h->next->next;
  }
  else{
    h2=h->next;
  }
  h2=reverse(h2);
  while(h2){
    if(h2->d!=h->d)
      return false;
    h2=h2->next;
    h=h->next;
  }
}
