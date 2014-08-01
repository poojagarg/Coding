#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
void print(int* a, int s, int b);
void quickSort(int *a, int i, int j){
	if(j<=i) return;
	int pivot=a[i];
	int e=i, s=i-1;
	int l=i+1;
	while(l<=j){
		if(a[l]<pivot){
			swap(a[s+1],a[l]);
			s++;
			swap(a[e+1],a[l]);
			e++;
		}
		if(a[l]==pivot&&(l!=e)){
			swap(a[e+1],a[l]);
			e++;
		}
		l++;
	}
	if(s>=i)
	cout<<"smaller";print(a,i,s);
	cout<<"equal";print(a,s+1,e);
	cout<<"greater"; print(a,e+1,j);
	if(s>i){
		quickSort(a,i,s);
	}
	if(e<j-1){
		quickSort(a, e+1,j);
	}
}
void print(int* a, int s, int b){
	for(int i=s; i<=b; i++){
		cout<<a[i]<<'\t';
	}
	cout<<endl;
}
void print(int* a, int n){
	for(int i=0; i<n; i++){
		cout<<a[i]<<'\t';
	}
	cout<<endl;
}
int main(){
	int a[100];
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	//print(a,n-1);
	quickSort(a,0,n-1);
	print(a,n-1);
}
