#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int f(char *s1, char*s2){
  int len1=strlen(s1);
  int len2=strlen(s2);
  int m[len1+1][len2+1];
  for(int i=0; i<=len1; i++){
    m[i][0]=0;
    m[0][i]=0;
  }
  for(int i=0; i<len1; i++){
    for(int j=0; j<len2; j++){
      if(s1[i]==s2[j]){
        m[i+1][j+1]=m[i][j]+1;  
      }
      else{
        m[i+1][j+1]=max(m[i][j+1],m[i+1][j]);
      }
    }
  }
return m[len1][len2];

}
int main(){
  char s1[100], s2[100];
  int n;
  cin>>n;
  while(n!=0){
    cin>>s1>>s2;
    cout<<f(s1,s2);
    cin>>n;
  }
}


