#include <iostream>
#include <algorithm>
using namespace std;
void f(int a[][4], int m, int n){
  for(int i=0;i<m; i++){
    for(int j=0; j<n; j++){
      int ind=i*n+j;
      cout<<a[i][j]<<'\t';
    }
  }
}
int main(){
  int a[3][4];
  for(int i=0; i<3; i++){
    for(int j=0; j<4; j++){
      a[i][j]=i*4+j;
      cout<<a[i][j]<<'\t';
    }
  }
  f(a,3,4);
}


