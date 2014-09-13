#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
int main(){
  int n;
  cin>>n;
  char w[n][21];
  set<char> alphabets;
  for(int i=0; i<n; i++){
    cin>>w[i];
    int t=strlen(w[i]);
    for(int j=0; j<t; j++)
      alphabets.insert(w[i][j]);
  }
  int s_=alphabets.size();
  char a[s_];
  int c=0;
  for(set<char>::iterator it=alphabets.begin(); it!=alphabets.end(); it++){
    a[c]=*it;
  //  cout<<a[c]<<'\t';
    c++;
  }
  set<char> s[26];
  for(int i=0; i<n-1; i++){
    int t=min(strlen(w[i]),strlen(w[i+1]));
    int j;
    for(j=0; j<t; j++){
      if(w[i][j]!=w[i+1][j])
        break;
    }
    int ind;
      for(ind=0; ind<s_; ind++){
        if(w[i+1][j]==a[ind])
          break;
      }
    //  cout<<a[ind]<<w[i][j];
      s[ind].insert(w[i][j]);
  }
  int v[s_];
  /*for(int i=0; i<s_; i++){
    cout<<i<<":";
  for(set<char>::iterator it=s[i].begin(); it!=s[i].end(); it++){
    cout<<*it<<'\t';
  }
  cout<<endl;
  }*/
  memset(v, 0, sizeof(v));
  while(true){
    set<char> remove;
    int flag=0;
  for(int i=0; i<s_; i++){
    if(!v[i]&&s[i].size()==0){
      cout<<a[i];
      v[i]=1;
      flag=1;
      remove.insert(a[i]);
    }
  }
  if(flag)cout<<endl;
  for(int i=0; i<s_; i++){
    if(!v[i]){
      for(set<char>::iterator it=remove.begin(); it!=remove.end(); it++)
       s[i].erase(*it);
    }
  }
  if(flag==0)
    break;
}
}
