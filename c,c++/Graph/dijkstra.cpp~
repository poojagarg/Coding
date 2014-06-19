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
			Q.push(ii(graph[start][i].first+distanceVertex[start],graph[start][i].second));
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
int main(){
	vvii graph=buildGraph(fopen("weighted_adjacencyList.txt","r"));
	dijkstra(graph);
	For(i, graph.size()){
		cout<<i<<":"<<distanceVertex[i]<<'\t';
	}
	return 0;
}
