#include <iostream>
#include <set>
using namespace std;
class entry{
  public:
  int x,y,v;
  entry(int xe,int ye, int ve){
    x=xe;
    y=ye;
    v=ve;
  }
};
class comp{
  public:
  bool operator()(const entry &a,const entry &b)const{
    if(a.x==b.x||a.y==b.y)
      return false;
    return a.v>b.v;
  }
};
void f(int row, int col, int m[][4], int k){
  set<entry,comp> s;
  
  s.insert(entry(row-1, col-1, m[row-1][col-1]));
  while(!s.empty()){
   typeof(s.begin()) it=s.begin();
   entry e1=*it;
   s.erase(it);
   k--;
   cout<<"<"<<e1.v<<">";
   if(k==0){
    cout<<e1.v;
    return;
   }
   cout<<"."<<e1.y<<".";
   if(e1.y-1>=0){
     cout<<"trying 1";
      pair<set<entry>::iterator,bool> ret;
       ret=s.insert(entry(e1.x, e1.y-1,m[e1.x][e1.y-1]));
        if(ret.second==true){
           cout<<ret.first->x<<","<<ret.first->y<<","<<ret.first->v<<".";
        }
   }
   cout<<"."<<e1.y<<".";
   if(e1.x-1>=0){
     cout<<"trying 2";
     pair<set<entry>::iterator,bool> ret;
     ret=s.insert(entry(e1.x-1, e1.y,m[e1.x-1][e1.y]));
     if(ret.second==false){
      cout<<e1.x-1<<","<<e1.y<<","<<m[e1.x-1][e1.y]<<".";
     }
   }
   for(set<entry>::iterator itr=s.begin(); itr!=s.end(); itr++)
     cout<<itr->v<<'\t';
   cout<<endl;
  }
}
int main(){
  int a[3][4]={{1,4,8,10},{2,7,9,15},{3,11,14,18}};
  f(3,4,a,5);
  
}
