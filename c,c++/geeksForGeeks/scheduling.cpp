#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<pair<int, int> > vii;
int f(vii &v){
  if(v.size()<2)
    return v.size();
  sort(v.begin(),v.end());
  vector<int> vi;
  vi.push_back(v[0].second);
  int n=v.size();
  for(int j=1; j<n; j++){
    int t=vi.size();
    for(int i=0; i<t; i++){
      if(vi[i]<v[j].first){
        vi[i]=v[j].second;
        break;
      }
      if(i==t){
        vi.push_back(v[j].second);
      }
    }
  }
  return vi.size();
}
