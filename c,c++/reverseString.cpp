#include<iostream>
#include<stdio.h>
#include <cstring>
using namespace std;

void reverse(char *s,int n){
  for(int i=0, j=n-1; i<j; i++, j--){
    char c=s[i];
    s[i]=s[j];
    s[j]=c;
  }
}
void rotateByK(int k,char* s){
  int n=strlen(s);
  reverse(s,n);
  reverse(s,k);
  reverse(s+k,n-k);
}
int main(){
  char str[200];
  scanf("%s",str);
  
  int k;
  cin>>k;
  rotateByK(k,str);
  printf("%s",str);
}
