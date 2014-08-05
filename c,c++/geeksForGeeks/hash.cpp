#include <iostream>
using namespace std;
class node{
  public:
    int d;
    node* next;
    node(int de, node* nexte){
      d=de;
      next=nexte;
    }
};
class hashTable{
  public:
    node** table;
    int size;
    hashTable(int s){
      size=s;
      table=(node**)malloc(sizeof(node*)*s);
      for(int i=0; i<s; i++)
        table[i]=NULL;
    }
    int hashKey(int n){
      return n%size;
    }
    void insert(int n){
      int k=hashKey(n);
      node* t=new node(n, table[k]);
      table[k]=t;
    }
    void show(){
      for(int i=0; i<size; i++){
        while(table[i]!=NULL){
          cout<<table[i]->d<<'\t';
          node* t=table[i];
          table[i]=table[i]->next;
          delete(t);
        }
        cout<<endl;
      }
    }
};
int main(){
  int size;
  cin>>size;
  hashTable h(size);
  int n;
  do{
    cin>>n;
    h.insert(n);
  }while(n!=-1);

  h.show();
}
