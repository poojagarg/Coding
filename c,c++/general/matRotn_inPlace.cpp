#include<iostream>
#include<malloc.h>
#include<stdio.h>
using namespace std;
void print(int **a, int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout<<a[i][j]<<'\t';
    }
    cout<<endl;
  }
}
void rot_inPlace(int **a, int n){
  for(int i=0; i<n/2; i++){
    for(int j=i;j<(n-1-i); j++ ){
      int temp[3];
      temp[0]=a[i][j];
      temp[1]=a[j][n-i-1];
      temp[2]=a[n-i-1][n-j-1];
      a[i][j]=a[n-j-1][i];
      a[j][n-i-1]=temp[0];
      a[n-i-1][n-j-1]=temp[1];
      a[n-j-1][i]=temp[2];
    }
  }
}
int main(){
 int n;
 cin>>n;
 int **a;
 a=new int*[n];
 for(int i=0; i<n; i++){
  a[i]=new int[n];
 }
 int count=0;
 for(int i=0; i<n; i++){
  for(int j=0; j<n; j++){
    a[i][j]=count++;
  }
 }
 rot_inPlace(a,n);
 print(a,n);
}
