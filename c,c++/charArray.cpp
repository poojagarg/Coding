#include <stdio.h>
int main(){
  char a[4];
  for(int i=0;i <4; i++)
    a[i]=(char)i+'a';
 a[0]=a[4];
  printf("%s",a+1);
  int n;
  scanf("%d",&n);
}
