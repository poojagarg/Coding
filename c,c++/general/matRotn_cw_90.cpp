#include<iostream>
#include<malloc.h>
using namespace std;
int** matRotn_cw_90(int A[][4], int m, int n){
	int **B;
	B=(int**) malloc (n*sizeof(int*));
	for(int i=0; i<n; i++){
		B[i]=(int*) malloc (m*sizeof(int));
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			B[j][m-i-1]=A[i][j];
		}
	}
	return B;
} 
int main(){
	int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int** b= matRotn_cw_90(a,3,4);
	for(int i=0; i<4; i++){
		for(int j=0; j<3; j++){
			cout<<b[i][j]<<'\t';
		}
		cout<<endl;
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<4; j++){
			cout<<a[i][j]<<'\t';
		}
		cout<<endl;
	}
	
}
