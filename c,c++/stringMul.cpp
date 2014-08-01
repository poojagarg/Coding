#include <iostream>
#include <sstream>
#include <string>
using namespace std;
string add(string s1, string s2){
  int l1=s1.length();
  int l2=s2.length();
  if(!l1)
    return s2;
  if(!l2)
    return s1;
  int i1=l1-1,i2=l2-1;
  string r="";
  int c=0;
  while(i1>=0&&i2>=0){
    int s=s1[i1]+s2[i2]+c-2*'0';
    c=s/10;
    s=s%10;
    ostringstream oss;
    oss<<s;
    r+=oss.str();
    i1--; 
    i2--;
  }
  while(i1>=0){
    int s=s1[i1]+c-'0';
    c=s/10;
    s=s%10;
    ostringstream oss;
    oss<<s;
    r+=oss.str();
    i1--;
  }
  while(i2>=0){
    int s=s2[i2]+c-'0';
    c=s/10;
    s=s%10;
    ostringstream oss;
    oss<<s;
    r+=oss.str();
    i2--;
}
ostringstream oss;
  if(c){
    oss<<c;
    r+=oss.str();
  }
  reverse(r.begin(), r.end());
  return r;
}
string mul_d(string s, int d, int c){
  string r="";
  for(int i=0; i<c; i++){
    r+="0";
  }
  int l=s.length();
  int i=l-1;
  c=0;
  while(i>=0){
    int s_=(s[i]-'0')*d+c;
    c=s_/10;
    s_=s_%10;
    ostringstream oss;
    oss<<s_;
    r+=oss.str();
    i--;
  }
  if(c){
  ostringstream oss;
    oss<<c;
    r+=oss.str();
  }
  reverse(r.begin(), r.end());
  return r;
}
string mul(string s1, string s2){
  int l1=s1.length()-1, l2=s2.length()-1;
  int c=0;
  string r="";
  for(int i=l2; i>=0; i--){
    string r1=mul_d(s1,s2[i]-'0',c);
    cout<<r1<<".";
    r=add(r,r1);
    c++;
  }
  return r;
}
int main(){
  string s1,s2;
  while(true){cin>>s1>>s2;
  cout<<mul(s1,s2);
  int c; cin>>c;
  if(c==0) break;
  }
}
