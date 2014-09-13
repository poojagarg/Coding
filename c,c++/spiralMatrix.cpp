#include <iostream>
using namespace std;
typedef enum direction{right, down, left, up}direction;
void f(int m[][3], int row, int col){
  int i=0, j=0;
  int min_i=1,max_i=row-1,min_j=0, max_j=col-1;
  
  int state=0;
  while(max_i>=min_i&&max_j>=min_j){
  switch(state){
    case 0:while(j<=max_j){
            cout<<m[i][j++]<<'\t';
           }
           state=1;
           j--;
           i=i+1;
           max_j--;
           break;
    case 1:while(i<=max_i){
            cout<<m[i++][j]<<'\t';
           }
           state=2;
           i--;
           j=j-1;
           max_i--;
           break;
    case 2:while(j>=min_j){
            cout<<m[i][j--]<<'\t';
           }
           state=3;
           j++;
           i=i-1;
           min_j++;
           break;
    case 3:while(i>=min_i){
            cout<<m[i--][j]<<'\t';
           }
           state=0;
           i++;
           j=j+1;
           max_i++;
           break;
  }
  }      
}
int main(){
  int row, col;
  cin>>row>>col;
  int m[row][3];
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      m[i][j]=i*col+j;
    }
  }
  f(m, row, col);
}
