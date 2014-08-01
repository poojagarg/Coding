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
typedef struct edge{int a; int b;}edge;
bool comp(edge e1, edge e2){
	if(e1.a==e2.a)
		return e1.b<e2.b;
	return e1.a<e2.a;
	}
long read(int idx){
    long sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
 
void update(int idx){
    while(idx <= maxVal){
        tree[idx] ++;
        idx += (idx & -idx);
    }
}
 
int main()
{
    int t;
    scanf("%d", &t);
 
    while(t--){
    	int n,m,k;
        scanf("%d %d %d", &n,&m,&k);
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
}
