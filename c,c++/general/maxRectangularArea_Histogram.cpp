#include<iostream>
#include<queue>
#include <stack>
#include<string>
#include<cstring>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include <utility>
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define For(i,n) for(int i=0; i<n; i++)
#define For1(i,s,n)   for(int i=s; i<n; i++)
#define For2(i,s,n,k)   for(int i=s; i<n; i=i+k)
int maxArea(int *A, int n){
  stack<ii> s;
  int max=-1;
  for(int i=0; i<=n; i++){
    while(!s.empty()&&(i==n||s.top().first>A[i])){
      int h=s.top().first;
      s.pop();
      int l=-1;
      if(!s.empty()){
        l=s.top().second;
      }
      int area=h*(i-l-1);
      max=max>area?max:area;
    }
    if(i<n){
      if(s.empty()||s.top().first!=A[i]) 
        s.push(ii(A[i],i));
      }
  }
  return max;
}
void print(int *a, int n){
  for(int i=0; i<n; i++){
    cout<<a[i]<<'\t';
  }
  cout<<endl;
}
int main(){
  int n;
   scanf("%d",&n);
   int A[n];
   For(i,n){
     scanf("%d",&A[i]);
      }
   cout<<maxArea(A,n);
}

