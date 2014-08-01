#include  <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
vi f(int n){
  if(n<=0)
    return vi(1,0);
  vi v;
  v=f(n-1);
  int s=v.size();
  for(int i=0; i<s; i++){
    int j=v[i];
    j|=(1<<(n-1));
    v.push_back(j);
  }
  return v;
}
void print(vi &v){
  for(typeof(v.begin()) i=v.begin(); i!=v.end(); i++){
     cout<<*i<<'\t';
    }
}
int main(){
  int n; 
  cin>>n;
  vi v=f(n);
  print(v);
}
