#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
void f(char* s, int d){
  int len=strlen(s);
  int count[26]={0},l[26];
  memset(l,-1,sizeof(l));
  for(int i=0; i<len; i++){
    count[s[i]-'a']++;
  }
  int cur=0;
  char r[len];
  while(cur<len){
 int index=max_element(count, count+26)-count;
 if(count[index]==0)
 {
  r[cur]='\0';
  cout<<r;
  return;
 }
 if(l[index]==-1||cur-l[index]>=d){
   
  count[index]--;
  l[index]=cur;
  r[cur]=(char)(index+'a');
  cur++;
 }
 else{
  int i;
  int countMax=0, maxIndex=-1;
  for(i=0; i<26; i++){
    if(i==index)
      continue;
    if(count[i]>countMax&&(l[i]==-1||cur-l[i]>=d)){
      countMax=count[i];
      maxIndex=i;
    }
  }
  if(maxIndex==-1){
    r[cur]='\0';
    return;
  }
if(count[i]==0)
  return;
  l[maxIndex]=cur;
  count[maxIndex]--;
  r[cur]=(char)(maxIndex+'a');
  cur++;
 }
  }
  r[cur]='\0';
  cout<<r;
 }
int main(){
  int n;
  char *s;
  cin>>n;
  cin>>s;
  while(n!=0){
    f(s,n);
    cin>>n;
    cin>>s;
  }
}
