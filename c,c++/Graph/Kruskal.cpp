#include<set>
typedef pair< int, pair<int, int> > iii;
void Qpush(priority_queue<iii,vector<iii>, greater<iii> > &Q, vvii &G, int start,set<int> &vertices){
	for(int i=0; i<G[start].size(); i++){
		int v=G[start][i].first;
		if(vertices.count(v)==1) continue;//already exist, check next one
		int u=start;
		int w=G[start][i].second;		
		Q.push(ii(w,ii(v,u)));
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
	tr(vertices,it){
		printf("<%d,%d>",it->first,it->second);
	}
	printf("\n");
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
