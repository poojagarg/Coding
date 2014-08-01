#include<iostream>
#include<algorithm>
using namespace std;
bool comp(int a, int b){
	return a<b;
}
int main(){
	cout<<max(3,2,comp);
	cout<<max(1,2,comp);
}
