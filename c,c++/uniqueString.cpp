#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
  char str[200];
  cin>>str;
  int len=strlen(str);
  int checker=0;
  for(int i=0; i<len; i++){
    int val=str[i]-'a';
    if((1<<val)&checker){
      cout<<str[i]<<"not unique"<<val<<","<<checker;
      break;
    }
    else{
      checker|=(1<<val);
    }
  }

}
