#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int count_=0;
typedef vector<string> vs;
vs f(string c, int k){
  vs v;
  if(k==1){
    int n=c.length();
    for(int i=0; i<n; i++){
      string s("");
      s+=c[i];
      v.push_back(s);
    }
    return v;
  }
  v=f(c,k-1);
  int n=c.length();
  int vl=v.size();
  for(int i=0; i<vl; i++){
    string s=v[i];
    v[i]=(s+c[0]);
    for(int j=1; j<n; j++){
      v.push_back(s+c[j]);
    }
  }
  return v;
}
void print(vs v){
  int n=v.size();
  for(int i=0;i<n; i++){
    cout<<v[i]<<endl;
  }
  cout<<n;
}
int main(){
  string s; 
  int k;
  cin>>s>>k;
  vs v=f(s,k);
  print(v);
}
