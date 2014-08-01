#include <stdio.h>
int* f()

{

  int a[3] = {1,2,3};

  return a;

}
int main(){
int* a=f();
printf("%d %d %d",a[0], a[1],a[2]);
  }
