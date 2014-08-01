#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <ctype.h>
#include <stack>
#include <iostream>
#include <queue>
#include <set>
#include<utility>
using namespace std;
long tree[1001];
int maxVal;
<<<<<<< HEAD
typedef struct edge{int a; int b;}edge;
bool comp(edge e1, edge e2){
	if(e1.a==e2.a)
		return e1.b<e2.b;
	return e1.a<e2.a;
	}
long read(int idx){
    long sum = 0;
=======
 
int read(int idx){
    int sum = 0;
>>>>>>> 4ac8dd9cc81600cb3dbd34529630f26f83b85d0b
    while(idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
 
<<<<<<< HEAD
void update(int idx){
    while(idx <= maxVal){
        tree[idx] ++;
=======
void update(int idx, int val){
    while(idx <= maxVal){
        tree[idx] += val;
>>>>>>> 4ac8dd9cc81600cb3dbd34529630f26f83b85d0b
        idx += (idx & -idx);
    }
}
 
int main()
{
    int t;
<<<<<<< HEAD
=======
 
>>>>>>> 4ac8dd9cc81600cb3dbd34529630f26f83b85d0b
    scanf("%d", &t);
 
    while(t--){
    	int n,m,k;
        scanf("%d %d %d", &n,&m,&k);
<<<<<<< HEAD
        edge bridge[k];
        maxVal = 0;
        for(int i = 0 ; i < k ; i++){
            scanf("%d %d",&bridge[i].a,&bridge[i].b);
        }
        sort(bridge, bridge+k);
        long res = 0;
        memset(tree,0,k*sizeof(long));
        for(int i =k-1; i>=0 ; i--){
                res += read(bridge[i].b - 1);
	        update(bridge[i].b);
        }
        printf("Test case %d: %ld\n",t+1,res);
    }
    return 0;
=======
        maxVal = 0;
        vector< pair<int, int> > v(k);
        for(int i = 0 ; i < k ; i++){
	    pair<int, int> p;	
            scanf("%d %d",&p.first,&p.second);
            maxVal=maxVal>p.second?maxVal:p.second;
            v[i]=p;
        }
        sort(v.begin(), v.end());
        long res = 0;
        memset(tree, 0, sizeof(tree));
        for(int i =k-1; i>=0 ; i--){
        	int x=v[i].first;
                res += read(v[i].second - 1);
                vector <int> b;
                b.push_back(v[i].second);
                
                while(i>0&&v[i-1].first==x){
                	i--;
                	res += read(v[i].second - 1);
                	b.push_back(v[i].second);
                }
		int z=b.size();
		for(int j=0; j<z; j++)
	            update(v[i].second, 1);
        }
        printf("Test case %d: %ld\n",t+1,res);
    }
>>>>>>> 4ac8dd9cc81600cb3dbd34529630f26f83b85d0b
}
