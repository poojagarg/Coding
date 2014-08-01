#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int order[26];
int visited[26];
int counter=0;
void topSort(vvi g, int s){
  visited[s]=1;
  int n=g[s].size();
  for(int i=0; i<n; i++){
    if(!visited[g[s][i]])
      topSort(g,g[s][i]);
  }
  order[s]=++counter;
}
void print(int *order, int n){
  for(int i=0; i<n; i++){
    cout<<"_"<<i<<":"<<order[i]<<'\t';
  }
}
void printG(vvi &g){
  int n=g.size();
  for(int i=0; i<n; i++){
    int j=g[i].size();
    cout<<"<"<<i<<">";
    for(int k=0; k<j; k++){
      cout<<g[i][k]<<'\t';
    }
  }
}
void f(char s[][100], int n){
  vvi g(26);
  for(int i=0; i<n-1; i++){
    int j=0;
    while(s[i][j]==s[i+1][j])
      j++;
   g[s[i][j]-'a'].push_back(s[i+1][j]-'a');
  }
  printG(g);
  topSort(g,1);
}
int main(){
  int n; 
  cin>>n;
  char s[n][100];
  for(int i=0; i<n; i++)
    cin>>s[i];
  memset(order,0, sizeof(order));
  memset(visited,0, sizeof(visited));
  f(s,n);
  print(order,26);
}
