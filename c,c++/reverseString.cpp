#include<iostream>
#include<stdio.h>
int main(){
  char str[200];
  scanf("%s",str);
  int i=0;
  while(str[i]!='\0')
     i++;
  for(int k=0, j=i-1; k<j; k++, j--){
    char c=str[k];
    str[k]=str[j];
    str[j]=c;
  }
  printf("%s",str);
}
