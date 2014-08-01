#include <iostream>
#include <string>
using namespace std;
int f(string s, int n){
  s=s+s;
  for(int i=0; i<=n; i++){
    int start,last;
    for(start=i, last=i+n-1; start<last; start++, last--){
      if(s[start]!=s[last])
        break;
    }
    if(start>=last)
      return 1;
  }
  return 0;
}
int main(){
  string s;
  int n;
  do{
  cin>>s;
  cout<<f(s, s.length());
}while(s.length()>3);
}
