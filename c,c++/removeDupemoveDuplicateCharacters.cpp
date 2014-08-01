#include<iostream>
using namespace std;
int main(){
  char str[200];
  cin>>str;
  int checker=0;
  int len=0;
  while(str[len]!='\0')
     len++;
     int tail=0;
  for(int i=0; str[i]!='\0';i++){
    int val=str[i]-'a';
    if((1<<val)&checker){
      str[i]=str[len-1];
      str[len-1]='\0';
      len--;
      i--;
    }
    else{
      tail++;
      checker|=(1<<val);
    }
  }
  cout<<str;
}
