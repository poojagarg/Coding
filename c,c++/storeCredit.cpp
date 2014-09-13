#include <iostream>
#include <set>
using namespace std;
int main(){
  int t;
  cin>>t;
  int c_=1;
  while(c_<=t){
    int c,p;
    cin>>c>>p;
    int a[p];
    for(int i=0; i<p; i++)
      cin>>a[i];
    set<int> s;
    for(int i=0;i<p; i++){
      if(s.find(c-a[i])!=s.end()){
        for(int j=0; j<i; j++){
          if(a[j]==c-a[i]){
            cout<<"Case #"<<c_<<": "<<j+1<<" "<<i+1;
            break;
          }
            
        }
      }
      else s.insert(a[i]);
    }
    c_++;
    cout<<endl;
  }
}
