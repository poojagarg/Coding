#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
  char s1[200],s2[200];
  cin>>s1>>s2;
  int len=strlen(s1);
  if(len!=strlen(s2)){
    cout<<"No";
    return 0;
  }

  sort(s1,s1+len);
  sort(s2, s2+len);
  for(int i=0; i<len; i++){
    if(s1[i]!=s2[i])
      cout<<"No";
  }
}
