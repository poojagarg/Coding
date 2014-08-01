#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int count_=0;
void f(string c, int k, string s){
  if(k==0){
    cout<<c<<endl;
    count_++;
    return;
  }
  else{
    int n=s.length();
    for(int i=n-1;i>=0; i--){
      swap(s[n-1],s[i]);
      string c_=c+s[n-1];
      string t=s;
      t.pop_back();
      f(c_,k-1,t);
    }
  }
}
int main(){
  string s; 
  int k;
  cin>>s>>k;
  f("",k,s);
  cout<<count_;
}
