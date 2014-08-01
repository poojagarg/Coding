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
vi visited;
void dfs(vvi g, int s){
  visited[s]=1;
  tr(g[s],i){
    if(visited[*i]!=1){
      dfs(g,*i);
    }
    else{
      //cycle exists
    }
  }
}
void dfsItr(vvi g, int s){
  stack<int> dfsStack;
  dfsStack.push(s);
  while(!dfsStack.empty() ){
    s=dfsStack.top();
    dfsStack.pop();
    if(visited[s]!=1){
      visited[s]=1;
    }
    else{
      //cycle exists
    }
    tr(g[s],i){
      if(visited[*i]){
        dfsStack.push(*i);
      }
    }
  }
}
void topSort_deg(vvi g, int s){
  int n=g.size();
  int deg[n]={0};
  tr(g,i){
    tr(g[*i],j){
      deg[*j]++;
    }
  }
  queue<int> qdeg;
  For(i,n){
    if(deg[i]==0){
      qdeg.push(i);
    }
  }
  int counter=0;
  while(!qdeg.empty()){
    int i=qdeg.front();
    order[i]=counter++;
    qdeg.pop();
    tr(g[i],j){
      deg[*j]--;
      if(deg[*j]==0)
        qdeg.push(*j);
    }
  }
  if(counter<n){
    //cycle exists
  }
}
//assumption that g is connected graph and has even degree for all vertices
void eulerCycle(vvi g, int s){
  int edgeCount=0;
  int start=s;
  vii edges;
  tr(g, i){
      edgeCount+=g[*i].size();
    }
  int noe=0;
  int flag=0;
  while(noe<edgeCount){
    flag=0;
    tr(g[s], i){
      if(g[s][*i]!=-1){
        edges.pb(ii(s,*i));
        noe++;
        s=g[s][*i];
        g[s][*i]=-1;
        flag=1;
        s=*i;
        break;
    }
    }
    if(flag==0){
      //either no eulerian circuit or it is a starting index
      if(s==start){
        //eulerian circuit!
      }
    }
  }
}
void prims(vvii g, int s){
  set<int> spanningVerticesSet;
  int n=0;
  int gSize=g.size();
  priority_queue<ii> disPQ;
  disPQ.push(ii(0,s));
  int start=s;
  while(gSize>n){
    ii minDisVertex=disPQ.top();
    disPQ.pop();
    if(spanningVerticesSet.find(minDisVertex.second)==spanningVerticesSet.end()){
      spanningVerticesSet.insert(minDisVertex.second);
      n++;
    }
    tr(g[minDisVertex.second], i){
      if(spanningVerticesSet.find(*i.first)==spanningVerticesSet.end()){
        disPQ.push(ii(*i.second,*i.first));
      }
    }
  }
}
vvi graphRev(vvi& g){
  vvi gRev(g.size());
  For(i, g.size()){
    For(j, g[i].size()){
      gRev[g[i][j]].pb(i);
    }
  }
  return gRev;
}

//order[v]=-1 for all vertices v, visited[v]=0
void topSort(vvi g, int s){
  static int counter=g.size[];
  visited[s]=1;
  tr(g[s], i){
    if(visited[*i]!=1){
      topSort(g, s);
    }
    else if(order[s]==-1){
      //Directed Cyclic graph, therefore not  possible
    }
  }
  order[s]=counter--;
}
void bfs(vvi g, int s){
    
  queue<int> q;
  q.push(s);
  visited[s]=1;
  while(!q.empty()){
    tr(q.front(),i){
      if(visited[*i]!=1){
        visited[*i]=1;
        q.push(*i);
      }
    }
      q.pop();
  }
}
int main(){
  vvi g;
  FILE* fp=fopen("graph_Unweighted_undirected.txt","r");
  read(g,fp);
  int n=g.size();
  visited.resize(n,0);
  For(i,n){
    if(visited[i]!=1){
      dfs(g,s);
    }
  }
}
