#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stdio.h>
using namespace std;
#define all(c) (c).begin(),(c).end() 
#define sz(a) int((a).size()) 
#define pb push_back 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
int N=8; // number of vertices 
vvi W(N); // graph 
vi V; // V is a visited flag 
void dfs(int i) { 
       if(!V[i]) { 
		printf("%d\t",i);
            V[i] = true; 
		for(vector<int>::iterator it=W[i].begin();it!=W[i].end(); it++){dfs(*it);}
       } 
} 
  
bool check_graph_connected_dfs() { 
       int start_vertex = 0; 
       V = vi(N, false); 
       dfs(start_vertex); 
       return (find(all(V), 0) == V.end()); 
 } 
int main(){
	
	char tmp; int n;
	FILE* fp=fopen("dfs.txt","r");
	if(!fp) return 0;
	int i=0;
	while(!feof(fp)){
		fscanf(fp,"%d%c",&n,&tmp); 
		W[i].push_back(n);
		cout<<n<<'\t';
		if(tmp=='\n'){cout<<W[i].size()<<'\n';i++; //if(i>=N) break;
}
}//end of while
	//cout<<i;
	check_graph_connected_dfs();	
}
