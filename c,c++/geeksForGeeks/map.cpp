#include <iostream>
#include <map>
using namespace std;

int main(){
  map<int, int> m;
  int n;
  cin>>n;
  for(int i=0; i<n; i++){
    m[i]=2*i;
  }
  for(int i=0; i<n; i=i+2){
    cout<<m[i];
  }
}
