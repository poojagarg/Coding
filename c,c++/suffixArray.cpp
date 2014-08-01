#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<char, int> ci;
void print(int *a, int n){
  for(int i=0; i<n; i++){
    cout<<a[i]<<'\t';
  }
}
typedef pair<int, int> ii;
typedef pair<ii, int > iii;
void f_(char* a, int n, int* v){
  int log;
  for(log=1; n>(1<<log); log++);
  int p[log+1][n];
  for(int i=0; i<n; i++)
    p[0][i]=v[i];
  priority_queue<iii, vector<iii>, greater<iii> > pq;
  int cnt=1;
  for(int k=1; k<=log;k++){
    for(int i=0; i<n; i++){
      ii p_;
      if((i+cnt)<n){
        p_.first=p[k-1][i];
        p_.second=p[k-1][i+cnt];
      }
      else{
        p_.first=p[k-1][i];
        p_.second=-1;
      }
      pq.push(iii(p_,i));
    }
    cnt=cnt<<1;
      ii prev=pq.top().first;
      int rank=0;
    while(!pq.empty()){
      iii p_=pq.top();
      pq.pop();
      if(prev.first==p_.first.first&&prev.second==p_.first.second){
        p[k][p_.second]=rank;
      }
      else{
        p[k][p_.second]=++rank;
      }
    }
  }
  print(p[log],n);
}
void f(char* a, int n,int *p){
  vector<ci> l(n);
  for(int i=0; i<n; i++){
    l[i].first=a[i];
    l[i].second=i;
  }
  priority_queue<ci,vector<ci>, greater<ci> > pq(l.begin(),l.end());
  int rank=0;
  char prev_char='-';
  while(!pq.empty()){
    ci t=pq.top();
    pq.pop();
    if(t.first==prev_char){
      p[t.second]=rank;
    }
    else{
      rank++;
      p[t.second]=rank;
      prev_char=t.first;
    }
  }
  print(p,n);
}
int main(){
  char a[100];
  cin>>a;
  int n=strlen(a);
  int p[n];
  f(a,n,p);
  f_(a, n,p);
}
