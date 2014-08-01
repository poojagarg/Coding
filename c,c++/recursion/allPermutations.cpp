#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef vector<string> vs;
#define print(v) for(typeof(v.begin()) i=v.begin(); i!=v.end(); i++){cout<<*i<<'\t'; }
vs p(string s){
  int l=s.length();
  if(l<2)
    return vs(1,s);
  char c=s[l-1];
  s.pop_back();
  vs v=p(s);
  int vecSize=v.size();
  for(int i=0; i<vecSize; i++){
    v[i]+=c;
    s=v[i];
    for(int j=l-1; j>0; j--){
      c=s[j];
      s[j]=s[j-1];
      s[j-1]=c;
      v.push_back(s);
    }
  }
  return v;
}

int main(){
  string s;
  cin>>s;
  vs v=p(s);
  print(v);
}
