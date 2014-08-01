#include<iostream>
#include<queue>
#include<utility>
using namespace std;
class node{
	public:
		node *l, *r;
		char c;
		node(node* le, node* re, char ce){
			l=le; r=re; c=ce;
	}
};
class heapNode{
	public:
		node* n;
		int key;
		heapNode(node* d, int k){
			n=d; key=k;
		}
};
typedef pair<int, char> ic;
bool comp(heapNode* h1, heapNode* h2){
	return h1->key<=h2->key;
}
node* f(ic a[], int n){
	priority_queue(heapNode*, vector<heapNode*>, comp) p;
	for(int i=0; i<n; i++){
		p.push(new heapNode(new node(NULL,NULL, a[i].second),a[i].first));
	}
	while(p.size()>1){
		heapNode* h1=p.top();
		p.pop();
		heapNode* h2=p.top();
		p.pop();
		p.push(new heapNode(new node(h1->n, h2->n, '0'),h1->key+h2->key));
		}
	heapNode* n=p.top();
	p.pop();
	return n->n;
}
