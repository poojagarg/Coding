#include<iostream>
#include<stdio.h>
#include<string>  
#include  <algorithm>
#include  <vector>
using namespace std;
int next_permutation_(string& s){
  int len=s.length();
   int j;
  for(j=len-1;j>0; j--){
    if(s[j]>s[j-1]){
    //  cout<<endl<<s<<":";
      break;
    }
  }
  if(j==0)
    return 0;
  int i;
  for(i=len-1; i>=j; i--){
    //printf("<%d:%c,%d:%c>",i,s[i],j-1,s[j-1]);
    if(s[i]>s[j-1]){
            break;
    }
  }
  swap(s[i],s[j-1]);
  sort(s.begin()+j,s.end());
  //int t; cin>>t;
  return 1;
  }
vector<string> sort_anagram(string& s){
  sort(s.begin(),s.end());
  vector<string> r;
  do{
     r.push_back(s);
  }while(next_permutation_(s));
  return r;
}
int main(){
  string s;
  cin>>s;
  vector<string> v=sort_anagram(s);
  cout<<v.size()<<endl;
  for(int i=0; i<v.size(); i++){
    cout<<v[i]<<'\t';
  }
}
