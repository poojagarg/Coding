#include <iostream>
#include <cmath>
using namespace std;
int col[8];
bool check(int r){
  for(int i=0; i<r; i++){
    int diff=abs(col[i]-col[r]);
    if(diff==0||diff==r-i ){
      return 0;
    }
  }
  return 1;
}
void print(){
  for(int i=0; i<8; i++){
    cout<<i<<","<<col[i]<<'\t';
  }
  cout<<endl;
}
void PQ(int r){
  if(r==8){
    print();
    return;
  }
  for(int i=0; i<8; i++){
    col[r]=i;
    if(check(r)){
      PQ(r+1);
    }
  }
}
int main(){
  PQ(0);
}
