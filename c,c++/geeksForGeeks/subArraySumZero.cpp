#include <iostream>
using namespace std;
class hashEntry{
  public:
    int d;
    hashEntry *next;
    hashEntry(int de, hashEntry* nexte=NULL){
      d=de;
      next=nexte;
    }};
typedef hashEntry* HE;
typedef hashEntry** H;
class hashTable{
public:
  H h;
  int size;
  hashTable(int sizee){
    h=(H)malloc(size*sizeof(HE));
    for(int i=0; i<size; i++){
      h[i]=NULL;
    }
    size=sizee;
  }
  int hashKey(int i){
    return i%size;
  }
int insert(int n){
    int k=hashKey(n);
    //h[k]=new hashEntry(n,h[k]);
    HE he=h[k];
    while(he!=NULL){
      if(he->d==n)
        break;
      he=he->next;
    }
    if(he==NULL){
      h[k]=new hashEntry(n,h[k]);
      return 1;
    }
    else{
      //already exists
      return 0;
    }
  }
};
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  int size;
  cin>>size;
  hashTable ht(size); 
  int sum=0;
  for(int i=0; i<n; i++){
    sum+=a[i];
    if(ht.insert(sum)==0)
    {
      cout<<"found at"<<i<<endl;
    }
  }
}
