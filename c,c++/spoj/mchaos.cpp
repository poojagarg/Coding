#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
char a[100000][11];
char rev[100000][11];
bool cmp1(int i, int j){
  if(strcmp(a[i],a[j])<0)
    return true;
  else
    return false;
}
bool cmp2(int i, int j){
  if(strcmp(rev[i],rev[j])<0)
    return true;
  else
    return false;
}
int tree[100000];
int maxVal;

int read(int i){
  int sum=0;
  while(i>0){
    sum+=tree[i];
    i-=(i&-i);
  }
  return sum;
}
void update(int i, int val){
  while(i<=maxVal){
    tree[i]+=val;
    i+=(i&-i);
  }
}
int main(){
  int n;
  cin>>n;
  for(int i=0; i<n; i++){
    scanf("%s",a[i]);
    strcpy(rev[i],a[i]);
   reverse(rev[i],rev[i]+strlen(rev[i]));
  }
  maxVal=n;
  int first[n], second[n];
  for(int i=0; i<n; i++){
    first[i]=second[i]=i;
  }
  sort(first,first+n,cmp1);
  sort(second,second+n, cmp2);
  int pos[n];
  for(int i=0; i<n; i++){
    pos[second[i]]=i;
  }
  for(int i=0; i<n; i++){
    update(i+1,1);  
  }
  int sum=0;
  for(int i=0; i<n; i++){
    sum+=read(pos[first[i]]);//reads including the current index
    update(pos[first[i]]+1,-1);//updates current index and its left parent
  }
  cout<<sum;
}
