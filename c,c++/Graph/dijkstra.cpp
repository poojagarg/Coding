#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#include<climits>
using namespace std;
typedef pair<int, int> ii;//weight and vertex
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
#define For(i,n) for(int i=0; i<n;i++)
#define tr(i,c) for((typeof((c).begin)) i=(c).begin(); i!=(c).begin(); i++)
vvii buildGraph(FILE* fp){
	vvii graph;
	int d,w;
	char c;
	while(!feof(fp)){
	vii list;
	do{
	fscanf(fp,"%d%d%c",&d,&w,&c);
	list.push_back( ii(d,w) );
	}while(c!='\n');
	graph.push_back(list);
	}
	return graph;
}
vi distanceVertex;
void dijkstra(vvii graph){
	int start=0;
	ii p;
	int n=graph.size();
	distanceVertex.resize(n,INT_MAX);	
	distanceVertex[start]=0; //distance of start vertex from start vertex
	priority_queue<ii,vector<ii>, greater<ii> > Q;
	while(n!=0){
		For(i,graph[start].size()){
			if(distance[graph[start][i].first]>(graph[start][i].first+distanceVertex[start])){
				Q.push(ii(graph[start][i].first+distanceVertex[start],graph[start][i].second));
				}
		}
		do{
			p=Q.top();
			Q.pop();
		}while(distanceVertex[p.second]<=p.first);
		distanceVertex[p.second]=p.first;
		start=p.second;
		n--;
	}
}
void dijkstraNew(vvii graph, int s){
	priority_queue<ii, vector<ii> , greater<ii> > q; //first element is the distance, 2nd is the vertex
	vector<int> distance(graph.size(), numeric_limits<int>::max());
	distance[s-1]=0;
	q.push(s);
	distance[s-1]=1; //for coding purposes
	int count=0;
	while(count<g.size()){
		ii n=q.top();
		q.pop();
		if(distance[n.second]>n.first){
			distance[n.second]=n.first;
			count++;
			for(int i=0; i<g[n].size(); i++){
				if(distance[g[n][i].first]>(distance[n.second]+g[n][i].second)){
					q.push(ii((distance[n.second]+g[n][i].second),g[n][i].first));
				}
			}
		}
	}
}
typedef pair<i, ii> iii;
typedef vector<iii> viii;
void prims(vvii graph){ //vertex, weight
	priority_queue< iii, vector<iii>, greater<iii> > q;
	viii MSTedges;
	int start=0;
	for(int i=0; i<graph[start].size(); i++){
		q.push( iii(graph[start][i].second, ii(graph[start][i].first, start) ) );
	}
	set<int> s;
	pair( set<int>::iterator, bool) ret;
	set<int>::iterator findSI;
	s.insert(start);
	while(s.size()!=graph.size()){
		iii n=q.top();
		q.pop();
		if(!s.find(n.second.first)){
			s.insert(n.second.first);
			start=n.second.first;
			MSTedges.push(n);
			for(int i=0; i<graph[start].size(); i++){
			q.push( iii(graph[start][i].second, ii(graph[start][i].first, start) ) );
			}			
		}
	}
}
int findSet(int v, int *parent, int n){
	if(v>=n) return -1;
	if(parent[v]>=0){
		return (parent[v]=find(parent[v], parent, n));
	}
	return v;
}
int unionSet(int v1, int v2, int *parent, int n){
	v1=findSet(v1,parent,n);
	v2=findSet(v2,parent,n);
	if(v1==v2) return 0;//already together
	if(parent[v1]<parent[v2]){
		parent[v2]=parent[v1];
	}
	else{
		if(parent[v1]>parent[v2]){
			parent[v1]=parent[v2];
		}
		else{
			parent[v1]=parent[v2];
			parent[v2]--; //height union
			//parent[v2]=parent[v1]+parent[v2]; //union by size
		}
	}
	return 1;//successful union
	
}
void Kruskals(vvii graph){
	int n=graph.size();
	priority_queue<iii, vector<iii>, greater<iii> > q;
	for(int i=0; i<n; i++){
		int m=graph[i].size();
		for(int j=0; j<m; j++){
			q.push(iii(graph[i][j].second, ii(graph[i][j].first, i) ));
		}
	}
	int parent[n];
	for(int i=0; i<n; i++){
		parent[i]=-1; //whosoever is parent, has a negative number. magnitude of number represents the size
	}
	viii MSTedges;
	while(MSTedges.size()!=n-1){
		iii n=q.top();
		q.pop();
		if(findSet(n.second.first, parent, n)!=findSet(n.second.second, parent, n)){
			unionSet(n.second.first, n.second.second, parent, n);
			MSTedges.push(n);
		}
	}
}
int main(){
	vvii graph=buildGraph(fopen("weighted_adjacencyList.txt","r"));
	dijkstra(graph);
	For(i, graph.size()){
		cout<<i<<":"<<distanceVertex[i]<<'\t';
	}
	return 0;
}
