#include <iostream>
#include <algorithm>
using namespace std;
void print(int *a, int n){
  for(int i=0; i<n; i++){
    cout<<a[i]<<'\t';
    }
}
class mycomparison
{
    bool reverse;
  public:
      mycomparison(const bool& revparam=false)
            {reverse=revparam;}
        bool operator() (const int& lhs, const int&rhs) const
            {
                  if (reverse) return (lhs>rhs);
                      else return (lhs<rhs);
                        }
};
bool comp(int a, int b){
  return a>b;
}
int main(){
  int n;
  cin>>n;
  int a[10];
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  int k;
  cin>>k;
  make_heap(a,a+k,comp);
  print(a,n);
}
