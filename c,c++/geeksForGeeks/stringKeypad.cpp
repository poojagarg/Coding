#include <iostream>
#include <string>
using namespace std;
void f(int dig,string s){
  if(dig==0){
  cout<<s<<endl;
    return;
  }
  int r=dig%10;
  dig=dig/10;
  switch(r){
    case 0:
    case 1:
      s.push_back((char)('0'+r));
      f(dig,s);
      break;
    default:
      for(int i=0; i<3; i++){
        s.push_back('a'+3*(r-2)+i);
        f(dig,s);
        s.pop_back();
      }
    }
}
int main(){
  int n;
  cin>>n;
  while(n!=0){
    f(n,"");
    cin>>n;
  }
  }
