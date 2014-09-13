#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int n;
  char w[n ][21];
  int a=0;
  int v[26]={0};
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>w[i];
    int t=strlen(w[i]);
    for(int j=0; j<t; j++){
      a|=(1<<(w[i][j]-'a'));
      v[w[i][j]-'a']=1;
    }

  }
  int s[26]={0};
  for(int i=0; i<n-1; i++){
    int j=0;
    while(w[i][j]==w[i+1][j])
      j++;
    s[w[i+1][j]-'a']|=(1<<(w[i][j]-'a'));

  }
  int remove;
  while(true){
    int flag=0;
  for(int i=0; i<26; i++){
    remove=-1;
    if(v[i]&&!s[i]){
      flag=1;
      v[i]=0;
      cout<<(char)(i+'a');
      remove^=(1<<i);
    }
  }
  cout<<endl;
  for(int i=0; i<26; i++){
    if(v[i]){
      s[i]&=~remove;
    }
  }
  if(!flag)
    break;
  }
}
