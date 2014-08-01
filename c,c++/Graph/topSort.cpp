#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define For(i,n) for(int i=0; i<n; i++)
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
bool visited[100];
int order[100];
void topSort(vvi g, int s){
  static int counter=g.size();
  visited[s]=1;
  tr(g[s], it){
    if(!visited[*it]){
      topSort(g,*it);
    }
    else if(order[*it]==-1){
      printf("cycle exists");
      return;
    }
    }
    order[s]=counter--;
}
void print(int* counter, int n){
  cout<<endl;
  For(i, 10){
    cout<<counter[i]<<'\t';
  }
  cout<<endl;
}
int main(){
  int n; 
  memset(order,-1,100);
  scanf("%d",&n);
  vvi g(n);
  For(i,n){
      int t;
      scanf("%d",&t);
      scanf("%d",&t);
      while(t!=-1){
        g[i].pb(t);
        scanf("%d",&t);
      }
    }
    topSort(g,0);
    print(order,n);
  }
