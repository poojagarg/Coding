#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
void bubbleSort(int *a, int n){
	for(int i=n-1; i>=0; i--){
		for(int j=0; j<i; j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
}


void print(int* a, int n){
	for(int i=0; i<n; i++){
		cout<<a[i]<<'\t';
	}
}
int main(){
	int a[100];
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	bubbleSort(a,n);
	print(a,n);
}
