#include<iostream>
#include<cstdio>
#define size 15
using namespace std;
void print(int *A, int n){
	for(int i=0; i<n; i++){
		cout<<A[i]<<'\t';
	}
}
void swap(int *A, int index, int minIndex){
	if(index==minIndex) return;
	int temp=A[index];
	A[index]=A[minIndex];
	A[minIndex]=temp;
}
void quickSelect(int* A, int i,int j, int k){
	
}
void quickSort(int* A, int i, int j){
	if(j-i<1)
		return;
	int pivot=A[i];
	int m=i;
	int n=i+1;
	while(n<=j){
		if(A[n]<pivot){
			swap(A,m+1,n);
			m++;
		}
		n++;
	}
	swap(A,i,m);
	//cout<<A[m]<<'f';
	quickSort(A,i, m-1);
	quickSort(A,m+1,j);
}
void quickSortNonUnique(int* A, int i, int j){
	if(j-i<1)
		return;
	int pivot=A[i];
	int m=i-1;
	int e=i;
	int n=i+1;
	while(n<=j){
		if(A[n]<pivot){
			m++; e++;
			swap(A,m,n);
			swap(A,e,n);
		}
		else if(A[n]==pivot){
			e++;
			swap(A,e,n);
		}
		n++;
	}
	if(m!=i-1){
		swap(A,i,m);
		quickSortNonUnique(A,i, m-1);
	}
	quickSortNonUnique(A,e+1,j);
}

int main(){
	int A[size];
	FILE* fp=fopen("sort.txt","r");
	int i=0;
	while(i<size){
		int d;
		char c;
		fscanf(fp,"%d%c",&d,&c);
		A[i]=d;
		i++;
	}
	quickSortNonUnique(A,0,size-1);
	print(A,size);
}
