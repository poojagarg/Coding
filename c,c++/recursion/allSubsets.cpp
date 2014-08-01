#include <iostream>
using namespace std;
void subset(int n){
  int l=1<<n;
  for(int i=0; i<l; i++){
    int c=0;
    int t=i;
    while(i>0){
      if(i%2){
        cout<<c<<'\t';}
      c++;
      i=i/2;
      }
    cout<<endl;
    i=t;
  }
}
int main(){
  int n;
  cin>>n;
  subset(n);
}
