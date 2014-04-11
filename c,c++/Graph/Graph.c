#include"GraphDef.h"
#include<stdio.h>
#define max_vertices 100
int visited[max_vertices];
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
displayAdjMatrix(GraphAdjMat* g){
	int i,j;
	for(i=0; i<g->V; i++){
		for(j=0; j<g->V; j++)
			printf("<%d>",g->Adj[i][j]);
		printf("\n");
		}//end of outer for
}
void debug(){
	int i;
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
		printf("<%d>:",t);
		if(t<0) break;
		if(t>=g->V) break;
		while(1){
			fscanf(fp,"%d",&b);
				
			if(b==-1) break;
			GraphNode* n=(GraphNode*)malloc(sizeof(GraphNode));
			n->v=b;
			n->next=g->Adj[t];
			g->Adj[t]=n;
			printf("<%d>",n->v);
			}//end of inner while
		//debug();		
		printf("\n");
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
void bfs(int i,GraphAdjList* g){
	GraphNode* start=g->Adj[i];
	GraphNode* end=start;
	while(start!=NULL){
		GraphNode* temp=start;
		start=start->next;
}
}
int main(){
	/*GraphAdjMat* g=adjMatrix();
	displayAdjMatrix(g);*/
	GraphAdjList* g=adjList();
	//displayAdjList(g);
	dfs_init(g);
	delGraphAdjList(g);
}
