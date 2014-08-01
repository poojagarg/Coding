#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
  char s1[200], s2[200];
  cin>>s1>>s2;
  int len=strlen(s1);
  if(strlen(s2)!=len)
    return 0;
  int num_u=0, num_c=0;
  int count[256]={0};
  for(int i=0; i<len; i++){
    if(count[s1[i]]==0)
      num_u++;
    count[s1[i]]++;
  }
  for(int i=0; i<len;i++){
    if(count[s2[i]]==0){
      return 0;
    }
    count[s2[i]]--;
    if(count[s2[i]]==0){
      num_c++;
      if(num_c==num_u){
        if(i==len-1)
          return 1;
      }
    }
  }
}
