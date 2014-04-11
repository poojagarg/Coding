typedef struct GraphAdjMat{
	int V; 
	int E;
	int **Adj;
}GraphAdjMat;
typedef struct GraphNode{
	int v; struct GraphNode* next;
}GraphNode;
typedef struct GraphAdjList{
	int V; 
	int E;
	GraphNode **Adj;
}GraphAdjList;
