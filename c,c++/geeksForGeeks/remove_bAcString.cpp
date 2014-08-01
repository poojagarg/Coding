#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char* f(char* s){
  int len=strlen(s);
  int j;
  for(int i=0; i<len; i++){
    switch(s[i]){
      case 'a':if(i<len-1&&s[i+1]=='c'){
               j=i;
                 while(j<len-2){
                  s[j]=s[j+2];
                  j++;
                 }
                 len=len-2;
               i--;}
                break;
      case 'b':j=i;
               while(j<len-1){
                s[j]=s[j+1];
                j++;
               }
               i--;
               len=len-1;
               break;
      default:
               break;
    
    }
  }
  cout<<len;
  s[len]='\0';
  return s;
}
int main(){
  char s[100];
  cin>>s;
  char* a=f(s);
  cout<<a;
}
