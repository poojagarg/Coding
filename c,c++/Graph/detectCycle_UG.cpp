#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include <utility>      // std::pair, std::make_pair
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define For(i,n) for(int i=0; i<n; i++)
#define ForS(i,k,n) for(int i=k; i<n; i++)
#define ForSI(i,k,n,inc) for(int i=k; i<n; i=i+inc)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
void isCyclic_UG(vvi &g, int s, int parent){
  visited[s]=1;
  int n=g[s].size();
  For(i,n){
    if(visited[g[s][i]]==0){
      isCyclic_UG(g,g[s][i], s);
    }
    else if(g[s][i]!=parent){
      return true;
    }
  }
  return false;
}

int main(){
}
