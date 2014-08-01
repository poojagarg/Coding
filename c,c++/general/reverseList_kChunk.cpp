#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
typedef struct node{
  int data; node* next;
}node;
node* reverseRec(node* h){
  if(!h||!h->next){
    return h;
  }
  node* head=reverseRec(h->next);
  h->next->next=h;
  h->next=NULL;
  return head;
  }
node* reverseK(node* head, int k){
  node* t=head; int c=1;
  while(t){
    t=t->next;
    c++;
    if(c==k)
      break;
  }
  if(t==NULL){
    return head; 
  }
  else{
    node* h=t->next;
    t->next=NULL;
    node* newHead=reverseRec(head);
    head->next=reverseK(h,k);
    return newHead;
  }
}
void print(node* n){
  while(n!=NULL){
    cout<<n->data<<'\t';
    n=n->next;
  }
  cout<<endl;
}
int main(){
  int n,k;
  scanf("%d %d",&n, &k);
  node *tmp, *h=NULL;
  int t;
  scanf("%d",&t);
  h=(node*)malloc(sizeof(node));
  h->data=t;
  h->next=NULL;
  tmp=h;
  for(int i=1; i<n; i++){
    tmp->next=(node*)malloc(sizeof(node));
    scanf("%d",&t);
    tmp=tmp->next; 
    tmp->data=t;
    tmp->next=NULL;
  }
  print(h);
  h=reverseK(h,k);
  print(h);
}
