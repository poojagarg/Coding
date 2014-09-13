#include <iostream>
#include <algorithm>
using namespace std;
int f(int *a, int n, int &start, int &finish){//returns sum,
  int maxSum=a[0];
  start=finish=0;
  int sum=a[0];
  int local_start=0;
  for(int i=1; i<n; i++){
    sum=a[i]+max(sum,0);
    if(sum==a[i])
      local_start=i;
    if(sum>maxSum){
      finish=i;
      start=local_start;
      maxSum=sum;
    }
  }

  return maxSum;
}

int main(){
  int n;
  do{
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  int start, finish;
  cout<<f(a,n,start, finish)<<'\t'<<start<<'\t'<<finish<<endl;
  }while(n!=1);
}
