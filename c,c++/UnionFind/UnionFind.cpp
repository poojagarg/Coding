#include<iostream>
using namespace std;
#define arraySize 10
int L[arraySize];
int find(int x){
	return (x==L[x])?x: L[x]=find(x);
}
int Union(int x, int y){
	L[x]=find(y);
}

int find(int x, int &count){
	count++;
	return (x==L[x])?x: L[x]=find(x, count);
}
int UnionSmaller(int x, int y){
	int a=0, b=0;
	find(x,a);
	find(y,b);
	a<b? L[x]=b: L[y]=a;
}

