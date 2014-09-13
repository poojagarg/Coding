#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int n;
  do{
  cin>>n;
  if(pow((int)cbrt(n),3)==n)
    cout<<"true";
  }  while(n!=0);
;
}
