#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int main(){
  int a[2][3];

  cout<<sizeof(a);

  memset(a,0,sizeof(a));
  for(int i=0;i<2; i++){
    for(int j=0; j<3; j++)
      cout<<a[i][j]<<'\t';
    
  cout<<'\n';
}
}
