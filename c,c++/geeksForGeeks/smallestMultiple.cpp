#include <iostream>
#include <string>
using namespace std;
string makeString(long largestNum, int n, long cur){
  char st[100];
  int start=0;
  while(largestNum){
    st[start++]='1';
    largestNum=largestNum/10;
  }
    st[start]='\0';
  string s;
  for(int i=0; i<n; i++){
    s.append(st);
  }
  while(cur){
    s.append("1");
    cur=cur/10;
  }
  return s;
}
int isDivisible(int a, long cur, long l, int n){
  long num;
  if(n==0)
    num=0;
  else
    num=l;
  for(int i=0; i<n; i++){
    num=num%a;
    num+=l;
  }
  return ((num+cur)%a==0);
}
string smallestMultiple(int a){
  int nod=0;
  int n=0;
  long largestNum=0;
  int p=1;
  while(true){
  long l=largestNum+p*1;
  p=p*10;
  if(l<0)
    break;
  largestNum=l;
  }
  cout<<largestNum<<";;";
  long cur=0;
  p=1;
  while(cur<a){
    cur+=p*1;
    p=p*10;
  }
  while(!isDivisible(a,cur, largestNum,n)){
    if(cur<largestNum){
      cur+=p*1;
      p=p*10;
    } 
    else{
      n++;
      cur=1;
      p=10;
    }
  }
  return makeString(largestNum, n,cur);
}
int main(){
  int a;
  cin>>a;
  while(a!=-1){
    cout<<smallestMultiple(a)<<'\t';
    cin>>a;
  }
}
