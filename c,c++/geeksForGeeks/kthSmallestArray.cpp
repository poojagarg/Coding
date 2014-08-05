#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef vector<int> vi;
int ks(int *a,int k, int n){
  priority_queue<int> pq;
  for(int i=0; i<k; i++){
    pq.push(a[i]);
  }
  for(int i=k; i<n; i++)
    if(pq.top()>a[i]){
      pq.pop();
      pq.push(a[i]);
    }
  return pq.top();
}
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  int k;
  cin>>k;
  cout<<ks(a,k,n);
}
