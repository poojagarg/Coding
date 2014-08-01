#include<iostream>
void quickSort(int* a, int i, int j ){
	if(j<=i)
		return;
	int p=a[i];
	int l=i-1;
	int e=i;
	for(int c=i+1; c<=j; c++){
		if(A[c]<p){
			swap(a,l+1,c);
			l++;
			swap(e+1,c);
			e++;
			}
		if(A[c]==p){
			swap(c,e+1);
			e++;
		}
	}
	if(l>i-1)
		quickSort(a,i,l);
	if(e<j)
		quickSort(a,e+1,j);
}
