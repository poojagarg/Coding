#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>    
#include<queue>
#include<set>    
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef pair< int, pair<int, int> > iii;
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
int min(int L[][2], int j,int toggle, vii G){//L[toggle],L[j][toggle],G[j]
	int min=L[j][toggle];
	tr(G, it){
		int v=it->first; int cost=it->second;
		if(L[v][toggle]+cost<min)
			min=L[v][toggle]+cost;	
	}
	return min;
}
void show(int L[][2], int n, int toggle){
	printf("\n");
	for(int i=0; i<n; i++)
		printf("<%d,%d>",i,L[i][toggle]);
	printf("\n");	
}
void show(int l[], int n){
	for(int i=0; i<n; i++){
		printf("<%d,%d>",i,l[i]); 
	}
}
void BellmanFord(vvii G, int start){
	int L[G.size()][2];
	for(int j=0; j<2; j++){
		for(int i=0; i<G.size(); i++){
			L[i][j]=987654321;
			//printf("<%d>",L[i][j]);
		}
		//printf("\n");
	}
	int toggle=0;
	L[start][toggle]=0;
	for(int i=0;i<G[start].size(); i++){		
		L[G[start][i].first][toggle]=G[start][i].second;
		//printf("<%d,%d>",G[start][i].first,L[G[start][i].first][toggle]);
	}
	/*for(int i=0; i<G.size(); i++)
		printf("<%d,%d>",i,L[i][toggle]);*/
	//show(L,G.size(),toggle);
	for(int i=2;i<=G.size(); i++){
		for(int j=0; j<G.size(); j++){
			L[j][1-toggle]=min(L,j,toggle,G[j]);
		}
		toggle=1-toggle;
	}
	show(L[toggle], G.size());
	show(L[1-toggle], G.size());
	//show(L, G.size(),toggle);
}

void Qpush(priority_queue<iii,vector<iii>, greater<iii> > &Q, vvii &G, int start,set<int> &vertices){
	for(int i=0; i<G[start].size(); i++){
		int v=G[start][i].first;
		if(vertices.count(v)==1) continue;//already exist, check next one
		int u=start;
		int w=G[start][i].second;
		//ii p(v,u);
		//pair< int, pair<int, int> > r(w,p);		
		Q.push(iii(w,ii(u,v)));
	}
}

void print(set<int> &vertices){
	printf("Vertices:");
	tr(vertices,it){
		printf("<%d>",*it);
	}
	printf("\n");
}
void print(vii &edges){
	printf("edges");
	tr(edges,it){
		printf("<%d,%d>",it->first,it->second);
	}
	printf("\n");
}
int Find(vi &F, int u){	
	//printf("finding %d:",u);
	while(F[u]>=0){
		u=F[u];
		//printf("%d,",u);
		
	}
	//printf("done"); 
	//debug();
	return u;	
}
void Union(vi &vertices,int u, int v){
	int pu=Find(vertices, u);
	int pv=Find(vertices, v);
	if(vertices[pu]>=vertices[pv]){ //pv is more negative=> more nodes
		vertices[pv]=vertices[pu]+vertices[pv];
		vertices[pu]=pv;		
		}
	else{
		vertices[pu]=vertices[pu]+vertices[pv];
		vertices[pv]=pu;
	}
}
void show(vii e){
	printf("Prim result");
	tr(e,it){
		printf("<%d,%d>",it->first, it->second);
	}
	
}
void show(vi &vertices){
	tr(vertices,it){
		printf("<%d>",*it);
	}
}
void Prim(vvii G){
	
	vector<int> vertices(G.size(),-1); //maintain parent of each vertex, if already root then maintain size(no of nodes) of the tree
	
	priority_queue<iii,vector<iii>, greater<iii> > Q;//min_heap
	for(int i=0; i<G.size(); i++){
		for(int j=0; j<G[i].size(); j++){
			int u=i;
			int v=G[i][j].first;
			int w=G[i][j].second;
			if(u<v){
				Q.push(iii(w,ii(u,v)));//pushing all the edges
				printf("<%d,%d,%d>",w,u,v);
			}
			}
	}
	vii edges;
	while(edges.size()<G.size()-1){
		iii res=Q.top();
		Q.pop();
		if(Find(vertices,res.second.first)!=Find(vertices,res.second.second)){ //belong to different set
			Union(vertices,res.second.first,res.second.second);
			edges.push_back(ii(res.second.first,res.second.second));
			}
	}
	show(edges);
}
void Kruskal(vvii G, int start){
	priority_queue<iii,vector<iii>, greater<iii> > Q;//min_heap
	set<int> vertices;
	vii edges;
	vertices.insert(start); 
	Qpush(Q,G,start,vertices);
	int n=G.size();
	while(vertices.size()<n){
		iii res=Q.top();
		Q.pop();
		if(vertices.count(res.second.first)==1&&vertices.count(res.second.second)==0){
			vertices.insert(res.second.second);
			edges.push_back(ii(res.second.first,res.second.second));
			Qpush(Q,G,res.second.second,vertices);
			continue;
		}
		else if(vertices.count(res.second.first)==0&&vertices.count(res.second.second)==1){
			vertices.insert(res.second.first);
			edges.push_back(ii(res.second.first,res.second.second));
			Qpush(Q,G,res.second.first,vertices);
			continue;
		}		
	}
	print(vertices);
	print(edges);
}
void Dijkstra(vvii G, int start){
	int n=G.size();
	vi D(n,987654321);
	D[start]=0;
	priority_queue<ii,vector<ii>, greater<ii> > Q;
	Q.push(ii(0,start));//key, vertex
	while(!Q.empty()){
		ii top=Q.top();
		Q.pop();
		int v=top.second; int d=top.first;
		if(d<=D[v]){
			int s=G[v].size();
			for(int i=0; i<s; i++){
				int l=d+G[v][i].second; 
				if(l<D[G[v][i].first]){
					D[G[v][i].first]=l;
					Q.push(ii(l,G[v][i].first));
				}	
			}	
		}		
	}
	for(int i=0; i<n; i++) 
		printf("<%d,%d>",i,D[i]);
}
int main(){
	vvii G=buildGraph();
	//BellmanFord(G,0);
	Kruskal(G,0);
	Prim(G);
	//showGraph(G);
	//Dijkstra(G,0);
}
