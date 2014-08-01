#include <iostream>
#include <cstring>
using namespace std;
int f(char* a, char* b, char* c){
  int n=strlen(a);
  int m=strlen(b);
  int r[n+1][m+1];
  r[0][0]=1;
  for(int i=1; i<=n; i++){
    r[i][0]=(r[i-1][0]&&c[i-1]==a[i-1]);
  }
  for(int i=1; i<=m; i++){
    r[0][i]=(r[0][i-1]&&c[i-1]==b[i-1]);
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      r[i][j]=((c[i+j-1]==b[j-1]&&r[i][j-1])||(c[i+j-1]==a[i-1]&&r[i-1][j]));
    }
  }
  return r[n][m];
}

int f_(char* a, char* b, char* c){
  int n=strlen(a);
  int m=strlen(b);
  int r[m+1];
  r[0]=1;
  for(int i=1; i<=m; i++){//0,i
    r[i]=(r[i-1]&&c[i-1]==b[i-1]);
  }
  for(int i=1; i<=n; i++){//i,j
    r[0]=r[0]&&c[i-1]==a[i-1];
    for(int j=1; j<=m; j++){
      r[j]=((c[i+j-1]==b[j-1]&&r[j-1])||(c[i+j-1]==a[i-1]&&r[j]));
    }
  }
  return r[m];}
int main(){
  char a[100],b[200],c[200];
  cin>>a>>b>>c;
  int n;
  cin>>n;
  while(n!=0){
    cout<<f_(a,b,c)<<endl;
    cin>>a>>b>>c;
    cin>>n;
  }
}
