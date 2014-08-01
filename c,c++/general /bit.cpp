#include<iostream>
#include<stdio.h>
#include"auxilary.h"
using namespace std;
#define nob 8
#define arraySize 2*nob-1
// number of elements in the array: 2(8)-1=15
int L[arraySize]={0};
//parent of index i: (i-1)/2
// set L[k]=x
void set(int k, int x){
	//cout<<k<<":"<<x<<".";
	int i;
	//cin>>i;
	if(k<0) return;
	if(k>=arraySize) return;
	if(k==0){
		L[k]=x; return;
	}
	int temp=L[k];
	L[k]=x;
	//its parent: parent-current value+x
	k=(k-1)/2;
	if(k<0) return;
	set(k,L[k]-temp+x);
}
int hasLeftRec(int k){
	if(k==1|k==0) return 0;//power of 2
	if(k%2==0) return hasLeftRec(k/2);
	else return 1;
}
int hasLeftItr(int k){
	if(k==1|k==0) return 0;//power of 2
	while(k){
		if(k%2==1) return 1;
		k=k/2;
		if(k==1|k==0) return 0;//power of 2
	}
}
int sum(int k){
	//cout<<"k:"<<k<<'\t';
	if(k<0||k>=arraySize) return 0;
	if(k==0){
		return L[k];
	}
	else if(k%2==0){
		return sum((k-1)/2);
	}
		//left child if index i is odd
	else{
		return L[k]+ (hasLeftItr(k+1)?sum(k-1):0);//if k-1==0 =>no more left neighbour
	}
}
int sum(int i,int j){
	return sum(j)-sum(i-1);	
}
int main(){
	FILE *fp=fopen("sort.txt","r");
	int k=nob-1;
	while(k<arraySize){
		int d;
		char c;
		fscanf(fp,"%d%c",&d,&c);
		set(k,d);
		k++;
	}
	print(L,arraySize);
	for(int i=k-1; i>nob-2; i--){
		cout<<i<<":"<<sum(i)<<'\t';
	}
}
