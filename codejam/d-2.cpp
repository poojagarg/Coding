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
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef long double ld;

const double eps = 1e-9;

inline int comp(const double &a, const double &b) {
	if (fabs(a - b) < eps)
		return 0;
	return a > b ? 1 : -1;
}
bool cmp(const ii &a, const ii &b){
  if(a.first==b.first)
    return a.second<b.second;
  else
    return a.first<b.first;
}
bool matrix(vii &p,ll tile, ll M){
  tile=1<<tile;
  if(p.sz==0){
    if(tile<=M)
    {
      p.pb(ii(M,M-tile));
      p.pb(ii(M-tile,M));
      sort(p.begin(),p.end(),cmp);
      return true;
    }
    return false;
  }
  else{
    ll min_;
    ll bestfit=0, bestInd;
    rep(i,p.sz){
      min_=min(p[i].first,p[i].second);
      if(min_>=tile){
        if(bestfit==0){
          bestfit=min_;
          bestInd=i;
        }
        else{
          if(bestfit>min_){
            bestfit=min_;
            bestInd=i;
          }
        }
      }
    }
      if(bestfit!=0){
        ll i=bestInd;
        p.erase(p.begin()+i);
        p.pb(ii(p[i].first-tile,p[i].second-tile));
        p.pb(ii(p[i].first-tile,p[i].second));
        p.pb(ii(p[i].first,p[i].second-tile));
        sort(p.begin(), p.end(),cmp);
        return true;
      }
    }
  return false;
}
int N;
int main() {
  cin>>N;
  rep2(nn,1,N+1){
    int n;
    ll m;
    cin>>n;
    cin>>m;
    ll a[n];
    rep(i,n){
      cin>>a[i];
    }
    sort(a,a+n);
    int count=1;
    int start=0, last=n-1;
    while(true){
    vii v;
   for(int i=last; i>=start; i--){
      if(!matrix(v,a[i],m)){
        break;
      }
      last--;
    }
   for(int i=start; i<last; i++){
      if(!matrix(v,a[i],m)){
        break;
   }
      start++;
  }
    if(start>last){
      cout<<"Case #"<<nn<<": "<<count<<endl;
      break;
    }
    else
      count++;
    }
}
}
