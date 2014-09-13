#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> ii;
void f(char *s){
  int n=strlen(s);
  int i;
  for(i=0; i<n; i++)
    if(s[i]=='b')
      break;
  if(i==n)
    return;
  vector <pair<int, int> > vii;
  int j,k, max=0;
  int f=i;
  for(j=i+1; j<n; j++){
    for(k=j; k<n; k++){
      if(s[k]=='b')
        break;
    }
    if(k-j>max){
      max=k-j;
      vii.clear();
      vii.push_back(ii(f,k));
    }
    else if(k-j==max){
      vii.push_back(ii(f,k));
    }
    j=k;
}
    char sMin[strlen(s)+1];
    strcpy(sMin,s);
    if(max==0)
      return;
  for(int i=0;i<vii.size(); i++){
    char sn[strlen(s)+1];
    strcpy(sn,s);
    int st=vii[i].first;
    int end=vii[i].second;
    reverse(sn+st, sn+end);
    if(strcmp(sn,sMin)<0){
      strcpy(sMin,sn);
    }
  }
  cout<<sMin<<endl;
}
int main(){
  char s[100];
  cin>>s;
  while(strlen(s)>1){
    f(s);
    cin>>s;
  }
}
