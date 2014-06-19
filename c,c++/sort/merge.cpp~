#include<iostream>
#include<cstdio>
using namespace std;
void print(int *a, int size){
	for(int i=0; i<size; i++){
		cout<<*(a+i)<<'\t';
	}
	cout<<"print\n";
}
void merge(int *A, int size, int startIndex){
	if(size<2) return;
	int B[size];
	int p=0;
	int *a1=A+startIndex;
	int *a2=A+startIndex+size/2;
	int s1=size/2;
	int s2=size/2+size%2;
	//print(a1,s1);
	//print(a2,s2);
	int c1,c2;
	c1=c2=0;
	while(c1<s1&&c2<s2){
		if(*a1<=*a2){
			B[p]=*a1;
			c1++;
			a1++;
			p++;
			}
		else{
			B[p]=*a2;
			c2++;
			a2++;
			p++;
		}
	}
	while(c1<s1){
			B[p]=*a1;
			c1++;
			a1++;
			p++;				
	}
	while(c2<s2){
			B[p]=*a2;
			c2++;
			a2++;
			p++;				
	}
	for(int i=0; i<size; i++){
		A[startIndex+i]=B[i];
		cout<<B[i]<<'\t';
	}
	cout<<"Merged\n";
	}
void mergeSort(int *A, int size, int startIndex){
	if(size<2)
		return;
	mergeSort(A,size/2,startIndex);
	mergeSort(A,size/2+size%2,startIndex+size/2);		
	merge(A,size,startIndex);
	
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
		cout<<A[i]<<'\t';
		i++;
	}
	cout<<'\n';
	mergeSort(A,10,0);
	i=0;
	while(i<10){
		cout<<A[i]<<'\t';
		i++;
		//fprintf(fp,"%d\t",A[i++]);
	}	
	}
