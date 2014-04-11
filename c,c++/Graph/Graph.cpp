#include<iostream>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include"GraphDef.h"
#include<vector> 
#define max_vertices 100
int indegree[max_vertices]={0};
int visited[max_vertices]={0};   
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
void debug(){
	int i;
	printf("debug");	
	scanf("%d",&i);
}
vvii G;
vvii buildGraph(){
	int n;
	printf("no of vertices:");
	scanf("%d",&n);//no of vertices

	FILE* fp=fopen("weightedGraph.txt","r");

	vvii G(100);
	G.resize(n);
	
	/*printf("<G size:%d>",G.size());
	for(int l=0; l<n; l++)	
		printf("<%d>",G[l].size());*/
	int i,a,w;	
	do{
				
		fscanf(fp,"%d",&i);
		//printf("<%d>",i);
		if(i>=n) {printf("breaking because %d",i);break;}
		char c='a';	
		while(c!='\n'){	
			fscanf(fp,"%d",&a);
			fscanf(fp,"%d",&w);
			ii p;
			p.first=a; p.second=w;
			G[i].push_back(p);
			fscanf(fp,"%c",&c);
			//printf("%d %d %c",p.first,p.second,c);
			//debug();	
			}
				
		}while(i!=n-1);
		
return G;
}
	
void showGraph(vvii G){
	int n=G.size();
	for(int i=0; i<n; i++){
		int t=G[i].size();
		printf("<%d>:",i);	
		for(int j=0; j<t; j++){
			printf("Vertex:%d, Weight:%d",G[i][j].first,G[i][j].second);
		}
		printf("\n");
		}	
}
GraphAdjMat* adjMatrix(){
	int i, u, v;
	GraphAdjMat* g=(GraphAdjMat*)malloc(sizeof(GraphAdjMat));
	if(!g) return NULL;
	scanf("%d%d", &g->V, &g->E);
	g->Adj=(int**)malloc(g->V*sizeof(int*)); //g->V rows containing int*
	int* tmp=(int*)malloc(g->V*g->V*sizeof(int));
	for(i=0; i<g->V; i++){
		g->Adj[i]=tmp+(i*g->V);	
	}
	for(i=0; i<g->V; i++){
		for(u=0; u<g->V; u++){
			g->Adj[i][u]=0;
		}	
	}
	return g;
}
void displayAdjMatrix(GraphAdjMat* g){
	int i,j;
	for(i=0; i<g->V; i++){
		for(j=0; j<g->V; j++)
			printf("<%d>",g->Adj[i][j]);
		printf("\n");
		}//end of outer for
}
void debug(){
	int i;
	printf("debug");	
	scanf("%d",&i);
}
GraphAdjList* adjList(){
	GraphAdjList* g=(GraphAdjList*)malloc(sizeof(GraphAdjList));
	scanf("%d%d",&g->V,&g->E);
	g->Adj=(GraphNode**)malloc(g->V*sizeof(GraphNode*));
	int i;	
	for(i=0; i<g->V; i++){
		g->Adj[i]=NULL;
	}
	FILE* fp=fopen("GraphAdjList.txt","r");
	int t,b;
	while(!feof(fp)){
		fscanf(fp,"%d",&t);
		//printf("<%d>:",t);
		if(t<0) break;
		if(t>=g->V) break;
		while(1){
			fscanf(fp,"%d",&b);
				
			if(b==-1) break;
			GraphNode* n=(GraphNode*)malloc(sizeof(GraphNode));
			n->v=b;
			n->next=g->Adj[t];
			g->Adj[t]=n;
			//printf("<%d>",n->v);
			}//end of inner while
		//debug();		
		//printf("\n");
		}//end of while
return g;
}// end of function
void displayAdjList(GraphAdjList* gt){
	if(!gt) return;
	int i,j;
	printf("\n");
	for(i=0; i<gt->V; i++){
		GraphNode* g=gt->Adj[i];
		printf("<%d>:",i);
		while(g!=NULL){
			printf("<%d>",g->v);
			g=g->next;			
			}
	printf("\n");}	
}
void delGraphAdjList(GraphAdjList* gt){
	if(!gt) return;
	int i;
	for(i=0; i<gt->V;  i++){
		GraphNode* g=gt->Adj[i];
		while(g){
			GraphNode* t=g;
			g=g->next; 
			free(t);
		}		
	}//end of for
	free(gt->Adj);
	free(gt);
}
void dfs(int i,GraphAdjList* g){
	if(i<0||i>g->V) return;
	if(visited[i]) return;
	visited[i]=1;
	printf("<%d>",i);
	GraphNode* n=g->Adj[i];
	while(n){
		dfs(n->v,g);
		n=n->next;
	}
}
void dfs_init(GraphAdjList* g){
	int i;
	for(i=0;i<g->V; i++){
		visited[i]=0;
	}
	for(i=0; i<g->V; i++){
		if(visited[i]==0)
			dfs(i,g);
	}
}
void bfs(int i,GraphAdjList* g){
	queue<int> bfsQueue;
	bfsQueue.push(i);
	int t;
	while(!bfsQueue.empty()){
		do{
			if(bfsQueue.empty()) return;
			t=bfsQueue.front();
			bfsQueue.pop();
		}while(visited[t]==1);
		printf("<%d>",t);
		visited[t]=1;
		GraphNode* n=g->Adj[t];
		while(n){
			if(!visited[n->v]){
				bfsQueue.push(n->v);}
			n=n->next;
		}
}
}
void showIndegree(int n){
	for(int i=0; i<n; i++)
		printf("<%d: %d>",i,indegree[i]);
	debug();
	
}
void populateIndegree(GraphAdjList* g){
	GraphNode* n;
	int i;
	for(i=0; i <g->V; i++){
		n=g->Adj[i];
		while(n){
			indegree[n->v]++;
			n=n->next;
		}//end of while
}	
showIndegree(g->V);
}

void topSort(GraphAdjList* g){
	populateIndegree(g);
	int flag=1;
	queue<int> topSortQ; 
	while(flag){
		flag=0;
		for(int i=0; i<g->V; i++){
			if(indegree[i]==0&&visited[i]==0){
				visited[i]=1;
				flag=1;
				topSortQ.push(i);
				GraphNode* n=g->Adj[i];
				while(n){
					indegree[n->v]--;
					n=n->next;
				}//end of while
			}//end of if
		}// end of for
		}	
while (!topSortQ.empty())
  	{
     		printf("<%d>",topSortQ.front());
		topSortQ.pop();
  	}
}//end of function
void bfs_init(GraphAdjList* g){
	int i;
	for(i=0;i<g->V; i++){
		visited[i]=0;
	}
	for(i=0; i<g->V; i++){
		if(visited[i]==0)
			bfs(i,g);
	}
}
int main(){
	/*GraphAdjMat* g=adjMatrix();
	displayAdjMatrix(g);*/
	GraphAdjList* g=adjList();
	//displayAdjList(g);
	//dfs_init(g);
	//bfs_init(g);
	topSort(g);	
	delGraphAdjList(g);
}
