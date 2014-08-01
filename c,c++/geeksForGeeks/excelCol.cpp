#include <iostream>
#include <cstring>
using namespace std;
void print(char *b,int n){
  for(int i=n-1;i>=0;i--)
    cout<<b[i]<<'\t';
}
void f(int a){
  a--;
char b[10];
int c=0;
while(a>0){
  int r=a%26;
  a=a/26;
  b[c++]=(char)('a'+r);
}
print(b,c);
}
int main(){
  int n;
  do{cin>>n;
  f(n);
}while(n!=0);
}

