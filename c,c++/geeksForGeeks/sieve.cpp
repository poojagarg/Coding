#include <iostream>
#include <cmath>
using namespace std;
void f(int n){
  int *p;
  p=(int*)calloc(sizeof(int), n+1);
  p[1]=1;
  int t=(int)sqrt(n);
  for(int i=2;i<=t; i++ ){
    if(p[i]==0){
      for(int j=i*2; j<=n; j=j+i){
        p[j]=1;
      }
    }
  }
  cout<<"Prime"<<endl;
  for(int i=2; i<=n; i++){
    if(p[i]==0){
      cout<<i<<'\t';
    }
  }
 delete(p); 
}
int main(){
  int n;
  cin>>n;
  do{
    f(n);
    cin>>n;
  }while(n>0);
}
