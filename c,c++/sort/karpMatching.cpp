#include  <iostream>
using namespace std;
int f(string p, string t){
  p=" "+p;
  t=" "+t;
  int m=p.length();
  int n=t.length();
  int pi[m];
  int k=-1;
  pi[0]=-1;
  int i=1;
  while(i<m){
    while(k>=0&&p[k+1]!=p[i])
      k=pi[k];
    k++;
    pi[i]=k;
    i++;
  }
  k=0;
  i=1;
  int count=0;
  while(i<n){
    while(k>=0&&p[k+1]!=t[i])
     k=pi[k];
    k++;
    if(k==m-1){
      count++;
      k=pi[k];
    }
    i++;
  } 
  return count;
}
int main(){
  string p, t;
  cin>>p>>t;
  cout<<f(p,t);
}
