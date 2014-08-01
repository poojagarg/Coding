#include <iostream>
#include  <cstdio>
#include<cstring>
using namespace std;
void f(char* s){
  int l=strlen(s);
  int i=0;
  int h=0, v=0;
  while(i<l){
    switch(s[i]){
      case 'e':
        h++; break;
      
      case 'n':
        v--; break;
      case 's':
        v++; break;
      case 'w':
        h--; break;
    }
    i++;
  }
  if(h>0){
    for(i=0; i<h; i++)
      cout<<'E';
  }
  if(v<0){
    for(i=0; i<-1*v; i++)
      cout<<'N';
  }

  if(v>0){
    for(i=0; i<v; i++)
      cout<<'S';
}
  if(h<0){
    for(i=0; i<-1*h; i++)
      cout<<'W';
  }
}
int main(){
  char d[200];
  cin>>d;
  f(d);
}
