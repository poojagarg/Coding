#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;
typedef struct node{
  int e; node* next;
}node;
typedef node** hashTable;
hashTable createHashTable(int size){
  hashTable h=(hashTable)malloc(sizeof(node*)*size);
  for(int i=0; i<size; i++){
    h[i]=NULL;
  }
  return h;
}
int hash(int e, int size){
  return e%size;
}
int findHashTable(int e, hashTable h, int size);
int findThreeElements(hashTable h, int size, int sum, int *a){
  for(int i=0; i<size; i++){
    for(int j=i+1;j <size; j++){
      if(findHashTable(sum-a[i]-a[j],h,size)){
        cout<<a[i]<<'\t'<<a[j]<<'\t';
        return 1;
      }
    }
  }
  return 0;
}
void viewHashTable(hashTable h, int size){
  for(int i=0; i<size; i++){
    node* n=h[i];
    cout<<"i: "<<i<<'\t';
    while(n){
      cout<<n->e<<'\t';
      n=n->next;
    }
  }
}
void insertHashTable(int e, hashTable h, int size){
  int key=hash(e, size);
  node* n=(node*)malloc(sizeof(node));
  n->e=e;
  n->next=h[key];
  h[key]=n;
}
int findHashTable(int e, hashTable h, int size){
  int key=hash(e, size);
  node* n=h[key];
  while(n){
    if(n->e==e)
      break;
    n=n->next;
  }
  if(!n) return 0;
  else return 1;
}
int main(){
  int n;
  cin>>n;
  int A[n];
  hashTable h=createHashTable(n*n);
  for(int i=0; i<n; i++){
    cin>>A[i];
    insertHashTable(A[i],h, n);
  }
  for(int i=0; i<n; i++){
    if(findHashTable(i,h,n)){
      cout<<"Present "<<i<<'\t';
    }
  }
  viewHashTable(h,n);
  findThreeElements(h, n, 10, A);
}

