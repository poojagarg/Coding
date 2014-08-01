#include <iostream>
#include <cstring>
using namespace std;
void f(char* s){
  int len=strlen(s);
  int i=1;
  int max=1;//a[0]
  int count=1;
  int st=0,bst=0;
  while(i<len){
    if(s[i]==s[i-1]+1){
      count++;
      
    }
    else{
      if(count>max){
        max=count;
        bst=st;
      }
      count=1;
      st=i;
    }
    i++;
  }
  if(count>max){
    max=count;
    bst=st;
  }
  for(i=0; i<max; i++)
    cout<<s[i+bst]<<'\t';
}
int main(){
  char s[200];
  cin>>s;
  f(s);

}
