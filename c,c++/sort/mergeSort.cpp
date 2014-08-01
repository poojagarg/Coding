#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
//sort array a in the range of i to j
void merge(int *a, int s1, int e1, int s2, int e2);
void mergeSort(int  *a, int i, int j){
	if(i>=j) return;
	int mid=(j+i)/2;
	mergeSort(a,i,mid);
	mergeSort(a,mid+1,j);
	merge(a,i,mid, mid+1,j);
}
void merge(int *a, int s1, int e1, int s2, int e2){
	int c=e1-s1+e2-s2+2;
	int b[c];
	int c1=e1-s1+1;
	int c2=e2-s2+1;
	int j=0;
	int i1=0, i2=0;
	while(i1<c1&&i2<c2){
		if(a[s1+i1]>a[s2+i2]){
			b[j++]=a[s2+i2];
			i2++;
		}
		else{
			b[j++]=a[s1+i1];
			i1++;
		}
	}
	while(i1<c1){
		b[j++]=a[s1+i1];
		i1++;
	}
	while(i2<c2){
		b[j++]=a[s2+i2];
		i2++;
	}
	for(j=0; j<c; j++){
		a[s1+j]=b[j];
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
	mergeSort(a,0,n-1);
	print(a,n);
}
