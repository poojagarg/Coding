#include<iostream>
#include<stack>
using namespace std;
int main(){
  stack<int> s[2];
  int o=0;
  do{
    switch(o){
      case 0:int n; cin>>n; s[0].push(n); break;
      case 1:if(!s[1].empty()){
               cout<<s[1].top(); 
               s[1].pop();
             }
             else{
              while(!s[0].empty()){
                s[1].push(s[0].top());
                s[0].pop();
              }
              if(s[1].empty())
                break;
              cout<<s[1].top();
              s[1].pop();
             }
             break;
      case 2:return 0;
    }
    cin>>o;
  }while(true);
}

