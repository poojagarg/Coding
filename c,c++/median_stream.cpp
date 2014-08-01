#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef priority_queue<int> pqM;//max priority heap
typedef priority_queue<int, vector<int>, greater<int> > pqm;//min priority heap

int f(pqm& min_heap, pqM& max_heap, int &temp_med, int e){
  if(temp_med==-1){
    if(min_heap.empty()){
      temp_med=e;
      return e;
    }
    int n1=max_heap.top();
    int n2=min_heap.top();
    if(e<n1){
      temp_med=max_heap.top();
      max_heap.pop();
      max_heap.push(e);
         }
    else if(e>n2){
      temp_med=min_heap.top();
      min_heap.pop();
      min_heap.push(e);
    }
    else{
      temp_med=e;
    }
      return temp_med;
  }
  else{
    if(e>temp_med){
      min_heap.push(e);
      max_heap.push(temp_med);
    }
    else{
      max_heap.push(e);
      min_heap.push(temp_med);
    }
    temp_med=-1;
    return (min_heap.top()+max_heap.top())/2;
  }
}
int main(){
  int n;
  pqm min_heap;
  pqM max_heap;
  int temp_med=-1;
  do{
    cin>>n;
    cout<<"median till now:"<<f(min_heap, max_heap,temp_med,n)<<'\t';

  }while(n!=-1);
}
