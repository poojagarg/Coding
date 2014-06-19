#include<iostream>
#include<vector>
#include<cstdio>
#include<climits>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define For(i,n) for(int i=0; i<n;i++)
#define tr(i,c) for((typeof((c).begin)) i=(c).begin(); i!=(c).begin(); i++)
vi dfsMark;
vi topologicalMark;
vvi buildGraph(FILE* fp){
	vvi graph;
	int d;
	char c;
	while(!feof(fp)){
	vi list;
	do{
	fscanf(fp,"%d%c",&d,&c);
	list.push_back(d);
	}while(c!='\n');
	graph.push_back(list);
	}
	return graph;
}
void topologicalSort(vvi graph,vi list, int vertex){
	static int rank=0;
	For(i,list.size()){
		if(dfsMark[list[i]]==0){
			dfsMark[list[i]]=1;
			topologicalSort(graph,graph[list[i]],list[i]);
		}
	}
	topologicalMark[vertex]=rank;		
	rank++;
}
void startTopologicalSort(vvi graph){
	int n=graph.size(); //number of vertices
	dfsMark.resize(n,0);
	topologicalMark.resize(n,10);
	dfsMark[0]=1;
	topologicalSort(graph,graph[0],0);//Assuming graph is connected
}
void DFS(vvi graph, vi list){
	For(i,list.size()){
		if(dfsMark[list[i]]==0){
			cout<<list[i]<<'\t';
			dfsMark[list[i]]=1;
			DFS(graph,graph[list[i]]);
		}
	}
}
void startDFS(vvi graph){
	int n=graph.size(); //number of vertices
	dfsMark.resize(n,0);
	For(i, graph.size()){	
		if(dfsMark[i]==0){
			dfsMark[i]=1;
			cout<<i<<'\t';
			DFS(graph, graph[i]);
			}
	}		
}
int main(){
	vvi graph=buildGraph(fopen("adjacencyList.txt","r"));
	//startDFS(graph);
	startTopologicalSort(graph);
	For(i,topologicalMark.size()){
		cout<<topologicalMark[i]<<'\t';
	}
	return 0;
}

