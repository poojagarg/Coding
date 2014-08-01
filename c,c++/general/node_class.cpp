#include<iostream>
using namespace std;
template<class T>
class node{
  public:
  node(T data,node<T> *ptrNext=NULL){
    this->data=data;
    this->next=ptrNext;
}
    T data;
    node<T> *next;
};


int main(){
  int a=2,b=3;
  node<int> *n=new node<int>(a);
  node<int> *n2=new node<int>(b);
  n2->next=n;
  cout<<n2->data<<n2->next->data;
}
