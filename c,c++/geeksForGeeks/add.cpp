#include <iostream>
using namespace std;
int add(int x, int y){
  if(!y)
    return x;
  int sum=x^y;
  int c=(x&y)<<1;
  return add(sum, c);
}
int main(){
  
int a, b;
  do{
  cin>>a>>b;
  cout<<add(a,b)<<'\t';
}while(a!=-1);
}
