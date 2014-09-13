
#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <list>

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz size()
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define rep2(i,n,m) for(int i=n;i<(int)(m);i++)
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define mem(a,b) memset(a,b,sizeof(a))

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;

const double eps = 1e-9;

inline int comp(const double &a, const double &b) {
	if (fabs(a - b) < eps)
		return 0;
	return a > b ? 1 : -1;
}
bool comp(const int &a, const int &b){
  return a<b;
}
int N;
int main() {
  cin>>N;
  map<string, int> m;
  m["left"]=0;
  m["right"]=1;
  m["up"]=2;
  m["down"]=3;
  rep2(nn,1,N+1){
    int n;
    cin>>n;
    string d;
    cin>>d;
    int dir=m[d];
    int a[n][n];
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        cin>>a[i][j];
      }
    }
    switch(dir){

      case 0:
              for(int i=0; i<n; i++){
                int j;
                int count=0;
                for( j=0; j<n; j++){
                if(a[i][j]==0){
                  count++;
                int k;
                  for( k=j+1; k<n; k++){
                  if(a[i][k]!=0)
                    break;
                }
                if(k==n)
                  break;
                int f=j;
                for(int l=k; l<n; l++){
                  a[i][f]=a[i][k];
                  f++;
                }
                
                }
                
              }
                for(int j=0; j<count; j++){
                  a[i][n-1-j]=0;
                }
              }
              for(int i=0; i<n; i++){
              for(int j=0; j<n-1; j++){
                if(a[i][j]==a[i][j+1]){
                  a[i][j]=2*a[i][j];
                  for(int k=j+1; k<n-1; k++){
                    a[i][k]=a[i][k+1];
                  }
                  a[i][n-1]=0;
                }
              }

             }
              break;


      case 1:
              for(int i=0; i<n; i++){
                int j;
                int count=0;
                for( j=n-1; j>=0; j--){
                if(a[i][j]==0){
                  count++;
                int k;
                  for( k=j-1; k>=0; k--){
                  if(a[i][k]!=0)
                    break;
                }
                if(k==-1)
                  break;
                int f=j;
                for(int l=k; l>=0; l--){
                  a[i][f]=a[i][k];
                  f--;
                }
                
                }
                
              }
                for(int j=0; j<count; j++){
                  a[i][j]=0;
                }
              }
              for(int i=0; i<n; i++){
              for(int j=n-1; j>0; j--){
                if(a[i][j]==a[i][j-1]){
                  a[i][j]=2*a[i][j];
                  for(int k=j-1; k>0; k--){
                    a[i][k]=a[i][k-1];
                  }
                  a[i][0]=0;
                }
              }

             }
              break;
    

    case 2:

              for(int i=0; i<n; i++) {//i represents column now
                int j;
                int count=0;
                for( j=0; j<n; j++){// j is for row
                if(a[j][i]==0){
                  count++;
                int k;
                  for( k=j+1; k<n; k++){
                  if(a[k][i]!=0)
                    break;
                }
                if(k==n)
                  break;
                int f=j;
                for(int l=k; l<n; l++){
                  a[f][i]=a[k][i];
                  f++;
                }
                
                }
                
              }
                for(int j=0; j<count; j++){
                  a[n-1-j][i]=0;
                }
              }
              for(int i=0; i<n; i++){
              for(int j=0; j<n-1; j++){
                if(a[j][i]==a[j+1][i]){
                  a[j][i]=2*a[j][i];
                  for(int k=j+1; k<n-1; k++){
                    a[k][i]=a[k+1][i];
                  }
                  a[n-1][i]=0;
                }
              }

             }
              break;






    case 3:


              for(int i=0; i<n; i++) {//i represents column now
                int j;
                int count=0;
                for( j=n-1; j>0; j--){// j is for row
                if(a[j][i]==0){
                  count++;
                int k;
                  for( k=j-1; k>=0; k--){
                  if(a[k][i]!=0)
                    break;
                }
                if(k==-1)
                  break;
                int f=j;
                for(int l=k; l>=0; l--){
                  a[f][i]=a[l][i];
                  f--;
                }
                }
                
              }
                for(int j=0; j<count; j++){
                  a[j][i]=0;
                }
              }
              for(int i=0; i<n; i++){
              for(int j=n-1; j>0; j--){
                if(a[j][i]==a[j-1][i]){
                  a[j][i]=2*a[j][i];
                  for(int k=j-1; k>0; k--){
                    a[k][i]=a[k-1][i];
                  }
                  a[0][i]=0;
                }
              }

             }
              break;
    }
    cout<<"Case #"<<nn<<":"<<endl;
    for(int i=0; i<n; i++){
      for(int j=0; j<n-1; j++){
        cout<<a[i][j]<<" ";
      }
        cout<<a[i][n-1];
        cout<<endl;
    }
  }
	return 0;
}
