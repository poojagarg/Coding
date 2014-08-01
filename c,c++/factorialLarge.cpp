#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
char* f(char* s, int d, int c){
  int l=strlen(s);
  int i=0;
  char r[l+2];
  int ri=0;
  while(i<l){
    int sum=d*(s[i]-'0')+c;
    c=sum/10;
    sum=sum%10;
    r[ri++]=(char)(sum+(int)'0');
    i++;
  }
  if(c){
    r[ri++]=(char)(c+(int)'0');
  }
  r[ri]='\0';
  for(int i=0; r[i]!='\0'; i++)
    cout<<r[i];
  cout<<endl;
  return r;
}
int main(){
  int n;
  char s[100];
  cin>>s;
  cin>>n;
  char* r=f(s,n,0);
  int l=strlen(r);
  for(int i=0; i<l; i++)
    cout<<r[i];
}
