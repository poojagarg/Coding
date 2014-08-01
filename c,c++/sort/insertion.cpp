#include<iostream>
#include<cstdio>
using namespace std;
void insertionSort(int *A, int size){
	for(int i=1; i<size; i++){//i: index which is not yet sorted
		int temp=A[i];
		int j;
		for(j=i-1; j>=0; j--){
			if(temp<A[j]){
				A[j+1]=A[j];
			}
			else
				break;
		}
			A[j+1]=temp;
	}
}
int main(){
	int A[10];
	FILE* fp=fopen("sort.txt","r");
	int i=0;
	while(i<10){
		int d;
		char c;
		fscanf(fp,"%d%c",&d,&c);
		A[i]=d;
		//cout<<A[i]<<'\t';
		i++;
	}
	insertionSort(A,10);
	i=0;
	while(i<10){
		cout<<A[i]<<'\t';
		i++;
		//fprintf(fp,"%d\t",A[i++]);
	}
	
}

