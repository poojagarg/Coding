#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
void print(vector<int> v){
  int n=v.size();
  for(int i=0; i<n; i++)
    cout<<v[i]<<'\t';
}
int f(char b, char e, char s[][100], int n, int chosen[], vector<int> &indices){
  if(indices.size()==n-1){
    int j;
    for( j=0; j<n; j++)
      if(!chosen[j])
        break;
    if(s[j][strlen(s[j])-1]==e){
     print(indices);
    return 1;
    }
    else{
      return 0;
    }
  }
  for(int i=0; i<n; i++){
    if(!chosen[i]&&s[i][0]==b){
      indices.push_back(i);
      chosen[i]=1;
      if(!f(s[i][strlen(s[i])-1],e,s,n,chosen,indices)){
        indices.pop_back();
        chosen[i]=0;
          }
      else{
        return 1;
      }
    }
  }
  return 0;
}
int main(){
  int n;
  cin>>n;
  char s[n][100];
  for(int i=0; i<n; i++)
    cin>>s[i];
  int chosen[n];
  memset(chosen,0,sizeof(chosen));
  chosen[0]=1;
  vector<int> indices(1,0);
  f(s[0][strlen(s[0])-1],s[0][0],s,n, chosen, indices);
}
