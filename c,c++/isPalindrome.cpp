#include <iostream>
#include  <cstring>
using namespace std;
bool f(char* s, int i, int j){
  if(i==j)
    return true;
  else
    if(s[i]!=s[j])
      return false;
    else
      return f(s,i+1, j-1);
}
int main(){
  char a[200];
  cin>>a;
  if(f(a,0,strlen(a)-1)){
    cout<<"Yes";
  }
}
