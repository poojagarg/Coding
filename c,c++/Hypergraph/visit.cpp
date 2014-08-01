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
typedef vector<int> vi;
typedef pair<vi,vi> vivi;//Edge
typedef vector<vivi> vvivi;//vector of Edges in the Hypergraph
typedef pair <vi, vvivi> H;//Hypergraph H- containing vector of vertices and edges
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
void debug(){
	int i;
	printf("debug");	
	scanf("%d",&i);
}
vvii buildHypergraph(){
	int n;
	FILE* fp=fopen("Hypergraph.txt","r");
	fscanf(fp,"%d",&n);
	H G;
	G.second.resize(n);
	G.first.resize(n);
	int i,a,w;	
	do{				
		char c=',';	
		while(c!='\n'){
			do{	
			fscanf(fp,"%d",&a);
			fscanf(fp,"%c",&c);
			}while(c!=' ');
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
