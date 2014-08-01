#include<iostream>
#include<cstdio>
#define size 60
using namespace std;
int main(){
	int A[size];
	FILE* fp=fopen("sort.txt","r");
	int i=0;
	while(i<size){
		int d;
		char c;
		fscanf(fp,"%d%c",&d,&c);
		A[i]=d;
		//cout<<A[i]<<'\t';
		i++;
	}
	for(int h=size/2; h>=1; h=h/2){
		for(int i=0; i<h; i++){
			for(int j=i+h; j<size; j=j+h){
				int temp=A[j];
				int k;
				for(k=j-h; k>=0; k=k-h){
					if(temp<A[k]){
						A[k+h]=A[k];
						}
					else
						break;
					}
				A[k+h]=temp;
			}
			}
			}
	i=0;
	while(i<size){
		cout<<A[i]<<'\t';
		i++;
		//fprintf(fp,"%d\t",A[i++]);
	}
	
}

